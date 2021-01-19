#include "ros/ros.h"
// #include "std_msgs/String.h"
#include "beginner_tutorials/input_msg.h"
#include "beginner_tutorials/output_msg.h"
int id;
float hight, weight, BMI;


void chatterCallback(const beginner_tutorials::input_msg::ConstPtr& msg)
{
  // ROS_INFO("I heard: [%s]", msg->data.c_str();
  id = msg->id;
  hight = msg->hight;
  weight = msg-> weight;
  BMI =  weight/(hight*hight);
  ROS_INFO("The person's id[%d], hight[%.2f], weight[%.2f], BMI[%.2f]",msg->id, msg->hight, msg->weight, BMI);

  ros::NodeHandle n;
  ros::Publisher process_pub = n.advertise<beginner_tutorials::output_msg>("output_topic", 1000);
  ros::Rate loop_rate(10);
  beginner_tutorials::output_msg output_msg;
  output_msg.id = id;
  output_msg.BMI = BMI;
  process_pub.publish(output_msg);
  ros::spinOnce();
  loop_rate.sleep();
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "process");
  ros::NodeHandle n;
  ros::Subscriber process_sub = n.subscribe("input_topic", 1000, chatterCallback);
  ros::Publisher process_pub = n.advertise<beginner_tutorials::output_msg>("output_topic", 1000);
  ros::spin();

  return 0;
}
