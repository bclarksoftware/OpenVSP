CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CFD_MESH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Path to cfd_mesh headers")

INCLUDE_DIRECTORIES( 
    ${NANOFLANN_INCLUDE_DIR}
    ${UTIL_INCLUDE_DIR}
    ${CPPTEST_INCLUDE_DIR} 
    ${LIBXML2_INCLUDE_DIR}
    ${GEOM_CORE_INCLUDE_DIR}
    ${XMLVSP_INCLUDE_DIR}
    ${TRIANGLE_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${CodeEli_INCLUDE_DIRS}
    ${TRITRI_INCLUDE_DIR}
    ${GEOM_API_INCLUDE_DIR}
    ${STEPCODE_INCLUDE_DIR}
   )

ADD_LIBRARY(cfd_mesh
BezierCurve.cpp
CfdMeshMgr.cpp
FeaMeshMgr.cpp
FeaPart.cpp
ICurve.cpp
IntersectPatch.cpp
ISegChain.cpp
Mesh.cpp
SCurve.cpp
Surf.cpp
SurfCore.cpp
SurfPatch.cpp
Tri.cpp
BezierCurve.h
CfdMeshMgr.h
FeaMeshMgr.h
FeaPart.h
ICurve.h
IntersectPatch.h
ISegChain.h
MapSource.h
Mesh.h
SCurve.h
Surf.h
SurfCore.h
SurfPatch.h
Tri.h
)

ADD_DEPENDENCIES( cfd_mesh
util
)
