#include "ros/ros.h"
#include "ros_topic_test/MsgTutorial.h"

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "topic_pub_test");
    ros::NodeHandle nh;

    ros::Publisher ros_tutorial_pub = 
    nh.advertise<ros_topic_test::MsgTutorial>("ros_tutorial_msg", 100);
    ros::Rate loop_rate(10);

    ros_topic_test::MsgTutorial msg;
    int count = 0;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = count;

        ROS_INFO("send msg = %d", msg.stamp.sec); 
        ROS_INFO("send msg = %d", msg.stamp.nsec); 
        ROS_INFO("send msg = %d", msg.data); 
        ros_tutorial_pub.publish(msg);
        loop_rate.sleep();
        ++count;
     }
     return 0;
}



