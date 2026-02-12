#ifndef _ROS_dynamixel_msgs_JointState_h
#define _ROS_dynamixel_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dynamixel_msgs
{

  class JointState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      uint32_t motor_ids_length;
      typedef int32_t _motor_ids_type;
      _motor_ids_type st_motor_ids;
      _motor_ids_type * motor_ids;
      uint32_t motor_temps_length;
      typedef int32_t _motor_temps_type;
      _motor_temps_type st_motor_temps;
      _motor_temps_type * motor_temps;
      typedef double _goal_pos_type;
      _goal_pos_type goal_pos;
      typedef double _current_pos_type;
      _current_pos_type current_pos;
      typedef double _error_type;
      _error_type error;
      typedef double _velocity_type;
      _velocity_type velocity;
      typedef double _load_type;
      _load_type load;
      typedef bool _is_moving_type;
      _is_moving_type is_moving;

    JointState():
      header(),
      name(""),
      motor_ids_length(0), st_motor_ids(), motor_ids(nullptr),
      motor_temps_length(0), st_motor_temps(), motor_temps(nullptr),
      goal_pos(0),
      current_pos(0),
      error(0),
      velocity(0),
      load(0),
      is_moving(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->motor_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_ids_length);
      for( uint32_t i = 0; i < motor_ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_motor_idsi;
      u_motor_idsi.real = this->motor_ids[i];
      *(outbuffer + offset + 0) = (u_motor_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_temps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_temps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_temps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_temps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_temps_length);
      for( uint32_t i = 0; i < motor_temps_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_motor_tempsi;
      u_motor_tempsi.real = this->motor_temps[i];
      *(outbuffer + offset + 0) = (u_motor_tempsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_tempsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_tempsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_tempsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_temps[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_goal_pos;
      u_goal_pos.real = this->goal_pos;
      *(outbuffer + offset + 0) = (u_goal_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_goal_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_goal_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_goal_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_goal_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_goal_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_goal_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_goal_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->goal_pos);
      union {
        double real;
        uint64_t base;
      } u_current_pos;
      u_current_pos.real = this->current_pos;
      *(outbuffer + offset + 0) = (u_current_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current_pos);
      union {
        double real;
        uint64_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_load;
      u_load.real = this->load;
      *(outbuffer + offset + 0) = (u_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_load.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_load.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_load.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_load.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_load.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_load.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_load.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->load);
      union {
        bool real;
        uint8_t base;
      } u_is_moving;
      u_is_moving.real = this->is_moving;
      *(outbuffer + offset + 0) = (u_is_moving.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_moving);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t motor_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_ids_length);
      if(motor_ids_lengthT > motor_ids_length)
        this->motor_ids = (int32_t*)realloc(this->motor_ids, motor_ids_lengthT * sizeof(int32_t));
      motor_ids_length = motor_ids_lengthT;
      for( uint32_t i = 0; i < motor_ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_motor_ids;
      u_st_motor_ids.base = 0;
      u_st_motor_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_motor_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_motor_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_motor_ids = u_st_motor_ids.real;
      offset += sizeof(this->st_motor_ids);
        memcpy( &(this->motor_ids[i]), &(this->st_motor_ids), sizeof(int32_t));
      }
      uint32_t motor_temps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_temps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_temps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_temps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_temps_length);
      if(motor_temps_lengthT > motor_temps_length)
        this->motor_temps = (int32_t*)realloc(this->motor_temps, motor_temps_lengthT * sizeof(int32_t));
      motor_temps_length = motor_temps_lengthT;
      for( uint32_t i = 0; i < motor_temps_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_motor_temps;
      u_st_motor_temps.base = 0;
      u_st_motor_temps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_temps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_motor_temps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_motor_temps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_motor_temps = u_st_motor_temps.real;
      offset += sizeof(this->st_motor_temps);
        memcpy( &(this->motor_temps[i]), &(this->st_motor_temps), sizeof(int32_t));
      }
      union {
        double real;
        uint64_t base;
      } u_goal_pos;
      u_goal_pos.base = 0;
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_goal_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->goal_pos = u_goal_pos.real;
      offset += sizeof(this->goal_pos);
      union {
        double real;
        uint64_t base;
      } u_current_pos;
      u_current_pos.base = 0;
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current_pos = u_current_pos.real;
      offset += sizeof(this->current_pos);
      union {
        double real;
        uint64_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error = u_error.real;
      offset += sizeof(this->error);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_load;
      u_load.base = 0;
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_load.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->load = u_load.real;
      offset += sizeof(this->load);
      union {
        bool real;
        uint8_t base;
      } u_is_moving;
      u_is_moving.base = 0;
      u_is_moving.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_moving = u_is_moving.real;
      offset += sizeof(this->is_moving);
     return offset;
    }

    virtual const char * getType() override { return "dynamixel_msgs/JointState"; };
    virtual const char * getMD5() override { return "2b8449320cde76616338e2539db27c32"; };

  };

}
#endif
