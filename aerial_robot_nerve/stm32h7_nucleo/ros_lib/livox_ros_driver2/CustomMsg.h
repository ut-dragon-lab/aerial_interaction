#ifndef _ROS_livox_ros_driver2_CustomMsg_h
#define _ROS_livox_ros_driver2_CustomMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "livox_ros_driver2/CustomPoint.h"

namespace livox_ros_driver2
{

  class CustomMsg : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _timebase_type;
      _timebase_type timebase;
      typedef uint32_t _point_num_type;
      _point_num_type point_num;
      typedef uint8_t _lidar_id_type;
      _lidar_id_type lidar_id;
      uint8_t rsvd[3];
      uint32_t points_length;
      typedef livox_ros_driver2::CustomPoint _points_type;
      _points_type st_points;
      _points_type * points;

    CustomMsg():
      header(),
      timebase(0),
      point_num(0),
      lidar_id(0),
      rsvd(),
      points_length(0), st_points(), points(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->timebase >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timebase >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timebase >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timebase >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->timebase >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->timebase >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->timebase >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->timebase >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timebase);
      *(outbuffer + offset + 0) = (this->point_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_num >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_num);
      *(outbuffer + offset + 0) = (this->lidar_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lidar_id);
      for( uint32_t i = 0; i < 3; i++){
      *(outbuffer + offset + 0) = (this->rsvd[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rsvd[i]);
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->timebase =  ((uint64_t) (*(inbuffer + offset)));
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->timebase |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->timebase);
      this->point_num =  ((uint32_t) (*(inbuffer + offset)));
      this->point_num |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->point_num |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->point_num |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->point_num);
      this->lidar_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lidar_id);
      for( uint32_t i = 0; i < 3; i++){
      this->rsvd[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rsvd[i]);
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (livox_ros_driver2::CustomPoint*)realloc(this->points, points_lengthT * sizeof(livox_ros_driver2::CustomPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(livox_ros_driver2::CustomPoint));
      }
     return offset;
    }

    virtual const char * getType() override { return "livox_ros_driver2/CustomMsg"; };
    virtual const char * getMD5() override { return "e4d6829bdfe657cb6c21a746c86b21a6"; };

  };

}
#endif
