#ifndef _ROS_fast_lio_Pose6D_h
#define _ROS_fast_lio_Pose6D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fast_lio
{

  class Pose6D : public ros::Msg
  {
    public:
      typedef double _offset_time_type;
      _offset_time_type offset_time;
      double acc[3];
      double gyr[3];
      double vel[3];
      double pos[3];
      double rot[9];

    Pose6D():
      offset_time(0),
      acc(),
      gyr(),
      vel(),
      pos(),
      rot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_offset_time;
      u_offset_time.real = this->offset_time;
      *(outbuffer + offset + 0) = (u_offset_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_offset_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_offset_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_offset_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_offset_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->offset_time);
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_acci;
      u_acci.real = this->acc[i];
      *(outbuffer + offset + 0) = (u_acci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acci.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acci.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acci.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acci.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acci.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_gyri;
      u_gyri.real = this->gyr[i];
      *(outbuffer + offset + 0) = (u_gyri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyri.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gyri.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gyri.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gyri.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gyri.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gyr[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_veli;
      u_veli.real = this->vel[i];
      *(outbuffer + offset + 0) = (u_veli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_veli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_veli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_veli.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_veli.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_veli.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_veli.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_veli.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vel[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_roti;
      u_roti.real = this->rot[i];
      *(outbuffer + offset + 0) = (u_roti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_offset_time;
      u_offset_time.base = 0;
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_offset_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->offset_time = u_offset_time.real;
      offset += sizeof(this->offset_time);
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_acci;
      u_acci.base = 0;
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acci.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc[i] = u_acci.real;
      offset += sizeof(this->acc[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_gyri;
      u_gyri.base = 0;
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gyri.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gyr[i] = u_gyri.real;
      offset += sizeof(this->gyr[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_veli;
      u_veli.base = 0;
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_veli.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vel[i] = u_veli.real;
      offset += sizeof(this->vel[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_posi;
      u_posi.base = 0;
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos[i] = u_posi.real;
      offset += sizeof(this->pos[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_roti;
      u_roti.base = 0;
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot[i] = u_roti.real;
      offset += sizeof(this->rot[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "fast_lio/Pose6D"; };
    virtual const char * getMD5() override { return "ab486e9c24704038320abf9ff59003d2"; };

  };

}
#endif
