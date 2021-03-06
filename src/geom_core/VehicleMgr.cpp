//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// VehicleMgr.cpp: implementation of the Vehicle Class and Vehicle Mgr Singleton.
//
//////////////////////////////////////////////////////////////////////

#include "Vehicle.h"
#include "VehicleMgr.h"

#ifdef WIN32
#include <windows.h>
#endif

//==== Constructor ====//
VehicleMgrSingleton::VehicleMgrSingleton()
{
    m_Vehicle = new Vehicle();
    m_Vehicle->Init();
}

Vehicle* VehicleMgrSingleton::GetVehicle()
{
    return m_Vehicle;
}



