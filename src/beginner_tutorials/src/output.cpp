#include "ros/ros.h"
#include "beginner_tutorials/output_msg.h"

void chatterCallback(const beginner_tutorials::output_msg::ConstPtr& msg)
{
  ROS_INFO("id: [%d]  BMI:[%.2f]", msg->id, msg->BMI);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "output");
  ros::NodeHandle n;
  ros::Subscriber output_sub = n.subscribe("output_topic", 1000, chatterCallback);
  ros::spin();

  return 0;
}
