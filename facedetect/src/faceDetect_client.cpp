#include "ros/ros.h"
#include "facedetect/FacePosition.h"
#include "std_msgs/String.h"



int main(int argc, char **argv)
{
	ros::init(argc, argv, "faceDetect_client");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<facedetect::FacePosition>("faceDetect");
 
	facedetect::FacePosition srv;
	srv.request.trigger=1;//trigger=1,stand for triggering the service;
	  if(srv.request.trigger== 1)
 {
	  if (client.call(srv))
	  {
	   // printf("Please response command: %s\n", srv.response.command.c_str());
	    ROS_INFO("Success to call service faceDetect!");
	  }
	  else
	  {
	    ROS_ERROR("Failed to call service faceDetect!");
	    return 1;
	  }
 }
                else
                {
                	ROS_INFO("Wrong number to trigger the service, Please input '1'!"); 
                }
        
                return 0;
}
