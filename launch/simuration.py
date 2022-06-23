from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
	return LaunchDescription([
		Node(package="ros_tcp_endpoint", executable="default_server_endpoint"),
		Node(package="followme_turtlebot3", executable="follow_me"),
	])
