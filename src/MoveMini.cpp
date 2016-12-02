#include "move_mini/move_mini.h"

MoveMini::MoveMini(){
	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",1);
	odom_sub = nh.subscribe("/odom",10,&MoveMini::odom_cb,this);
	std::cout << "角度を入力してね(deg)" << std::endl;
	std::cin >> angular;
	theta = 0;
	sum_angular = 0;
	time_cnt = 1;
}

void MoveMini::odom_cb(const nav_msgs::OdometryConstPtr& msg){
	theta = msg->pose.pose.orientation.z;
	vth = msg->twist.twist.angular.z;	
	//ROS_INFO("Odom is God");
}

void MoveMini::RotateMini(){
	double diff_theta = angular/180 - theta;
	double kp = 2;
	cmd.angular.z = kp * diff_theta;
	std::cout << "diff_theta = " << diff_theta << std::endl;
	cmd_vel_pub.publish(cmd);
}
