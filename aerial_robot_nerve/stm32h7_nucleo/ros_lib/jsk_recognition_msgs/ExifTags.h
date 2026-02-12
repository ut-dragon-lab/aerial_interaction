#ifndef _ROS_jsk_recognition_msgs_ExifTags_h
#define _ROS_jsk_recognition_msgs_ExifTags_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/ExifGPSInfo.h"

namespace jsk_recognition_msgs
{

  class ExifTags : public ros::Msg
  {
    public:
      typedef const char* _interop_index_type;
      _interop_index_type interop_index;
      typedef uint32_t _image_width_type;
      _image_width_type image_width;
      typedef uint32_t _image_height_type;
      _image_height_type image_height;
      uint32_t bits_per_sample_length;
      typedef uint16_t _bits_per_sample_type;
      _bits_per_sample_type st_bits_per_sample;
      _bits_per_sample_type * bits_per_sample;
      typedef uint16_t _photometric_interpretation_type;
      _photometric_interpretation_type photometric_interpretation;
      typedef const char* _image_description_type;
      _image_description_type image_description;
      typedef const char* _make_type;
      _make_type make;
      typedef const char* _model_type;
      _model_type model;
      typedef uint32_t _strip_offsets_type;
      _strip_offsets_type strip_offsets;
      typedef uint16_t _orientation_type;
      _orientation_type orientation;
      typedef uint16_t _samples_per_pixel_type;
      _samples_per_pixel_type samples_per_pixel;
      typedef uint32_t _rows_per_strip_type;
      _rows_per_strip_type rows_per_strip;
      typedef uint32_t _strip_byte_counts_type;
      _strip_byte_counts_type strip_byte_counts;
      typedef double _x_resolution_type;
      _x_resolution_type x_resolution;
      typedef double _y_resolution_type;
      _y_resolution_type y_resolution;
      typedef uint16_t _planar_configuration_type;
      _planar_configuration_type planar_configuration;
      typedef uint16_t _resolution_unit_type;
      _resolution_unit_type resolution_unit;
      uint16_t transfer_function[768];
      typedef const char* _software_type;
      _software_type software;
      typedef const char* _date_time_type;
      _date_time_type date_time;
      typedef const char* _artist_type;
      _artist_type artist;
      double white_point[2];
      double primary_chromaticities[6];
      typedef uint32_t _tile_width_type;
      _tile_width_type tile_width;
      typedef uint32_t _tile_length_type;
      _tile_length_type tile_length;
      typedef uint32_t _jpg_from_raw_start_type;
      _jpg_from_raw_start_type jpg_from_raw_start;
      typedef uint32_t _jpg_from_raw_length_type;
      _jpg_from_raw_length_type jpg_from_raw_length;
      double ycb_cr_Coefficients[3];
      uint16_t ycb_cr_sub_sampling[2];
      typedef uint16_t _ycb_cr_positioning_type;
      _ycb_cr_positioning_type ycb_cr_positioning;
      double reference_black_white[6];
      typedef const char* _copyright_type;
      _copyright_type copyright;
      typedef double _exposure_time_type;
      _exposure_time_type exposure_time;
      typedef double _f_number_type;
      _f_number_type f_number;
      typedef uint16_t _exposure_program_type;
      _exposure_program_type exposure_program;
      typedef jsk_recognition_msgs::ExifGPSInfo _gps_info_type;
      _gps_info_type gps_info;
      uint32_t iso_length;
      typedef uint16_t _iso_type;
      _iso_type st_iso;
      _iso_type * iso;
      typedef uint16_t _sensitivity_type_type;
      _sensitivity_type_type sensitivity_type;
      typedef uint32_t _standard_output_sensitivity_type;
      _standard_output_sensitivity_type standard_output_sensitivity;
      typedef uint32_t _recommended_exposure_index_type;
      _recommended_exposure_index_type recommended_exposure_index;
      typedef uint32_t _iso_speed_type;
      _iso_speed_type iso_speed;
      typedef uint32_t _iso_speed_latitudeyyy_type;
      _iso_speed_latitudeyyy_type iso_speed_latitudeyyy;
      typedef uint32_t _iso_speed_latitudezzz_type;
      _iso_speed_latitudezzz_type iso_speed_latitudezzz;
      typedef const char* _exif_version_type;
      _exif_version_type exif_version;
      typedef const char* _date_time_original_type;
      _date_time_original_type date_time_original;
      typedef const char* _date_time_digitized_type;
      _date_time_digitized_type date_time_digitized;
      typedef const char* _offset_time_type;
      _offset_time_type offset_time;
      typedef const char* _offset_time_original_type;
      _offset_time_original_type offset_time_original;
      typedef const char* _offset_time_digitized_type;
      _offset_time_digitized_type offset_time_digitized;
      uint8_t components_configuration[4];
      typedef double _compressed_bits_per_pixel_type;
      _compressed_bits_per_pixel_type compressed_bits_per_pixel;
      typedef double _shutter_speed_value_type;
      _shutter_speed_value_type shutter_speed_value;
      typedef double _aperture_value_type;
      _aperture_value_type aperture_value;
      typedef double _brightness_value_type;
      _brightness_value_type brightness_value;
      typedef double _exposure_bias_value_type;
      _exposure_bias_value_type exposure_bias_value;
      typedef double _max_aperture_value_type;
      _max_aperture_value_type max_aperture_value;
      typedef double _subject_distance_type;
      _subject_distance_type subject_distance;
      typedef uint16_t _metering_mode_type;
      _metering_mode_type metering_mode;
      typedef uint16_t _light_source_type;
      _light_source_type light_source;
      typedef uint16_t _flash_type;
      _flash_type flash;
      typedef double _focal_length_type;
      _focal_length_type focal_length;
      uint32_t subject_area_length;
      typedef uint16_t _subject_area_type;
      _subject_area_type st_subject_area;
      _subject_area_type * subject_area;
      typedef const char* _user_comment_type;
      _user_comment_type user_comment;
      typedef const char* _subsec_time_type;
      _subsec_time_type subsec_time;
      typedef const char* _subsec_time_original_type;
      _subsec_time_original_type subsec_time_original;
      typedef const char* _subsec_time_digitized_type;
      _subsec_time_digitized_type subsec_time_digitized;
      typedef double _temperature_type;
      _temperature_type temperature;
      typedef double _humidity_type;
      _humidity_type humidity;
      typedef double _pressure_type;
      _pressure_type pressure;
      typedef double _water_depth_type;
      _water_depth_type water_depth;
      typedef double _acceleration_type;
      _acceleration_type acceleration;
      typedef double _camera_elevation_angle_type;
      _camera_elevation_angle_type camera_elevation_angle;
      typedef const char* _flash_pix_version_type;
      _flash_pix_version_type flash_pix_version;
      typedef uint16_t _color_space_type;
      _color_space_type color_space;
      typedef uint16_t _exif_image_width_type;
      _exif_image_width_type exif_image_width;
      typedef uint16_t _exif_image_height_type;
      _exif_image_height_type exif_image_height;
      typedef const char* _related_sound_file_type;
      _related_sound_file_type related_sound_file;
      typedef double _flash_energy_type;
      _flash_energy_type flash_energy;
      typedef double _focal_plane_x_resolution_type;
      _focal_plane_x_resolution_type focal_plane_x_resolution;
      typedef double _focal_plane_y_resolution_type;
      _focal_plane_y_resolution_type focal_plane_y_resolution;
      typedef uint16_t _focal_plane_resolution_unit_type;
      _focal_plane_resolution_unit_type focal_plane_resolution_unit;
      uint16_t subject_location[2];
      typedef double _exposure_index_type;
      _exposure_index_type exposure_index;
      typedef uint16_t _sensing_method_type;
      _sensing_method_type sensing_method;
      typedef const char* _scene_type_type;
      _scene_type_type scene_type;
      typedef uint16_t _custom_rendered_type;
      _custom_rendered_type custom_rendered;
      typedef uint16_t _exposure_mode_type;
      _exposure_mode_type exposure_mode;
      typedef uint16_t _white_balance_type;
      _white_balance_type white_balance;
      typedef double _digital_zoom_ratio_type;
      _digital_zoom_ratio_type digital_zoom_ratio;
      typedef uint16_t _focal_length_in_35mm_film_type;
      _focal_length_in_35mm_film_type focal_length_in_35mm_film;
      typedef uint16_t _scene_capture_type_type;
      _scene_capture_type_type scene_capture_type;
      typedef uint16_t _gain_control_type;
      _gain_control_type gain_control;
      typedef uint16_t _contrast_type;
      _contrast_type contrast;
      typedef uint16_t _saturation_type;
      _saturation_type saturation;
      typedef uint16_t _sharpness_type;
      _sharpness_type sharpness;
      typedef uint16_t _subject_distance_range_type;
      _subject_distance_range_type subject_distance_range;
      typedef const char* _image_unique_id_type;
      _image_unique_id_type image_unique_id;
      typedef const char* _camera_owner_name_type;
      _camera_owner_name_type camera_owner_name;
      typedef const char* _body_serial_number_type;
      _body_serial_number_type body_serial_number;
      double lens_specification[4];
      typedef const char* _lens_make_type;
      _lens_make_type lens_make;
      typedef const char* _lens_model_type;
      _lens_model_type lens_model;
      typedef const char* _lens_serial_number_type;
      _lens_serial_number_type lens_serial_number;
      typedef uint16_t _composite_image_type;
      _composite_image_type composite_image;
      uint16_t composite_image_count[2];
      typedef double _gamma_type;
      _gamma_type gamma;

    ExifTags():
      interop_index(""),
      image_width(0),
      image_height(0),
      bits_per_sample_length(0), st_bits_per_sample(), bits_per_sample(nullptr),
      photometric_interpretation(0),
      image_description(""),
      make(""),
      model(""),
      strip_offsets(0),
      orientation(0),
      samples_per_pixel(0),
      rows_per_strip(0),
      strip_byte_counts(0),
      x_resolution(0),
      y_resolution(0),
      planar_configuration(0),
      resolution_unit(0),
      transfer_function(),
      software(""),
      date_time(""),
      artist(""),
      white_point(),
      primary_chromaticities(),
      tile_width(0),
      tile_length(0),
      jpg_from_raw_start(0),
      jpg_from_raw_length(0),
      ycb_cr_Coefficients(),
      ycb_cr_sub_sampling(),
      ycb_cr_positioning(0),
      reference_black_white(),
      copyright(""),
      exposure_time(0),
      f_number(0),
      exposure_program(0),
      gps_info(),
      iso_length(0), st_iso(), iso(nullptr),
      sensitivity_type(0),
      standard_output_sensitivity(0),
      recommended_exposure_index(0),
      iso_speed(0),
      iso_speed_latitudeyyy(0),
      iso_speed_latitudezzz(0),
      exif_version(""),
      date_time_original(""),
      date_time_digitized(""),
      offset_time(""),
      offset_time_original(""),
      offset_time_digitized(""),
      components_configuration(),
      compressed_bits_per_pixel(0),
      shutter_speed_value(0),
      aperture_value(0),
      brightness_value(0),
      exposure_bias_value(0),
      max_aperture_value(0),
      subject_distance(0),
      metering_mode(0),
      light_source(0),
      flash(0),
      focal_length(0),
      subject_area_length(0), st_subject_area(), subject_area(nullptr),
      user_comment(""),
      subsec_time(""),
      subsec_time_original(""),
      subsec_time_digitized(""),
      temperature(0),
      humidity(0),
      pressure(0),
      water_depth(0),
      acceleration(0),
      camera_elevation_angle(0),
      flash_pix_version(""),
      color_space(0),
      exif_image_width(0),
      exif_image_height(0),
      related_sound_file(""),
      flash_energy(0),
      focal_plane_x_resolution(0),
      focal_plane_y_resolution(0),
      focal_plane_resolution_unit(0),
      subject_location(),
      exposure_index(0),
      sensing_method(0),
      scene_type(""),
      custom_rendered(0),
      exposure_mode(0),
      white_balance(0),
      digital_zoom_ratio(0),
      focal_length_in_35mm_film(0),
      scene_capture_type(0),
      gain_control(0),
      contrast(0),
      saturation(0),
      sharpness(0),
      subject_distance_range(0),
      image_unique_id(""),
      camera_owner_name(""),
      body_serial_number(""),
      lens_specification(),
      lens_make(""),
      lens_model(""),
      lens_serial_number(""),
      composite_image(0),
      composite_image_count(),
      gamma(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_interop_index = strlen(this->interop_index);
      varToArr(outbuffer + offset, length_interop_index);
      offset += 4;
      memcpy(outbuffer + offset, this->interop_index, length_interop_index);
      offset += length_interop_index;
      *(outbuffer + offset + 0) = (this->image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      *(outbuffer + offset + 0) = (this->image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      *(outbuffer + offset + 0) = (this->bits_per_sample_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bits_per_sample_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bits_per_sample_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bits_per_sample_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bits_per_sample_length);
      for( uint32_t i = 0; i < bits_per_sample_length; i++){
      *(outbuffer + offset + 0) = (this->bits_per_sample[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bits_per_sample[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->bits_per_sample[i]);
      }
      *(outbuffer + offset + 0) = (this->photometric_interpretation >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->photometric_interpretation >> (8 * 1)) & 0xFF;
      offset += sizeof(this->photometric_interpretation);
      uint32_t length_image_description = strlen(this->image_description);
      varToArr(outbuffer + offset, length_image_description);
      offset += 4;
      memcpy(outbuffer + offset, this->image_description, length_image_description);
      offset += length_image_description;
      uint32_t length_make = strlen(this->make);
      varToArr(outbuffer + offset, length_make);
      offset += 4;
      memcpy(outbuffer + offset, this->make, length_make);
      offset += length_make;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      *(outbuffer + offset + 0) = (this->strip_offsets >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->strip_offsets >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->strip_offsets >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->strip_offsets >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strip_offsets);
      *(outbuffer + offset + 0) = (this->orientation >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation >> (8 * 1)) & 0xFF;
      offset += sizeof(this->orientation);
      *(outbuffer + offset + 0) = (this->samples_per_pixel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->samples_per_pixel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->samples_per_pixel);
      *(outbuffer + offset + 0) = (this->rows_per_strip >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rows_per_strip >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rows_per_strip >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rows_per_strip >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rows_per_strip);
      *(outbuffer + offset + 0) = (this->strip_byte_counts >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->strip_byte_counts >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->strip_byte_counts >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->strip_byte_counts >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strip_byte_counts);
      union {
        double real;
        uint64_t base;
      } u_x_resolution;
      u_x_resolution.real = this->x_resolution;
      *(outbuffer + offset + 0) = (u_x_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_resolution);
      union {
        double real;
        uint64_t base;
      } u_y_resolution;
      u_y_resolution.real = this->y_resolution;
      *(outbuffer + offset + 0) = (u_y_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y_resolution);
      *(outbuffer + offset + 0) = (this->planar_configuration >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planar_configuration >> (8 * 1)) & 0xFF;
      offset += sizeof(this->planar_configuration);
      *(outbuffer + offset + 0) = (this->resolution_unit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resolution_unit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->resolution_unit);
      for( uint32_t i = 0; i < 768; i++){
      *(outbuffer + offset + 0) = (this->transfer_function[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transfer_function[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transfer_function[i]);
      }
      uint32_t length_software = strlen(this->software);
      varToArr(outbuffer + offset, length_software);
      offset += 4;
      memcpy(outbuffer + offset, this->software, length_software);
      offset += length_software;
      uint32_t length_date_time = strlen(this->date_time);
      varToArr(outbuffer + offset, length_date_time);
      offset += 4;
      memcpy(outbuffer + offset, this->date_time, length_date_time);
      offset += length_date_time;
      uint32_t length_artist = strlen(this->artist);
      varToArr(outbuffer + offset, length_artist);
      offset += 4;
      memcpy(outbuffer + offset, this->artist, length_artist);
      offset += length_artist;
      for( uint32_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_white_pointi;
      u_white_pointi.real = this->white_point[i];
      *(outbuffer + offset + 0) = (u_white_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_white_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_white_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_white_pointi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_white_pointi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_white_pointi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_white_pointi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_white_pointi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->white_point[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_primary_chromaticitiesi;
      u_primary_chromaticitiesi.real = this->primary_chromaticities[i];
      *(outbuffer + offset + 0) = (u_primary_chromaticitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_primary_chromaticitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_primary_chromaticitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_primary_chromaticitiesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_primary_chromaticitiesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_primary_chromaticitiesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_primary_chromaticitiesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_primary_chromaticitiesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->primary_chromaticities[i]);
      }
      *(outbuffer + offset + 0) = (this->tile_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tile_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tile_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tile_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tile_width);
      *(outbuffer + offset + 0) = (this->tile_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tile_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tile_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tile_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tile_length);
      *(outbuffer + offset + 0) = (this->jpg_from_raw_start >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jpg_from_raw_start >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jpg_from_raw_start >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jpg_from_raw_start >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jpg_from_raw_start);
      *(outbuffer + offset + 0) = (this->jpg_from_raw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jpg_from_raw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jpg_from_raw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jpg_from_raw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jpg_from_raw_length);
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_ycb_cr_Coefficientsi;
      u_ycb_cr_Coefficientsi.real = this->ycb_cr_Coefficients[i];
      *(outbuffer + offset + 0) = (u_ycb_cr_Coefficientsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ycb_cr_Coefficientsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ycb_cr_Coefficientsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ycb_cr_Coefficientsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ycb_cr_Coefficientsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ycb_cr_Coefficientsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ycb_cr_Coefficientsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ycb_cr_Coefficientsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ycb_cr_Coefficients[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->ycb_cr_sub_sampling[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ycb_cr_sub_sampling[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ycb_cr_sub_sampling[i]);
      }
      *(outbuffer + offset + 0) = (this->ycb_cr_positioning >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ycb_cr_positioning >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ycb_cr_positioning);
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_reference_black_whitei;
      u_reference_black_whitei.real = this->reference_black_white[i];
      *(outbuffer + offset + 0) = (u_reference_black_whitei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_black_whitei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_black_whitei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_black_whitei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_reference_black_whitei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_reference_black_whitei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_reference_black_whitei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_reference_black_whitei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->reference_black_white[i]);
      }
      uint32_t length_copyright = strlen(this->copyright);
      varToArr(outbuffer + offset, length_copyright);
      offset += 4;
      memcpy(outbuffer + offset, this->copyright, length_copyright);
      offset += length_copyright;
      union {
        double real;
        uint64_t base;
      } u_exposure_time;
      u_exposure_time.real = this->exposure_time;
      *(outbuffer + offset + 0) = (u_exposure_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exposure_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exposure_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exposure_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_exposure_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_exposure_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_exposure_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_exposure_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->exposure_time);
      union {
        double real;
        uint64_t base;
      } u_f_number;
      u_f_number.real = this->f_number;
      *(outbuffer + offset + 0) = (u_f_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f_number.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_f_number.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_f_number.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_f_number.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_f_number.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->f_number);
      *(outbuffer + offset + 0) = (this->exposure_program >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exposure_program >> (8 * 1)) & 0xFF;
      offset += sizeof(this->exposure_program);
      offset += this->gps_info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->iso_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iso_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iso_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iso_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iso_length);
      for( uint32_t i = 0; i < iso_length; i++){
      *(outbuffer + offset + 0) = (this->iso[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iso[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->iso[i]);
      }
      *(outbuffer + offset + 0) = (this->sensitivity_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensitivity_type >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensitivity_type);
      *(outbuffer + offset + 0) = (this->standard_output_sensitivity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->standard_output_sensitivity >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->standard_output_sensitivity >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->standard_output_sensitivity >> (8 * 3)) & 0xFF;
      offset += sizeof(this->standard_output_sensitivity);
      *(outbuffer + offset + 0) = (this->recommended_exposure_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recommended_exposure_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recommended_exposure_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recommended_exposure_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recommended_exposure_index);
      *(outbuffer + offset + 0) = (this->iso_speed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iso_speed >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iso_speed >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iso_speed >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iso_speed);
      *(outbuffer + offset + 0) = (this->iso_speed_latitudeyyy >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iso_speed_latitudeyyy >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iso_speed_latitudeyyy >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iso_speed_latitudeyyy >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iso_speed_latitudeyyy);
      *(outbuffer + offset + 0) = (this->iso_speed_latitudezzz >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iso_speed_latitudezzz >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iso_speed_latitudezzz >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iso_speed_latitudezzz >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iso_speed_latitudezzz);
      uint32_t length_exif_version = strlen(this->exif_version);
      varToArr(outbuffer + offset, length_exif_version);
      offset += 4;
      memcpy(outbuffer + offset, this->exif_version, length_exif_version);
      offset += length_exif_version;
      uint32_t length_date_time_original = strlen(this->date_time_original);
      varToArr(outbuffer + offset, length_date_time_original);
      offset += 4;
      memcpy(outbuffer + offset, this->date_time_original, length_date_time_original);
      offset += length_date_time_original;
      uint32_t length_date_time_digitized = strlen(this->date_time_digitized);
      varToArr(outbuffer + offset, length_date_time_digitized);
      offset += 4;
      memcpy(outbuffer + offset, this->date_time_digitized, length_date_time_digitized);
      offset += length_date_time_digitized;
      uint32_t length_offset_time = strlen(this->offset_time);
      varToArr(outbuffer + offset, length_offset_time);
      offset += 4;
      memcpy(outbuffer + offset, this->offset_time, length_offset_time);
      offset += length_offset_time;
      uint32_t length_offset_time_original = strlen(this->offset_time_original);
      varToArr(outbuffer + offset, length_offset_time_original);
      offset += 4;
      memcpy(outbuffer + offset, this->offset_time_original, length_offset_time_original);
      offset += length_offset_time_original;
      uint32_t length_offset_time_digitized = strlen(this->offset_time_digitized);
      varToArr(outbuffer + offset, length_offset_time_digitized);
      offset += 4;
      memcpy(outbuffer + offset, this->offset_time_digitized, length_offset_time_digitized);
      offset += length_offset_time_digitized;
      for( uint32_t i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->components_configuration[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->components_configuration[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_compressed_bits_per_pixel;
      u_compressed_bits_per_pixel.real = this->compressed_bits_per_pixel;
      *(outbuffer + offset + 0) = (u_compressed_bits_per_pixel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_compressed_bits_per_pixel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_compressed_bits_per_pixel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_compressed_bits_per_pixel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_compressed_bits_per_pixel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_compressed_bits_per_pixel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_compressed_bits_per_pixel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_compressed_bits_per_pixel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->compressed_bits_per_pixel);
      union {
        double real;
        uint64_t base;
      } u_shutter_speed_value;
      u_shutter_speed_value.real = this->shutter_speed_value;
      *(outbuffer + offset + 0) = (u_shutter_speed_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_shutter_speed_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_shutter_speed_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_shutter_speed_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_shutter_speed_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_shutter_speed_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_shutter_speed_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_shutter_speed_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->shutter_speed_value);
      union {
        double real;
        uint64_t base;
      } u_aperture_value;
      u_aperture_value.real = this->aperture_value;
      *(outbuffer + offset + 0) = (u_aperture_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aperture_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aperture_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aperture_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_aperture_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_aperture_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_aperture_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_aperture_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->aperture_value);
      union {
        double real;
        uint64_t base;
      } u_brightness_value;
      u_brightness_value.real = this->brightness_value;
      *(outbuffer + offset + 0) = (u_brightness_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brightness_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brightness_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brightness_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_brightness_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_brightness_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_brightness_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_brightness_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->brightness_value);
      union {
        double real;
        uint64_t base;
      } u_exposure_bias_value;
      u_exposure_bias_value.real = this->exposure_bias_value;
      *(outbuffer + offset + 0) = (u_exposure_bias_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exposure_bias_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exposure_bias_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exposure_bias_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_exposure_bias_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_exposure_bias_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_exposure_bias_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_exposure_bias_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->exposure_bias_value);
      union {
        double real;
        uint64_t base;
      } u_max_aperture_value;
      u_max_aperture_value.real = this->max_aperture_value;
      *(outbuffer + offset + 0) = (u_max_aperture_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_aperture_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_aperture_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_aperture_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_aperture_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_aperture_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_aperture_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_aperture_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_aperture_value);
      union {
        double real;
        uint64_t base;
      } u_subject_distance;
      u_subject_distance.real = this->subject_distance;
      *(outbuffer + offset + 0) = (u_subject_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_subject_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_subject_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_subject_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_subject_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_subject_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_subject_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_subject_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->subject_distance);
      *(outbuffer + offset + 0) = (this->metering_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->metering_mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->metering_mode);
      *(outbuffer + offset + 0) = (this->light_source >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->light_source >> (8 * 1)) & 0xFF;
      offset += sizeof(this->light_source);
      *(outbuffer + offset + 0) = (this->flash >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flash >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flash);
      union {
        double real;
        uint64_t base;
      } u_focal_length;
      u_focal_length.real = this->focal_length;
      *(outbuffer + offset + 0) = (u_focal_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_focal_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_focal_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_focal_length.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_focal_length.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_focal_length.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_focal_length.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_focal_length.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->focal_length);
      *(outbuffer + offset + 0) = (this->subject_area_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subject_area_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subject_area_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subject_area_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subject_area_length);
      for( uint32_t i = 0; i < subject_area_length; i++){
      *(outbuffer + offset + 0) = (this->subject_area[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subject_area[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->subject_area[i]);
      }
      uint32_t length_user_comment = strlen(this->user_comment);
      varToArr(outbuffer + offset, length_user_comment);
      offset += 4;
      memcpy(outbuffer + offset, this->user_comment, length_user_comment);
      offset += length_user_comment;
      uint32_t length_subsec_time = strlen(this->subsec_time);
      varToArr(outbuffer + offset, length_subsec_time);
      offset += 4;
      memcpy(outbuffer + offset, this->subsec_time, length_subsec_time);
      offset += length_subsec_time;
      uint32_t length_subsec_time_original = strlen(this->subsec_time_original);
      varToArr(outbuffer + offset, length_subsec_time_original);
      offset += 4;
      memcpy(outbuffer + offset, this->subsec_time_original, length_subsec_time_original);
      offset += length_subsec_time_original;
      uint32_t length_subsec_time_digitized = strlen(this->subsec_time_digitized);
      varToArr(outbuffer + offset, length_subsec_time_digitized);
      offset += 4;
      memcpy(outbuffer + offset, this->subsec_time_digitized, length_subsec_time_digitized);
      offset += length_subsec_time_digitized;
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_humidity;
      u_humidity.real = this->humidity;
      *(outbuffer + offset + 0) = (u_humidity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humidity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humidity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humidity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_humidity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_humidity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_humidity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_humidity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->humidity);
      union {
        double real;
        uint64_t base;
      } u_pressure;
      u_pressure.real = this->pressure;
      *(outbuffer + offset + 0) = (u_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pressure.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pressure.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pressure.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pressure.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pressure);
      union {
        double real;
        uint64_t base;
      } u_water_depth;
      u_water_depth.real = this->water_depth;
      *(outbuffer + offset + 0) = (u_water_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_water_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_water_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_water_depth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_water_depth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_water_depth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_water_depth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_water_depth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->water_depth);
      union {
        double real;
        uint64_t base;
      } u_acceleration;
      u_acceleration.real = this->acceleration;
      *(outbuffer + offset + 0) = (u_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acceleration);
      union {
        double real;
        uint64_t base;
      } u_camera_elevation_angle;
      u_camera_elevation_angle.real = this->camera_elevation_angle;
      *(outbuffer + offset + 0) = (u_camera_elevation_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_camera_elevation_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_camera_elevation_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_camera_elevation_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_camera_elevation_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_camera_elevation_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_camera_elevation_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_camera_elevation_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->camera_elevation_angle);
      uint32_t length_flash_pix_version = strlen(this->flash_pix_version);
      varToArr(outbuffer + offset, length_flash_pix_version);
      offset += 4;
      memcpy(outbuffer + offset, this->flash_pix_version, length_flash_pix_version);
      offset += length_flash_pix_version;
      *(outbuffer + offset + 0) = (this->color_space >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->color_space >> (8 * 1)) & 0xFF;
      offset += sizeof(this->color_space);
      *(outbuffer + offset + 0) = (this->exif_image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exif_image_width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->exif_image_width);
      *(outbuffer + offset + 0) = (this->exif_image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exif_image_height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->exif_image_height);
      uint32_t length_related_sound_file = strlen(this->related_sound_file);
      varToArr(outbuffer + offset, length_related_sound_file);
      offset += 4;
      memcpy(outbuffer + offset, this->related_sound_file, length_related_sound_file);
      offset += length_related_sound_file;
      union {
        double real;
        uint64_t base;
      } u_flash_energy;
      u_flash_energy.real = this->flash_energy;
      *(outbuffer + offset + 0) = (u_flash_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flash_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flash_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flash_energy.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_flash_energy.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_flash_energy.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_flash_energy.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_flash_energy.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->flash_energy);
      union {
        double real;
        uint64_t base;
      } u_focal_plane_x_resolution;
      u_focal_plane_x_resolution.real = this->focal_plane_x_resolution;
      *(outbuffer + offset + 0) = (u_focal_plane_x_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_focal_plane_x_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_focal_plane_x_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_focal_plane_x_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_focal_plane_x_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_focal_plane_x_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_focal_plane_x_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_focal_plane_x_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->focal_plane_x_resolution);
      union {
        double real;
        uint64_t base;
      } u_focal_plane_y_resolution;
      u_focal_plane_y_resolution.real = this->focal_plane_y_resolution;
      *(outbuffer + offset + 0) = (u_focal_plane_y_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_focal_plane_y_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_focal_plane_y_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_focal_plane_y_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_focal_plane_y_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_focal_plane_y_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_focal_plane_y_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_focal_plane_y_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->focal_plane_y_resolution);
      *(outbuffer + offset + 0) = (this->focal_plane_resolution_unit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->focal_plane_resolution_unit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->focal_plane_resolution_unit);
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->subject_location[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subject_location[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->subject_location[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_exposure_index;
      u_exposure_index.real = this->exposure_index;
      *(outbuffer + offset + 0) = (u_exposure_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exposure_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exposure_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exposure_index.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_exposure_index.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_exposure_index.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_exposure_index.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_exposure_index.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->exposure_index);
      *(outbuffer + offset + 0) = (this->sensing_method >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensing_method >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensing_method);
      uint32_t length_scene_type = strlen(this->scene_type);
      varToArr(outbuffer + offset, length_scene_type);
      offset += 4;
      memcpy(outbuffer + offset, this->scene_type, length_scene_type);
      offset += length_scene_type;
      *(outbuffer + offset + 0) = (this->custom_rendered >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->custom_rendered >> (8 * 1)) & 0xFF;
      offset += sizeof(this->custom_rendered);
      *(outbuffer + offset + 0) = (this->exposure_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exposure_mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->exposure_mode);
      *(outbuffer + offset + 0) = (this->white_balance >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->white_balance >> (8 * 1)) & 0xFF;
      offset += sizeof(this->white_balance);
      union {
        double real;
        uint64_t base;
      } u_digital_zoom_ratio;
      u_digital_zoom_ratio.real = this->digital_zoom_ratio;
      *(outbuffer + offset + 0) = (u_digital_zoom_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_digital_zoom_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_digital_zoom_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_digital_zoom_ratio.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_digital_zoom_ratio.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_digital_zoom_ratio.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_digital_zoom_ratio.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_digital_zoom_ratio.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->digital_zoom_ratio);
      *(outbuffer + offset + 0) = (this->focal_length_in_35mm_film >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->focal_length_in_35mm_film >> (8 * 1)) & 0xFF;
      offset += sizeof(this->focal_length_in_35mm_film);
      *(outbuffer + offset + 0) = (this->scene_capture_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scene_capture_type >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scene_capture_type);
      *(outbuffer + offset + 0) = (this->gain_control >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gain_control >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gain_control);
      *(outbuffer + offset + 0) = (this->contrast >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contrast >> (8 * 1)) & 0xFF;
      offset += sizeof(this->contrast);
      *(outbuffer + offset + 0) = (this->saturation >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->saturation >> (8 * 1)) & 0xFF;
      offset += sizeof(this->saturation);
      *(outbuffer + offset + 0) = (this->sharpness >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharpness >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharpness);
      *(outbuffer + offset + 0) = (this->subject_distance_range >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subject_distance_range >> (8 * 1)) & 0xFF;
      offset += sizeof(this->subject_distance_range);
      uint32_t length_image_unique_id = strlen(this->image_unique_id);
      varToArr(outbuffer + offset, length_image_unique_id);
      offset += 4;
      memcpy(outbuffer + offset, this->image_unique_id, length_image_unique_id);
      offset += length_image_unique_id;
      uint32_t length_camera_owner_name = strlen(this->camera_owner_name);
      varToArr(outbuffer + offset, length_camera_owner_name);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_owner_name, length_camera_owner_name);
      offset += length_camera_owner_name;
      uint32_t length_body_serial_number = strlen(this->body_serial_number);
      varToArr(outbuffer + offset, length_body_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->body_serial_number, length_body_serial_number);
      offset += length_body_serial_number;
      for( uint32_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_lens_specificationi;
      u_lens_specificationi.real = this->lens_specification[i];
      *(outbuffer + offset + 0) = (u_lens_specificationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lens_specificationi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lens_specificationi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lens_specificationi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lens_specificationi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lens_specificationi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lens_specificationi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lens_specificationi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lens_specification[i]);
      }
      uint32_t length_lens_make = strlen(this->lens_make);
      varToArr(outbuffer + offset, length_lens_make);
      offset += 4;
      memcpy(outbuffer + offset, this->lens_make, length_lens_make);
      offset += length_lens_make;
      uint32_t length_lens_model = strlen(this->lens_model);
      varToArr(outbuffer + offset, length_lens_model);
      offset += 4;
      memcpy(outbuffer + offset, this->lens_model, length_lens_model);
      offset += length_lens_model;
      uint32_t length_lens_serial_number = strlen(this->lens_serial_number);
      varToArr(outbuffer + offset, length_lens_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->lens_serial_number, length_lens_serial_number);
      offset += length_lens_serial_number;
      *(outbuffer + offset + 0) = (this->composite_image >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->composite_image >> (8 * 1)) & 0xFF;
      offset += sizeof(this->composite_image);
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->composite_image_count[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->composite_image_count[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->composite_image_count[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_gamma;
      u_gamma.real = this->gamma;
      *(outbuffer + offset + 0) = (u_gamma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gamma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gamma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gamma.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gamma.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gamma.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gamma.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gamma.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gamma);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_interop_index;
      arrToVar(length_interop_index, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interop_index; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interop_index-1]=0;
      this->interop_index = (char *)(inbuffer + offset-1);
      offset += length_interop_index;
      this->image_width =  ((uint32_t) (*(inbuffer + offset)));
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_width);
      this->image_height =  ((uint32_t) (*(inbuffer + offset)));
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_height);
      uint32_t bits_per_sample_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bits_per_sample_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bits_per_sample_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bits_per_sample_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bits_per_sample_length);
      if(bits_per_sample_lengthT > bits_per_sample_length)
        this->bits_per_sample = (uint16_t*)realloc(this->bits_per_sample, bits_per_sample_lengthT * sizeof(uint16_t));
      bits_per_sample_length = bits_per_sample_lengthT;
      for( uint32_t i = 0; i < bits_per_sample_length; i++){
      this->st_bits_per_sample =  ((uint16_t) (*(inbuffer + offset)));
      this->st_bits_per_sample |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_bits_per_sample);
        memcpy( &(this->bits_per_sample[i]), &(this->st_bits_per_sample), sizeof(uint16_t));
      }
      this->photometric_interpretation =  ((uint16_t) (*(inbuffer + offset)));
      this->photometric_interpretation |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->photometric_interpretation);
      uint32_t length_image_description;
      arrToVar(length_image_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_image_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_image_description-1]=0;
      this->image_description = (char *)(inbuffer + offset-1);
      offset += length_image_description;
      uint32_t length_make;
      arrToVar(length_make, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_make; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_make-1]=0;
      this->make = (char *)(inbuffer + offset-1);
      offset += length_make;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      this->strip_offsets =  ((uint32_t) (*(inbuffer + offset)));
      this->strip_offsets |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->strip_offsets |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->strip_offsets |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->strip_offsets);
      this->orientation =  ((uint16_t) (*(inbuffer + offset)));
      this->orientation |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->orientation);
      this->samples_per_pixel =  ((uint16_t) (*(inbuffer + offset)));
      this->samples_per_pixel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->samples_per_pixel);
      this->rows_per_strip =  ((uint32_t) (*(inbuffer + offset)));
      this->rows_per_strip |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rows_per_strip |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->rows_per_strip |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->rows_per_strip);
      this->strip_byte_counts =  ((uint32_t) (*(inbuffer + offset)));
      this->strip_byte_counts |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->strip_byte_counts |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->strip_byte_counts |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->strip_byte_counts);
      union {
        double real;
        uint64_t base;
      } u_x_resolution;
      u_x_resolution.base = 0;
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_resolution = u_x_resolution.real;
      offset += sizeof(this->x_resolution);
      union {
        double real;
        uint64_t base;
      } u_y_resolution;
      u_y_resolution.base = 0;
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y_resolution = u_y_resolution.real;
      offset += sizeof(this->y_resolution);
      this->planar_configuration =  ((uint16_t) (*(inbuffer + offset)));
      this->planar_configuration |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->planar_configuration);
      this->resolution_unit =  ((uint16_t) (*(inbuffer + offset)));
      this->resolution_unit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->resolution_unit);
      for( uint32_t i = 0; i < 768; i++){
      this->transfer_function[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->transfer_function[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->transfer_function[i]);
      }
      uint32_t length_software;
      arrToVar(length_software, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_software; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_software-1]=0;
      this->software = (char *)(inbuffer + offset-1);
      offset += length_software;
      uint32_t length_date_time;
      arrToVar(length_date_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_date_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_date_time-1]=0;
      this->date_time = (char *)(inbuffer + offset-1);
      offset += length_date_time;
      uint32_t length_artist;
      arrToVar(length_artist, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_artist; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_artist-1]=0;
      this->artist = (char *)(inbuffer + offset-1);
      offset += length_artist;
      for( uint32_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_white_pointi;
      u_white_pointi.base = 0;
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_white_pointi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->white_point[i] = u_white_pointi.real;
      offset += sizeof(this->white_point[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_primary_chromaticitiesi;
      u_primary_chromaticitiesi.base = 0;
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_primary_chromaticitiesi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->primary_chromaticities[i] = u_primary_chromaticitiesi.real;
      offset += sizeof(this->primary_chromaticities[i]);
      }
      this->tile_width =  ((uint32_t) (*(inbuffer + offset)));
      this->tile_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tile_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tile_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tile_width);
      this->tile_length =  ((uint32_t) (*(inbuffer + offset)));
      this->tile_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tile_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tile_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tile_length);
      this->jpg_from_raw_start =  ((uint32_t) (*(inbuffer + offset)));
      this->jpg_from_raw_start |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->jpg_from_raw_start |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->jpg_from_raw_start |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->jpg_from_raw_start);
      this->jpg_from_raw_length =  ((uint32_t) (*(inbuffer + offset)));
      this->jpg_from_raw_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->jpg_from_raw_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->jpg_from_raw_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->jpg_from_raw_length);
      for( uint32_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_ycb_cr_Coefficientsi;
      u_ycb_cr_Coefficientsi.base = 0;
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ycb_cr_Coefficientsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ycb_cr_Coefficients[i] = u_ycb_cr_Coefficientsi.real;
      offset += sizeof(this->ycb_cr_Coefficients[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      this->ycb_cr_sub_sampling[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->ycb_cr_sub_sampling[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ycb_cr_sub_sampling[i]);
      }
      this->ycb_cr_positioning =  ((uint16_t) (*(inbuffer + offset)));
      this->ycb_cr_positioning |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ycb_cr_positioning);
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_reference_black_whitei;
      u_reference_black_whitei.base = 0;
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_reference_black_whitei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->reference_black_white[i] = u_reference_black_whitei.real;
      offset += sizeof(this->reference_black_white[i]);
      }
      uint32_t length_copyright;
      arrToVar(length_copyright, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_copyright; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_copyright-1]=0;
      this->copyright = (char *)(inbuffer + offset-1);
      offset += length_copyright;
      union {
        double real;
        uint64_t base;
      } u_exposure_time;
      u_exposure_time.base = 0;
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_exposure_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->exposure_time = u_exposure_time.real;
      offset += sizeof(this->exposure_time);
      union {
        double real;
        uint64_t base;
      } u_f_number;
      u_f_number.base = 0;
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_f_number.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->f_number = u_f_number.real;
      offset += sizeof(this->f_number);
      this->exposure_program =  ((uint16_t) (*(inbuffer + offset)));
      this->exposure_program |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->exposure_program);
      offset += this->gps_info.deserialize(inbuffer + offset);
      uint32_t iso_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      iso_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      iso_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      iso_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->iso_length);
      if(iso_lengthT > iso_length)
        this->iso = (uint16_t*)realloc(this->iso, iso_lengthT * sizeof(uint16_t));
      iso_length = iso_lengthT;
      for( uint32_t i = 0; i < iso_length; i++){
      this->st_iso =  ((uint16_t) (*(inbuffer + offset)));
      this->st_iso |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_iso);
        memcpy( &(this->iso[i]), &(this->st_iso), sizeof(uint16_t));
      }
      this->sensitivity_type =  ((uint16_t) (*(inbuffer + offset)));
      this->sensitivity_type |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sensitivity_type);
      this->standard_output_sensitivity =  ((uint32_t) (*(inbuffer + offset)));
      this->standard_output_sensitivity |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->standard_output_sensitivity |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->standard_output_sensitivity |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->standard_output_sensitivity);
      this->recommended_exposure_index =  ((uint32_t) (*(inbuffer + offset)));
      this->recommended_exposure_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recommended_exposure_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->recommended_exposure_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->recommended_exposure_index);
      this->iso_speed =  ((uint32_t) (*(inbuffer + offset)));
      this->iso_speed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->iso_speed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->iso_speed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->iso_speed);
      this->iso_speed_latitudeyyy =  ((uint32_t) (*(inbuffer + offset)));
      this->iso_speed_latitudeyyy |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->iso_speed_latitudeyyy |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->iso_speed_latitudeyyy |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->iso_speed_latitudeyyy);
      this->iso_speed_latitudezzz =  ((uint32_t) (*(inbuffer + offset)));
      this->iso_speed_latitudezzz |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->iso_speed_latitudezzz |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->iso_speed_latitudezzz |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->iso_speed_latitudezzz);
      uint32_t length_exif_version;
      arrToVar(length_exif_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_exif_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_exif_version-1]=0;
      this->exif_version = (char *)(inbuffer + offset-1);
      offset += length_exif_version;
      uint32_t length_date_time_original;
      arrToVar(length_date_time_original, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_date_time_original; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_date_time_original-1]=0;
      this->date_time_original = (char *)(inbuffer + offset-1);
      offset += length_date_time_original;
      uint32_t length_date_time_digitized;
      arrToVar(length_date_time_digitized, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_date_time_digitized; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_date_time_digitized-1]=0;
      this->date_time_digitized = (char *)(inbuffer + offset-1);
      offset += length_date_time_digitized;
      uint32_t length_offset_time;
      arrToVar(length_offset_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_offset_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_offset_time-1]=0;
      this->offset_time = (char *)(inbuffer + offset-1);
      offset += length_offset_time;
      uint32_t length_offset_time_original;
      arrToVar(length_offset_time_original, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_offset_time_original; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_offset_time_original-1]=0;
      this->offset_time_original = (char *)(inbuffer + offset-1);
      offset += length_offset_time_original;
      uint32_t length_offset_time_digitized;
      arrToVar(length_offset_time_digitized, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_offset_time_digitized; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_offset_time_digitized-1]=0;
      this->offset_time_digitized = (char *)(inbuffer + offset-1);
      offset += length_offset_time_digitized;
      for( uint32_t i = 0; i < 4; i++){
      this->components_configuration[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->components_configuration[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_compressed_bits_per_pixel;
      u_compressed_bits_per_pixel.base = 0;
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_compressed_bits_per_pixel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->compressed_bits_per_pixel = u_compressed_bits_per_pixel.real;
      offset += sizeof(this->compressed_bits_per_pixel);
      union {
        double real;
        uint64_t base;
      } u_shutter_speed_value;
      u_shutter_speed_value.base = 0;
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_shutter_speed_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->shutter_speed_value = u_shutter_speed_value.real;
      offset += sizeof(this->shutter_speed_value);
      union {
        double real;
        uint64_t base;
      } u_aperture_value;
      u_aperture_value.base = 0;
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->aperture_value = u_aperture_value.real;
      offset += sizeof(this->aperture_value);
      union {
        double real;
        uint64_t base;
      } u_brightness_value;
      u_brightness_value.base = 0;
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_brightness_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->brightness_value = u_brightness_value.real;
      offset += sizeof(this->brightness_value);
      union {
        double real;
        uint64_t base;
      } u_exposure_bias_value;
      u_exposure_bias_value.base = 0;
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_exposure_bias_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->exposure_bias_value = u_exposure_bias_value.real;
      offset += sizeof(this->exposure_bias_value);
      union {
        double real;
        uint64_t base;
      } u_max_aperture_value;
      u_max_aperture_value.base = 0;
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_aperture_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_aperture_value = u_max_aperture_value.real;
      offset += sizeof(this->max_aperture_value);
      union {
        double real;
        uint64_t base;
      } u_subject_distance;
      u_subject_distance.base = 0;
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_subject_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->subject_distance = u_subject_distance.real;
      offset += sizeof(this->subject_distance);
      this->metering_mode =  ((uint16_t) (*(inbuffer + offset)));
      this->metering_mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->metering_mode);
      this->light_source =  ((uint16_t) (*(inbuffer + offset)));
      this->light_source |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->light_source);
      this->flash =  ((uint16_t) (*(inbuffer + offset)));
      this->flash |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->flash);
      union {
        double real;
        uint64_t base;
      } u_focal_length;
      u_focal_length.base = 0;
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_focal_length.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->focal_length = u_focal_length.real;
      offset += sizeof(this->focal_length);
      uint32_t subject_area_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subject_area_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subject_area_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subject_area_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subject_area_length);
      if(subject_area_lengthT > subject_area_length)
        this->subject_area = (uint16_t*)realloc(this->subject_area, subject_area_lengthT * sizeof(uint16_t));
      subject_area_length = subject_area_lengthT;
      for( uint32_t i = 0; i < subject_area_length; i++){
      this->st_subject_area =  ((uint16_t) (*(inbuffer + offset)));
      this->st_subject_area |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_subject_area);
        memcpy( &(this->subject_area[i]), &(this->st_subject_area), sizeof(uint16_t));
      }
      uint32_t length_user_comment;
      arrToVar(length_user_comment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_comment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_comment-1]=0;
      this->user_comment = (char *)(inbuffer + offset-1);
      offset += length_user_comment;
      uint32_t length_subsec_time;
      arrToVar(length_subsec_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subsec_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subsec_time-1]=0;
      this->subsec_time = (char *)(inbuffer + offset-1);
      offset += length_subsec_time;
      uint32_t length_subsec_time_original;
      arrToVar(length_subsec_time_original, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subsec_time_original; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subsec_time_original-1]=0;
      this->subsec_time_original = (char *)(inbuffer + offset-1);
      offset += length_subsec_time_original;
      uint32_t length_subsec_time_digitized;
      arrToVar(length_subsec_time_digitized, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subsec_time_digitized; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subsec_time_digitized-1]=0;
      this->subsec_time_digitized = (char *)(inbuffer + offset-1);
      offset += length_subsec_time_digitized;
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_humidity;
      u_humidity.base = 0;
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->humidity = u_humidity.real;
      offset += sizeof(this->humidity);
      union {
        double real;
        uint64_t base;
      } u_pressure;
      u_pressure.base = 0;
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pressure.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pressure = u_pressure.real;
      offset += sizeof(this->pressure);
      union {
        double real;
        uint64_t base;
      } u_water_depth;
      u_water_depth.base = 0;
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_water_depth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->water_depth = u_water_depth.real;
      offset += sizeof(this->water_depth);
      union {
        double real;
        uint64_t base;
      } u_acceleration;
      u_acceleration.base = 0;
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acceleration = u_acceleration.real;
      offset += sizeof(this->acceleration);
      union {
        double real;
        uint64_t base;
      } u_camera_elevation_angle;
      u_camera_elevation_angle.base = 0;
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_camera_elevation_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->camera_elevation_angle = u_camera_elevation_angle.real;
      offset += sizeof(this->camera_elevation_angle);
      uint32_t length_flash_pix_version;
      arrToVar(length_flash_pix_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_flash_pix_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_flash_pix_version-1]=0;
      this->flash_pix_version = (char *)(inbuffer + offset-1);
      offset += length_flash_pix_version;
      this->color_space =  ((uint16_t) (*(inbuffer + offset)));
      this->color_space |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->color_space);
      this->exif_image_width =  ((uint16_t) (*(inbuffer + offset)));
      this->exif_image_width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->exif_image_width);
      this->exif_image_height =  ((uint16_t) (*(inbuffer + offset)));
      this->exif_image_height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->exif_image_height);
      uint32_t length_related_sound_file;
      arrToVar(length_related_sound_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_related_sound_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_related_sound_file-1]=0;
      this->related_sound_file = (char *)(inbuffer + offset-1);
      offset += length_related_sound_file;
      union {
        double real;
        uint64_t base;
      } u_flash_energy;
      u_flash_energy.base = 0;
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_flash_energy.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->flash_energy = u_flash_energy.real;
      offset += sizeof(this->flash_energy);
      union {
        double real;
        uint64_t base;
      } u_focal_plane_x_resolution;
      u_focal_plane_x_resolution.base = 0;
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_focal_plane_x_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->focal_plane_x_resolution = u_focal_plane_x_resolution.real;
      offset += sizeof(this->focal_plane_x_resolution);
      union {
        double real;
        uint64_t base;
      } u_focal_plane_y_resolution;
      u_focal_plane_y_resolution.base = 0;
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_focal_plane_y_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->focal_plane_y_resolution = u_focal_plane_y_resolution.real;
      offset += sizeof(this->focal_plane_y_resolution);
      this->focal_plane_resolution_unit =  ((uint16_t) (*(inbuffer + offset)));
      this->focal_plane_resolution_unit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->focal_plane_resolution_unit);
      for( uint32_t i = 0; i < 2; i++){
      this->subject_location[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->subject_location[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->subject_location[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_exposure_index;
      u_exposure_index.base = 0;
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_exposure_index.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->exposure_index = u_exposure_index.real;
      offset += sizeof(this->exposure_index);
      this->sensing_method =  ((uint16_t) (*(inbuffer + offset)));
      this->sensing_method |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sensing_method);
      uint32_t length_scene_type;
      arrToVar(length_scene_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_scene_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_scene_type-1]=0;
      this->scene_type = (char *)(inbuffer + offset-1);
      offset += length_scene_type;
      this->custom_rendered =  ((uint16_t) (*(inbuffer + offset)));
      this->custom_rendered |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->custom_rendered);
      this->exposure_mode =  ((uint16_t) (*(inbuffer + offset)));
      this->exposure_mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->exposure_mode);
      this->white_balance =  ((uint16_t) (*(inbuffer + offset)));
      this->white_balance |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->white_balance);
      union {
        double real;
        uint64_t base;
      } u_digital_zoom_ratio;
      u_digital_zoom_ratio.base = 0;
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_digital_zoom_ratio.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->digital_zoom_ratio = u_digital_zoom_ratio.real;
      offset += sizeof(this->digital_zoom_ratio);
      this->focal_length_in_35mm_film =  ((uint16_t) (*(inbuffer + offset)));
      this->focal_length_in_35mm_film |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->focal_length_in_35mm_film);
      this->scene_capture_type =  ((uint16_t) (*(inbuffer + offset)));
      this->scene_capture_type |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scene_capture_type);
      this->gain_control =  ((uint16_t) (*(inbuffer + offset)));
      this->gain_control |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gain_control);
      this->contrast =  ((uint16_t) (*(inbuffer + offset)));
      this->contrast |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->contrast);
      this->saturation =  ((uint16_t) (*(inbuffer + offset)));
      this->saturation |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->saturation);
      this->sharpness =  ((uint16_t) (*(inbuffer + offset)));
      this->sharpness |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharpness);
      this->subject_distance_range =  ((uint16_t) (*(inbuffer + offset)));
      this->subject_distance_range |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->subject_distance_range);
      uint32_t length_image_unique_id;
      arrToVar(length_image_unique_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_image_unique_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_image_unique_id-1]=0;
      this->image_unique_id = (char *)(inbuffer + offset-1);
      offset += length_image_unique_id;
      uint32_t length_camera_owner_name;
      arrToVar(length_camera_owner_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_owner_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_owner_name-1]=0;
      this->camera_owner_name = (char *)(inbuffer + offset-1);
      offset += length_camera_owner_name;
      uint32_t length_body_serial_number;
      arrToVar(length_body_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_serial_number-1]=0;
      this->body_serial_number = (char *)(inbuffer + offset-1);
      offset += length_body_serial_number;
      for( uint32_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_lens_specificationi;
      u_lens_specificationi.base = 0;
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lens_specificationi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lens_specification[i] = u_lens_specificationi.real;
      offset += sizeof(this->lens_specification[i]);
      }
      uint32_t length_lens_make;
      arrToVar(length_lens_make, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lens_make; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lens_make-1]=0;
      this->lens_make = (char *)(inbuffer + offset-1);
      offset += length_lens_make;
      uint32_t length_lens_model;
      arrToVar(length_lens_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lens_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lens_model-1]=0;
      this->lens_model = (char *)(inbuffer + offset-1);
      offset += length_lens_model;
      uint32_t length_lens_serial_number;
      arrToVar(length_lens_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lens_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lens_serial_number-1]=0;
      this->lens_serial_number = (char *)(inbuffer + offset-1);
      offset += length_lens_serial_number;
      this->composite_image =  ((uint16_t) (*(inbuffer + offset)));
      this->composite_image |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->composite_image);
      for( uint32_t i = 0; i < 2; i++){
      this->composite_image_count[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->composite_image_count[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->composite_image_count[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_gamma;
      u_gamma.base = 0;
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gamma.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gamma = u_gamma.real;
      offset += sizeof(this->gamma);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/ExifTags"; };
    virtual const char * getMD5() override { return "0db5f040080892d8197ca4a68428c05d"; };

  };

}
#endif
