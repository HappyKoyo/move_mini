#ifndef MOVE_MINI_MOVE_MINI_H_
#define MOVE_MINI_MOVE_MINI_H_

#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <math.h>

class MoveMini{
	private:
		ros::Publisher cmd_vel_pub;
		ros::Subscriber odom_sub;
		void odom_cb(const nav_msgs::OdometryConstPtr& msg);
		int time_cnt;
		double sum_angular;
		double angular;
		double theta;
		double vth;
	public:
		MoveMini();
		void RotateMini();
		ros::NodeHandle nh;
		geometry_msgs::Twist cmd;
};

#endif
