#include "ros/ros.h"
#include "asr_usercommand/UserCommand.h"
#include <cstdlib>
#include "std_msgs/String.h"



int main(int argc, char **argv)
{
  ros::init(argc, argv, "user_command__client");
  
  if (argc != 2)
  {
    ROS_INFO("usage: user_command_client,Please input the audio number num:");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<asr_usercommand::UserCommand>("user_command");
  
  asr_usercommand::UserCommand srv;
  srv.request.num = atoll(argv[1]);
  if (client.call(srv))
  {
    printf("Please response command: %s\n", srv.response.command.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service user_command");
    return 1;
  }
  return 0;
}
