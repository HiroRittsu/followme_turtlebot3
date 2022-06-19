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
    void scanCallback(const sensor_msgs::msg::LaserScan::ConstSharedPtr msgs) const {
        float rad = msgs->angle_min;
        std::vector<std::pair<float, float>> positions;

        for (const auto &range: msgs->ranges) {
            positions.emplace_back(range * std::sin(rad) * 100, -range * std::cos(rad) * 100);
            rad += msgs->angle_increment;
        }
    }
};
