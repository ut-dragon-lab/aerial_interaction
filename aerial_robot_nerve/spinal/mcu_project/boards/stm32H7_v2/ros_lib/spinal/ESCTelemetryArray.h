#ifndef _ROS_spinal_ESCTelemetryArray_h
#define _ROS_spinal_ESCTelemetryArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "spinal/ESCTelemetry.h"

namespace spinal
{

  class ESCTelemetryArray : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef spinal::ESCTelemetry _esc_telemetry_1_type;
      _esc_telemetry_1_type esc_telemetry_1;
      typedef spinal::ESCTelemetry _esc_telemetry_2_type;
      _esc_telemetry_2_type esc_telemetry_2;
      typedef spinal::ESCTelemetry _esc_telemetry_3_type;
      _esc_telemetry_3_type esc_telemetry_3;
      typedef spinal::ESCTelemetry _esc_telemetry_4_type;
      _esc_telemetry_4_type esc_telemetry_4;

    ESCTelemetryArray():
      stamp(),
      esc_telemetry_1(),
      esc_telemetry_2(),
      esc_telemetry_3(),
      esc_telemetry_4()
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
      offset += this->esc_telemetry_1.serialize(outbuffer + offset);
      offset += this->esc_telemetry_2.serialize(outbuffer + offset);
      offset += this->esc_telemetry_3.serialize(outbuffer + offset);
      offset += this->esc_telemetry_4.serialize(outbuffer + offset);
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
      offset += this->esc_telemetry_1.deserialize(inbuffer + offset);
      offset += this->esc_telemetry_2.deserialize(inbuffer + offset);
      offset += this->esc_telemetry_3.deserialize(inbuffer + offset);
      offset += this->esc_telemetry_4.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "spinal/ESCTelemetryArray"; };
    virtual const char * getMD5() override { return "4241fed520a3d67a4b657a2656e3dfda"; };

  };

}
#endif
