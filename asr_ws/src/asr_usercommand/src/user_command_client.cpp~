#include "ros/ros.h"
#include "asr_usercommand/UserCommand.h"
#include <cstdlib>
#include "std_msgs/String.h"



int main(int argc, char **argv)
{
  ros::init(argc, argv, "user_command__client");
  
 // if (argc != 2)
 //{
 //    ROS_INFO("usage: user_command_client,Please input '0' to trigger the service");
 //  return 1;
 //}

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<asr_usercommand::UserCommand>("user_command");
  
  asr_usercommand::UserCommand srv;
  //srv.request.num = atoll(argv[1]);//argv[1]=0 表示触发server服务；非0则无效；
  srv.request.num=0;//默认将其设置为0，以触发server服务；
  if(srv.request.num== 0)
 {
	  if (client.call(srv))
	  {
	   // printf("Please response command: %s\n", srv.response.command.c_str());
	    ROS_INFO("Success to call service user_command!");
	  }
	  else
	  {
	    ROS_ERROR("Failed to call service user_command");
	    return 1;
	  }
 }
  else
  {
       ROS_INFO("Wrong number to trigger the service, Please input '0'!"); 
  }
  return 0;
}
