#ifndef _ROS_axis_msgs_Axis_h
#define _ROS_axis_msgs_Axis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace axis_msgs
{

  class Axis : public ros::Msg
  {
    public:
      typedef float _pan_type;
      _pan_type pan;
      typedef float _tilt_type;
      _tilt_type tilt;
      typedef float _zoom_type;
      _zoom_type zoom;
      typedef float _pan_speed_type;
      _pan_speed_type pan_speed;
      typedef float _tilt_speed_type;
      _tilt_speed_type tilt_speed;
      typedef float _zoom_speed_type;
      _zoom_speed_type zoom_speed;
      typedef float _focus_type;
      _focus_type focus;
      typedef float _brightness_type;
      _brightness_type brightness;
      typedef float _iris_type;
      _iris_type iris;
      typedef bool _autofocus_type;
      _autofocus_type autofocus;
      typedef bool _autoiris_type;
      _autoiris_type autoiris;

    Axis():
      pan(0),
      tilt(0),
      zoom(0),
      pan_speed(0),
      tilt_speed(0),
      zoom_speed(0),
      focus(0),
      brightness(0),
      iris(0),
      autofocus(0),
      autoiris(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.real = this->pan;
      *(outbuffer + offset + 0) = (u_pan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pan);
      union {
        float real;
        uint32_t base;
      } u_tilt;
      u_tilt.real = this->tilt;
      *(outbuffer + offset + 0) = (u_tilt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tilt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tilt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tilt);
      union {
        float real;
        uint32_t base;
      } u_zoom;
      u_zoom.real = this->zoom;
      *(outbuffer + offset + 0) = (u_zoom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zoom.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zoom.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zoom.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zoom);
      union {
        float real;
        uint32_t base;
      } u_pan_speed;
      u_pan_speed.real = this->pan_speed;
      *(outbuffer + offset + 0) = (u_pan_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pan_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pan_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pan_speed);
      union {
        float real;
        uint32_t base;
      } u_tilt_speed;
      u_tilt_speed.real = this->tilt_speed;
      *(outbuffer + offset + 0) = (u_tilt_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tilt_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tilt_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tilt_speed);
      union {
        float real;
        uint32_t base;
      } u_zoom_speed;
      u_zoom_speed.real = this->zoom_speed;
      *(outbuffer + offset + 0) = (u_zoom_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zoom_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zoom_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zoom_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zoom_speed);
      union {
        float real;
        uint32_t base;
      } u_focus;
      u_focus.real = this->focus;
      *(outbuffer + offset + 0) = (u_focus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_focus.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_focus.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_focus.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->focus);
      union {
        float real;
        uint32_t base;
      } u_brightness;
      u_brightness.real = this->brightness;
      *(outbuffer + offset + 0) = (u_brightness.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brightness.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brightness.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brightness.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brightness);
      union {
        float real;
        uint32_t base;
      } u_iris;
      u_iris.real = this->iris;
      *(outbuffer + offset + 0) = (u_iris.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iris.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iris.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iris.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iris);
      union {
        bool real;
        uint8_t base;
      } u_autofocus;
      u_autofocus.real = this->autofocus;
      *(outbuffer + offset + 0) = (u_autofocus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autofocus);
      union {
        bool real;
        uint8_t base;
      } u_autoiris;
      u_autoiris.real = this->autoiris;
      *(outbuffer + offset + 0) = (u_autoiris.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autoiris);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.base = 0;
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pan = u_pan.real;
      offset += sizeof(this->pan);
      union {
        float real;
        uint32_t base;
      } u_tilt;
      u_tilt.base = 0;
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tilt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tilt = u_tilt.real;
      offset += sizeof(this->tilt);
      union {
        float real;
        uint32_t base;
      } u_zoom;
      u_zoom.base = 0;
      u_zoom.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zoom.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zoom.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zoom.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zoom = u_zoom.real;
      offset += sizeof(this->zoom);
      union {
        float real;
        uint32_t base;
      } u_pan_speed;
      u_pan_speed.base = 0;
      u_pan_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pan_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pan_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pan_speed = u_pan_speed.real;
      offset += sizeof(this->pan_speed);
      union {
        float real;
        uint32_t base;
      } u_tilt_speed;
      u_tilt_speed.base = 0;
      u_tilt_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tilt_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tilt_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tilt_speed = u_tilt_speed.real;
      offset += sizeof(this->tilt_speed);
      union {
        float real;
        uint32_t base;
      } u_zoom_speed;
      u_zoom_speed.base = 0;
      u_zoom_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zoom_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zoom_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zoom_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zoom_speed = u_zoom_speed.real;
      offset += sizeof(this->zoom_speed);
      union {
        float real;
        uint32_t base;
      } u_focus;
      u_focus.base = 0;
      u_focus.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_focus.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_focus.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_focus.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->focus = u_focus.real;
      offset += sizeof(this->focus);
      union {
        float real;
        uint32_t base;
      } u_brightness;
      u_brightness.base = 0;
      u_brightness.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brightness.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brightness.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brightness.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brightness = u_brightness.real;
      offset += sizeof(this->brightness);
      union {
        float real;
        uint32_t base;
      } u_iris;
      u_iris.base = 0;
      u_iris.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iris.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iris.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iris.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iris = u_iris.real;
      offset += sizeof(this->iris);
      union {
        bool real;
        uint8_t base;
      } u_autofocus;
      u_autofocus.base = 0;
      u_autofocus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autofocus = u_autofocus.real;
      offset += sizeof(this->autofocus);
      union {
        bool real;
        uint8_t base;
      } u_autoiris;
      u_autoiris.base = 0;
      u_autoiris.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autoiris = u_autoiris.real;
      offset += sizeof(this->autoiris);
     return offset;
    }

    virtual const char * getType() override { return "axis_msgs/Axis"; };
    virtual const char * getMD5() override { return "f440b7dca90ab3091a81b5532bf10b30"; };

  };

}
#endif
