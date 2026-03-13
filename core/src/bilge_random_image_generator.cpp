#include "bilge_random_image_generator.h"

#include "std_msgs/msg/header.hpp"
#include <chrono>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

BilgeRandomImageGenerator::BilgeRandomImageGenerator() {}

sensor_msgs::msg::Image::SharedPtr BilgeRandomImageGenerator::GenerateRandomImage() const {
    cv::Mat my_image(cv::Size(640, 480), CV_8UC3);
    cv::randu(my_image, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));
    return cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", my_image).toImageMsg();
  }