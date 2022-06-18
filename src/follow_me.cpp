#include <memory>
#include "../include/followme_turtlebot3/follow_me.hpp"


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FollowMe>());
    rclcpp::shutdown();
    return 0;
}
