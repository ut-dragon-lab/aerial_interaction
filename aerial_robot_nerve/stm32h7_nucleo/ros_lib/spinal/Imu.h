#ifndef _ROS_spinal_Imu_h
#define _ROS_spinal_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace spinal
{

  class Imu : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      float acc[3];
      float gyro[3];
      float mag[3];
      float quaternion[4];

    Imu():
      stamp(),
      acc(),
      gyro(),
      mag(),
      quaternion()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_acci;
      u_acci.real = this->acc[i];
      *(outbuffer + offset + 0) = (u_acci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroi;
      u_gyroi.real = this->gyro[i];
      *(outbuffer + offset + 0) = (u_gyroi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyroi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyroi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyro[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_magi;
      u_magi.real = this->mag[i];
      *(outbuffer + offset + 0) = (u_magi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mag[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.real = this->quaternion[i];
      *(outbuffer + offset + 0) = (u_quaternioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quaternioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quaternioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quaternioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quaternion[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_acci;
      u_acci.base = 0;
      u_acci.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acci.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acci.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acci.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc[i] = u_acci.real;
      offset += sizeof(this->acc[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroi;
      u_gyroi.base = 0;
      u_gyroi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyroi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyroi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gyro[i] = u_gyroi.real;
      offset += sizeof(this->gyro[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_magi;
      u_magi.base = 0;
      u_magi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mag[i] = u_magi.real;
      offset += sizeof(this->mag[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.base = 0;
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quaternion[i] = u_quaternioni.real;
      offset += sizeof(this->quaternion[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "spinal/Imu"; };
    virtual const char * getMD5() override { return "ae078a6cf2a27bba55c15c4ea83c6817"; };

  };

}
#endif
