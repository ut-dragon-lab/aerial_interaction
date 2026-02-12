#ifndef _ROS_geographic_msgs_GeoPoseWithCovarianceStamped_h
#define _ROS_geographic_msgs_GeoPoseWithCovarianceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeoPoseWithCovariance.h"

namespace geographic_msgs
{

  class GeoPoseWithCovarianceStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geographic_msgs::GeoPoseWithCovariance _pose_type;
      _pose_type pose;

    GeoPoseWithCovarianceStamped():
      header(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "geographic_msgs/GeoPoseWithCovarianceStamped"; };
    virtual const char * getMD5() override { return "2cc818b24aae5ffa4fd33f5ee0bb5421"; };

  };

}
#endif
