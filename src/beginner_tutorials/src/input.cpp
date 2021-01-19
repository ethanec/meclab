#include "ros/ros.h"
// #include "std_msgs/String.h"
#include "beginner_tutorials/input_msg.h"
#include <iostream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "input");
  ros::NodeHandle n;
//   ros::Publisher input_pub = n.advertise<std_msgs::String>("input_topic", 1000);
  ros::Publisher input_pub = n.advertise<beginner_tutorials::input_msg>("input_topic", 1000);
  while (input_pub.getNumSubscribers() < 1) { }
  ros::Rate loop_rate(10);
  
  int id;
  float hight, weight;
  n.getParam("/input/id", id);
  n.getParam("/input/hight", hight);
  n.getParam("/input/weight", weight);

  ROS_INFO("The person's id[%d], hight[%lf], weight[%lf]", id, hight, weight);
  
  beginner_tutorials::input_msg msg;
  msg.id = id;
  msg.hight = hight;
  msg.weight = weight;


  input_pub.publish(msg);
  ros::spinOnce();
  loop_rate.sleep();

  return 0;
}
