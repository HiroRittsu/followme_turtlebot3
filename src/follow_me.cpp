#include <memory>
#include "../include/followme_turtlebot3/follow_me.hpp"


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::WallRate rate(30);
    auto node = std::make_shared<FollowMe>();

    while (rclcpp::ok()) {
        rclcpp::spin_some(node);
        node->calc();
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

void FollowMe::calc() {

    if (this->positions.empty()) return;
    std::cout << this->positions.back().first << this->positions.back().second << '\n';

}
