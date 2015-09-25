#include "ros/ros.h"
#include "asr_usercommand/UserCommand.h"
#include <cstdlib>
#include "std_msgs/String.h"



int main(int argc, char **argv)
{
  ros::init(argc, argv, "record_client");
  
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<asr_usercommand::UserCommand>("recordService");
  
  asr_usercommand::UserCommand srv;
  srv.request.num=0;
  if(srv.request.num== 0)
 {
	  if (client.call(srv))
	  {
	    ROS_INFO("Success to call service recordService!");
	  }
	  else
	  {
	    ROS_ERROR("Failed to call service recordService");
	    return 1;
	  }
 }
  else
  {
       ROS_INFO("Wrong number to trigger the service, Please input '0'!"); 
  }
  return 0;
}
