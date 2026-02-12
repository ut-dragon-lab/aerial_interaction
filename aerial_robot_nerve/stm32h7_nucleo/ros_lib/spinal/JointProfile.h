#ifndef _ROS_spinal_JointProfile_h
#define _ROS_spinal_JointProfile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spinal
{

  class JointProfile : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _servo_id_type;
      _servo_id_type servo_id;
      typedef int8_t _angle_sgn_type;
      _angle_sgn_type angle_sgn;
      typedef float _angle_scale_type;
      _angle_scale_type angle_scale;
      typedef int16_t _zero_point_offset_type;
      _zero_point_offset_type zero_point_offset;
      enum { JOINT =  0 };
      enum { GIMBAL =  1 };

    JointProfile():
      type(0),
      servo_id(0),
      angle_sgn(0),
      angle_scale(0),
      zero_point_offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->servo_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_id);
      union {
        int8_t real;
        uint8_t base;
      } u_angle_sgn;
      u_angle_sgn.real = this->angle_sgn;
      *(outbuffer + offset + 0) = (u_angle_sgn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angle_sgn);
      union {
        float real;
        uint32_t base;
      } u_angle_scale;
      u_angle_scale.real = this->angle_scale;
      *(outbuffer + offset + 0) = (u_angle_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_scale.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_scale);
      union {
        int16_t real;
        uint16_t base;
      } u_zero_point_offset;
      u_zero_point_offset.real = this->zero_point_offset;
      *(outbuffer + offset + 0) = (u_zero_point_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zero_point_offset.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->zero_point_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->servo_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->servo_id);
      union {
        int8_t real;
        uint8_t base;
      } u_angle_sgn;
      u_angle_sgn.base = 0;
      u_angle_sgn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angle_sgn = u_angle_sgn.real;
      offset += sizeof(this->angle_sgn);
      union {
        float real;
        uint32_t base;
      } u_angle_scale;
      u_angle_scale.base = 0;
      u_angle_scale.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_scale.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_scale.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_scale.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_scale = u_angle_scale.real;
      offset += sizeof(this->angle_scale);
      union {
        int16_t real;
        uint16_t base;
      } u_zero_point_offset;
      u_zero_point_offset.base = 0;
      u_zero_point_offset.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zero_point_offset.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zero_point_offset = u_zero_point_offset.real;
      offset += sizeof(this->zero_point_offset);
     return offset;
    }

    virtual const char * getType() override { return "spinal/JointProfile"; };
    virtual const char * getMD5() override { return "f9dfda7d868ab0ffbbc985ef3ceb92c6"; };

  };

}
#endif
