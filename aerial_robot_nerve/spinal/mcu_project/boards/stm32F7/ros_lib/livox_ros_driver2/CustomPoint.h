#ifndef _ROS_livox_ros_driver2_CustomPoint_h
#define _ROS_livox_ros_driver2_CustomPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace livox_ros_driver2
{

  class CustomPoint : public ros::Msg
  {
    public:
      typedef uint32_t _offset_time_type;
      _offset_time_type offset_time;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef uint8_t _reflectivity_type;
      _reflectivity_type reflectivity;
      typedef uint8_t _tag_type;
      _tag_type tag;
      typedef uint8_t _line_type;
      _line_type line;

    CustomPoint():
      offset_time(0),
      x(0),
      y(0),
      z(0),
      reflectivity(0),
      tag(0),
      line(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->offset_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_time);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      *(outbuffer + offset + 0) = (this->reflectivity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reflectivity);
      *(outbuffer + offset + 0) = (this->tag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tag);
      *(outbuffer + offset + 0) = (this->line >> (8 * 0)) & 0xFF;
      offset += sizeof(this->line);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->offset_time =  ((uint32_t) (*(inbuffer + offset)));
      this->offset_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset_time);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      this->reflectivity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reflectivity);
      this->tag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->tag);
      this->line =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->line);
     return offset;
    }

    virtual const char * getType() override { return "livox_ros_driver2/CustomPoint"; };
    virtual const char * getMD5() override { return "109a3cc548bb1f96626be89a5008bd6d"; };

  };

}
#endif
