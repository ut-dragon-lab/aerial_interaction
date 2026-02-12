#ifndef _ROS_spinal_ESCTelemetry_h
#define _ROS_spinal_ESCTelemetry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spinal
{

  class ESCTelemetry : public ros::Msg
  {
    public:
      typedef int8_t _temperature_type;
      _temperature_type temperature;
      typedef uint16_t _voltage_type;
      _voltage_type voltage;
      typedef uint16_t _current_type;
      _current_type current;
      typedef uint16_t _consumption_type;
      _consumption_type consumption;
      typedef uint32_t _rpm_type;
      _rpm_type rpm;
      typedef uint8_t _crc_error_type;
      _crc_error_type crc_error;

    ESCTelemetry():
      temperature(0),
      voltage(0),
      current(0),
      consumption(0),
      rpm(0),
      crc_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature);
      *(outbuffer + offset + 0) = (this->voltage >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage);
      *(outbuffer + offset + 0) = (this->current >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current);
      *(outbuffer + offset + 0) = (this->consumption >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->consumption >> (8 * 1)) & 0xFF;
      offset += sizeof(this->consumption);
      *(outbuffer + offset + 0) = (this->rpm >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rpm >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rpm >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rpm >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpm);
      *(outbuffer + offset + 0) = (this->crc_error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->crc_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      this->voltage =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage);
      this->current =  ((uint16_t) (*(inbuffer + offset)));
      this->current |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current);
      this->consumption =  ((uint16_t) (*(inbuffer + offset)));
      this->consumption |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->consumption);
      this->rpm =  ((uint32_t) (*(inbuffer + offset)));
      this->rpm |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rpm |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->rpm |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->rpm);
      this->crc_error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->crc_error);
     return offset;
    }

    virtual const char * getType() override { return "spinal/ESCTelemetry"; };
    virtual const char * getMD5() override { return "9b487ff46539816f75a3cc6b7cb27abf"; };

  };

}
#endif
