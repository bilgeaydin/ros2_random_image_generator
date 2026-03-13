#include "node.h"

#include "std_msgs/msg/header.hpp"
#include <chrono>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>

#include <bilge_random_image_generator.h>

static constexpr const char* kOutputImageTopic = "random_image";

using namespace std::chrono_literals;

BilgeRandomImageGeneratorNode::BilgeRandomImageGeneratorNode() : Node("bilge_random_image_generator"), m_count_(0) {
    m_publisher_ =
        this->create_publisher<sensor_msgs::msg::Image>(kOutputImageTopic, 10);
    m_timer_ = this->create_wall_timer(
        500ms, std::bind(&BilgeRandomImageGeneratorNode::timer_callback, this));
  }

void BilgeRandomImageGeneratorNode::timer_callback() {
    BilgeRandomImageGenerator image_generator;
    sensor_msgs::msg::Image::SharedPtr msg_ = image_generator.GenerateRandomImage();
    m_publisher_->publish(*msg_.get());
    RCLCPP_INFO(this->get_logger(), "Random image %ld published", m_count_);
    m_count_++;
  }