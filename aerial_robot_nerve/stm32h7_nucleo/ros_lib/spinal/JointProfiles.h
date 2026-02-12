#ifndef _ROS_spinal_JointProfiles_h
#define _ROS_spinal_JointProfiles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spinal/JointProfile.h"

namespace spinal
{

  class JointProfiles : public ros::Msg
  {
    public:
      uint32_t joints_length;
      typedef spinal::JointProfile _joints_type;
      _joints_type st_joints;
      _joints_type * joints;

    JointProfiles():
      joints_length(0), st_joints(), joints(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->joints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joints_length);
      for( uint32_t i = 0; i < joints_length; i++){
      offset += this->joints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t joints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joints_length);
      if(joints_lengthT > joints_length)
        this->joints = (spinal::JointProfile*)realloc(this->joints, joints_lengthT * sizeof(spinal::JointProfile));
      joints_length = joints_lengthT;
      for( uint32_t i = 0; i < joints_length; i++){
      offset += this->st_joints.deserialize(inbuffer + offset);
        memcpy( &(this->joints[i]), &(this->st_joints), sizeof(spinal::JointProfile));
      }
     return offset;
    }

    virtual const char * getType() override { return "spinal/JointProfiles"; };
    virtual const char * getMD5() override { return "66156f10148589b39044caa245b86798"; };

  };

}
#endif
