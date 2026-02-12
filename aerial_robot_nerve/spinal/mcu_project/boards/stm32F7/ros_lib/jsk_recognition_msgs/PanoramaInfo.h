#ifndef _ROS_jsk_recognition_msgs_PanoramaInfo_h
#define _ROS_jsk_recognition_msgs_PanoramaInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class PanoramaInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _projection_model_type;
      _projection_model_type projection_model;
      typedef uint32_t _image_height_type;
      _image_height_type image_height;
      typedef uint32_t _image_width_type;
      _image_width_type image_width;
      typedef double _theta_min_type;
      _theta_min_type theta_min;
      typedef double _theta_max_type;
      _theta_max_type theta_max;
      typedef double _phi_min_type;
      _phi_min_type phi_min;
      typedef double _phi_max_type;
      _phi_max_type phi_max;

    PanoramaInfo():
      header(),
      projection_model(""),
      image_height(0),
      image_width(0),
      theta_min(0),
      theta_max(0),
      phi_min(0),
      phi_max(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_projection_model = strlen(this->projection_model);
      varToArr(outbuffer + offset, length_projection_model);
      offset += 4;
      memcpy(outbuffer + offset, this->projection_model, length_projection_model);
      offset += length_projection_model;
      *(outbuffer + offset + 0) = (this->image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      *(outbuffer + offset + 0) = (this->image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      union {
        double real;
        uint64_t base;
      } u_theta_min;
      u_theta_min.real = this->theta_min;
      *(outbuffer + offset + 0) = (u_theta_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_min.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta_min.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta_min.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta_min.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta_min.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta_min);
      union {
        double real;
        uint64_t base;
      } u_theta_max;
      u_theta_max.real = this->theta_max;
      *(outbuffer + offset + 0) = (u_theta_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_max.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta_max.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta_max.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta_max.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta_max.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta_max);
      union {
        double real;
        uint64_t base;
      } u_phi_min;
      u_phi_min.real = this->phi_min;
      *(outbuffer + offset + 0) = (u_phi_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi_min.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_phi_min.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_phi_min.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_phi_min.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_phi_min.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->phi_min);
      union {
        double real;
        uint64_t base;
      } u_phi_max;
      u_phi_max.real = this->phi_max;
      *(outbuffer + offset + 0) = (u_phi_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi_max.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_phi_max.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_phi_max.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_phi_max.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_phi_max.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->phi_max);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_projection_model;
      arrToVar(length_projection_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_projection_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_projection_model-1]=0;
      this->projection_model = (char *)(inbuffer + offset-1);
      offset += length_projection_model;
      this->image_height =  ((uint32_t) (*(inbuffer + offset)));
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_height);
      this->image_width =  ((uint32_t) (*(inbuffer + offset)));
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_width);
      union {
        double real;
        uint64_t base;
      } u_theta_min;
      u_theta_min.base = 0;
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_theta_min.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->theta_min = u_theta_min.real;
      offset += sizeof(this->theta_min);
      union {
        double real;
        uint64_t base;
      } u_theta_max;
      u_theta_max.base = 0;
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_theta_max.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->theta_max = u_theta_max.real;
      offset += sizeof(this->theta_max);
      union {
        double real;
        uint64_t base;
      } u_phi_min;
      u_phi_min.base = 0;
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_phi_min.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->phi_min = u_phi_min.real;
      offset += sizeof(this->phi_min);
      union {
        double real;
        uint64_t base;
      } u_phi_max;
      u_phi_max.base = 0;
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_phi_max.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->phi_max = u_phi_max.real;
      offset += sizeof(this->phi_max);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/PanoramaInfo"; };
    virtual const char * getMD5() override { return "340435d77351bcae6fd5d846323c4a05"; };

  };

}
#endif
