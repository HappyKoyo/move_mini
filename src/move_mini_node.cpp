#include "move_mini/move_mini.h"

int main(int argc,char **argv){
	ros::init(argc, argv, "move_mini");
	ros::NodeHandle n("~");
	MoveMini mm;
	ros::Rate loop_rate(10);
	while(ros::ok()){
		mm.RotateMini();
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
