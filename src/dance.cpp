#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "bookish_carnival");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/navi", 10);
  ros::Publisher sound_pub = nh.advertise<std_msgs::Int8>("sound", 10);
  ros::Publisher playtime_pub = nh.advertise<std_msgs::Int16>("playtime", 10);
  srand (time(NULL));
  int mode = 0;
  geometry_msgs::Twist msg;
  std_msgs::Int8 msgb;
  std_msgs::Int16 msgc;

  msgb.data = 0;
  msgc.data = 1;
  playtime_pub.publish(msgc);
  sleep(7);
  while(ros::ok())
  {
    mode = rand() % 3 + 0;

    switch(mode)
    {
      case 0:
      {
        //forward
        msg.linear.x = 0.2;
        msg.angular.z = 0.0;
        int tf=0;
        tf = rand() %20 + 6;
        msgb.data = 1;
        msgc.data = tf;
        sound_pub.publish(msgb);
        playtime_pub.publish(msgc);
        for (int i=0 ; i<tf; i++)
          {
            cmd_vel_pub.publish(msg);
            ros::Duration(0.2).sleep();
          }
        msgb.data = 0;
        sound_pub.publish(msgb);
        msg.linear.x = -0.2;
        msg.angular.z = 0.0;
        for (int i=0 ; i<tf; i++)
          {
            cmd_vel_pub.publish(msg);
            ros::Duration(0.2).sleep();
        }


      }
      case 1:
      {
      msg.linear.x = 0.0;
      msg.angular.z = 2.0;
      int ts=0;
      ts = rand() %20 + 6;
      msgb.data = 3;
      msgc.data = ts;
      playtime_pub.publish(msgc);
      sound_pub.publish(msgb);
      for (int i=0 ; i<ts; i++)
        {
          cmd_vel_pub.publish(msg);
          ros::Duration(0.2).sleep();
        }
        msgb.data = 0;
        sound_pub.publish(msgb);
      }
      case 2:
      {
        //back
        msg.linear.x = -0.2;
        msg.angular.z = 0.0;
        int tb=0;
        tb = rand() %20 + 6;
        msgb.data = 2;
        msgc.data = tb;
        playtime_pub.publish(msgc);
        sound_pub.publish(msgb);
        for (int i=0 ; i<tb; i++)
          {
            cmd_vel_pub.publish(msg);
            ros::Duration(0.2).sleep();
          }
        msgb.data = 0;
        sound_pub.publish(msgb);
        msg.linear.x = 0.2;
        msg.angular.z = 0.0;
        for (int i=0 ; i<tb; i++)
          {
            cmd_vel_pub.publish(msg);
            ros::Duration(0.2).sleep();
        }

      }
      case 3:
      {
      msg.linear.x = 0.0;
      msg.angular.z = -2.0;
      int ts=0;
      ts = rand() %20 + 6;
      msgb.data = 3;
      msgc.data = ts;
      playtime_pub.publish(msgc);
      sound_pub.publish(msgb);
      for (int i=0 ; i<ts; i++)
        {
          cmd_vel_pub.publish(msg);
          ros::Duration(0.2).sleep();
        }
      msgb.data = 0;
      sound_pub.publish(msgb);
      }

    }
  }

  return 0;
}
