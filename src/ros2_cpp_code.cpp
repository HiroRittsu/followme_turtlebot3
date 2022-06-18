#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
public:
    MinimalSubscriber() : Node("minimal_subscriber") {
        subscribers.push_back(this->create_subscription<sensor_msgs::msg::LaserScan>(
                "scan", 10, std::bind(&MinimalSubscriber::callback, this, _1))
        );
    }

private:
    void callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) const {
        for (auto range: msg->ranges) {
            std::cout << range << '\n';
        }
    }

    std::vector<rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr> subscribers;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}