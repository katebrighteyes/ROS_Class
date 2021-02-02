#include "ros/ros.h"
#include "ros_topic_test/MsgTutorial.h"

void msgCallback(const ros_topic_test::MsgTutorial::ConstPtr& msg)
{
    ROS_INFO("received msg = %d", msg->stamp.sec);
    ROS_INFO("received msg = %d", msg->stamp.nsec);
    ROS_INFO("received msg = %d", msg->data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_sub_test");
    ros::NodeHandle nh;

   ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

    ros::spin();
    return 0;
}

