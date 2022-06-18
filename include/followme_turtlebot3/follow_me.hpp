#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"


class FollowMe : public rclcpp::Node {
public:
    FollowMe() : Node("minimal_subscriber") {
        this->create_subscription<sensor_msgs::msg::LaserScan>(
                "scan", 10, std::bind(&FollowMe::scanCallback, this, std::placeholders::_1));
    }

private:
    void scanCallback(const sensor_msgs::msg::LaserScan::ConstSharedPtr msg) const {
        for (auto range: msg->ranges) {
            std::cout << range << '\n';
        }
    }
};