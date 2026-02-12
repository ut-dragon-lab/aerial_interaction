#ifndef _ROS_spinal_PwmTest_h
#define _ROS_spinal_PwmTest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spinal
{

  class PwmTest : public ros::Msg
  {
    public:
      uint32_t motor_index_length;
      typedef uint8_t _motor_index_type;
      _motor_index_type st_motor_index;
      _motor_index_type * motor_index;
      uint32_t pwms_length;
      typedef float _pwms_type;
      _pwms_type st_pwms;
      _pwms_type * pwms;

    PwmTest():
      motor_index_length(0), st_motor_index(), motor_index(nullptr),
      pwms_length(0), st_pwms(), pwms(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_index_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_index_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_index_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_index_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_index_length);
      for( uint32_t i = 0; i < motor_index_length; i++){
      *(outbuffer + offset + 0) = (this->motor_index[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_index[i]);
      }
      *(outbuffer + offset + 0) = (this->pwms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pwms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pwms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pwms_length);
      for( uint32_t i = 0; i < pwms_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pwmsi;
      u_pwmsi.real = this->pwms[i];
      *(outbuffer + offset + 0) = (u_pwmsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pwmsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pwmsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pwmsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pwms[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t motor_index_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_index_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_index_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_index_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_index_length);
      if(motor_index_lengthT > motor_index_length)
        this->motor_index = (uint8_t*)realloc(this->motor_index, motor_index_lengthT * sizeof(uint8_t));
      motor_index_length = motor_index_lengthT;
      for( uint32_t i = 0; i < motor_index_length; i++){
      this->st_motor_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_motor_index);
        memcpy( &(this->motor_index[i]), &(this->st_motor_index), sizeof(uint8_t));
      }
      uint32_t pwms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pwms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pwms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pwms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pwms_length);
      if(pwms_lengthT > pwms_length)
        this->pwms = (float*)realloc(this->pwms, pwms_lengthT * sizeof(float));
      pwms_length = pwms_lengthT;
      for( uint32_t i = 0; i < pwms_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pwms;
      u_st_pwms.base = 0;
      u_st_pwms.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pwms.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pwms.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pwms.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pwms = u_st_pwms.real;
      offset += sizeof(this->st_pwms);
        memcpy( &(this->pwms[i]), &(this->st_pwms), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "spinal/PwmTest"; };
    virtual const char * getMD5() override { return "cde6ce7a926a6c0df9ceed0fa7842042"; };

  };

}
#endif
