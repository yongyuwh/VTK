/*=========================================================================

  Program:   Visualization Library
  Module:    Points.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlPoints - abstract interface to 3D points
// .SECTION Description
// vlPoints provides an abstract interface to 3D points. The data model
// for vlPoints is an array of x-y-z triplets accessible by point id.
// The subclasses of vlPoints are concrete data types (float, int, etc.) 
// that implement the interface of vlPoints. 

#ifndef __vlPoints_h
#define __vlPoints_h

#include "RefCount.hh"

class vlFloatPoints;
class vlIdList;

class vlPoints : public vlRefCount 
{
public:
  vlPoints();
  virtual ~vlPoints() {};
  char *GetClassName() {return "vlPoints";};
  void PrintSelf(ostream& os, vlIndent indent);

  // Description:
  // Create a copy of this object.
  virtual vlPoints *MakeObject(int sze, int ext=1000) = 0;

  // Description:
  // Return number of points in list.
  virtual int GetNumberOfPoints() = 0;

  // Description:
  // Return a float point x[3] for a particular point id.
  virtual float *GetPoint(int i) = 0;

  // Description:
  // Insert point into object. No range checking performed (fast!).
  virtual void SetPoint(int i,float x[3]) = 0;

  // Description:
  // Insert point into object. Range checking performed and memory
  // allocated as necessary.
  virtual void InsertPoint(int i, float x[3]) = 0;

  // Description:
  // Insert point into next available slot. Returns point id of slot.
  virtual int InsertNextPoint(float x[3]) = 0;

  // Description:
  // Reclaim any extra memory.
  virtual void Squeeze() = 0; // reclaim memory

  void GetPoints(vlIdList& ptId, vlFloatPoints& fp);
  virtual void ComputeBounds();
  float *GetBounds();

protected:
  float Bounds[6];
  vlTimeStamp ComputeTime; // Time at which bounds computed

};

#endif
