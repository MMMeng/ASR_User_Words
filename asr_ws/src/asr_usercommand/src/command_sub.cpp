#include "ros/ros.h"
#include "std_msgs/String.h"
#include "asr_usercommand/Command.h"

void commandCallback(asr_usercommand::Command  msg)
{
  printf("I heard: %s\n", msg.command.c_str());
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "command_subscriber");

  ros::NodeHandle n;

  ros::Subscriber command_sub = n.subscribe("command", 1000, commandCallback);
  ros::spin();

  return 0;
}
