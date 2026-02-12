#ifndef _ROS_axis_msgs_Ptz_h
#define _ROS_axis_msgs_Ptz_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace axis_msgs
{

  class Ptz : public ros::Msg
  {
    public:
      typedef float _pan_type;
      _pan_type pan;
      typedef float _tilt_type;
      _tilt_type tilt;
      typedef float _zoom_type;
      _zoom_type zoom;

    Ptz():
      pan(0),
      tilt(0),
      zoom(0)
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
     return offset;
    }

    virtual const char * getType() override { return "axis_msgs/Ptz"; };
    virtual const char * getMD5() override { return "eef4827ef5b8ba89a8c9fa0810a30294"; };

  };

}
#endif
