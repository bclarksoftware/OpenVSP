#ifndef _VSP_GRAPHIC_CAMERA_BASE_H
#define _VSP_GRAPHIC_CAMERA_BASE_H

#include "glm/glm.hpp"
#include "Common.h"

#define PERSPECTIVE_ZOOM_INIT 60.0f
#define ORTHOGRAPHIC_ZOOM_INIT 0.018f

namespace VSPGraphic
{
/*!
* Camera Base Class.
*/
class Camera
{
public:
    /*!
    * Constructor.
    */
    Camera();
    /*!
    * Destructor.
    */
    virtual ~Camera();

public:
    /*!
    * Return current ProjectionMatrix.
    */
    virtual glm::mat4 getProjectionMatrix();
    /*!
    * Return current ModelViewMatrix.
    */
    virtual glm::mat4 getModelViewMatrix();
    /*!
    * Resize viewport.
    */
    virtual void resize( int x, int y, int width, int height );
    /*!
    * Set Projection type. Possible type are VSP_CAM_ORTHO and VSP_CAM_PERSPECTIVE.
    * Default: VSP_CAM_ORTHO
    */
    virtual void setProjection( Common::VSPenum type );
    /*!
    * Set Zoom Value.
    * value is a float that describe how close an item is appear in scene.
    * Example:
    * By default, when value equals to 1.0, the screen is zoomed to one unit space.
    */
    virtual void setZoomValue( float value );
    /*!
    * Get Zoom Value.
    */
    virtual float getZoomValue();
    /*!
    * Change view type.
    * Acceptable values are VSP_CAM_TOP, VSP_CAM_FRONT, VSP_CAM_LEFT, VSP_CAM_LEFT_ISO,
    * VSP_CAM_BOTTOM, VSP_CAM_REAR, VSP_CAM_RIGHT, VSP_CAM_RIGHT_ISO, VSP_CAM_CENTER.
    */
    virtual void changeView( Common::VSPenum type );
    /*!
    * Reset camera to default location.
    */
    virtual void resetView();

public:
    /*
    * Save current camera system.
    *
    * index - index of the save.  Index is zero based.
    * If index is already used, its content will be
    * overwrited with new camera system.
    */
    virtual void save( int index ) = 0;

    /*
    * Load saved camera system.
    *
    * index - index to load.  If index is never used,
    * nothing will happen.
    */
    virtual void load( int index ) = 0;

public:
    /*!
    * Rotate the scene.
    *
    * px, py - previous xy mouse location.
    * cx, cy - current xy mouse location.
    */
    virtual void rotate( int px, int py, int cx, int cy ) = 0;

    /*!
    * Panning the scene.
    *
    * px, py - previous xy mouse location.
    * cx, cy - current xy mouse location.
    */
    virtual void pan( int px, int py, int cx, int cy ) = 0;

    /*!
    * Panning the scene.
    *
    * x, y - how much distance to pan.
    */
    virtual void pan( float x, float y ) = 0;

    /*!
    * Zoom in or out.
    *
    * px, py - previous xy mouse location.
    * cx, cy - current xy mouse location.
    */
    virtual void zoom( int px, int py, int cx, int cy ) = 0;

    /*!
    * Zoom in or out.
    *
    * zoomvalue - amount to zoom in or out.  Positive zooms out,
    * negative zooms in.
    */
    virtual void zoom( float zoomvalue ) = 0;

    /*!
    * Move Geometry to center.
    */
    virtual void center() = 0;

    /*!
    * Set Center of Rotation.  XYZ are in world space.
    */
    virtual void setCOR( float x, float y, float z ) = 0;

protected:
    /*
    * Change View.
    */
    virtual void _top();
    virtual void _front();
    virtual void _left();
    virtual void _left_Iso();
    virtual void _bottom();
    virtual void _rear();
    virtual void _right();
    virtual void _right_Iso();

protected:
    virtual void _calculateProjection();

protected:
    // Transformation matrices.
    glm::mat4 _viewMatrix;
    glm::mat4 _modelviewMatrix;
    glm::mat4 _projectionMatrix;

    // Camera
    glm::vec3 _eye;
    glm::vec3 _focus;
    glm::vec3 _camUp;

    // Viewport x, y, width and height.
    int _vx;
    int _vy;
    int _vWidth;
    int _vHeight;

    // Zoom Value
    float _oZoom;
    float _pZoom;

    // Borders
    float _leftB;
    float _rightB;
    float _upB;
    float _downB;

    // Type of Projection.
    Common::VSPenum _projectionType;
};
}
#endif