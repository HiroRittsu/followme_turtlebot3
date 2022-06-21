#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"


class FollowMe : public rclcpp::Node {
public:
    FollowMe() : Node("follow_me") {

        auto onScan = [this](const sensor_msgs::msg::LaserScan::UniquePtr msgs) -> void {
            this->positions.clear();
            float rad = msgs->angle_min;
            for (const auto &range: msgs->ranges) {
                this->positions.emplace_back(range * std::sin(rad) * 100, -range * std::cos(rad) * 100);
                rad += msgs->angle_increment;
            }
        };

        rclcpp::QoS qos(rclcpp::KeepLast(10));
        this->subScan = create_subscription<sensor_msgs::msg::LaserScan>("scan", qos, onScan);
    }

    void calc();

private:
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subScan;
    std::vector<std::pair<float, float>> positions;
};
