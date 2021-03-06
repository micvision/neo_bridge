//
// Created by huang on 17-12-7.
//

#ifndef NEO_BRIDGE_CROSNODE_H
#define NEO_BRIDGE_CROSNODE_H

#include "CShareMem.h"
#include "CThreadBase.h"
#include "packet.h"
#include <neo_bridge/CRosNode.h>
#include <neoslam_sdk/TypePacket_RobotStatus.h>

#include <ros/ros.h>
#include <ros/time.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/tf.h>
#include <tf2_msgs/TFMessage.h>
#include <tf/transform_listener.h>
#include <nav_msgs/Path.h>
#include <neoslam_sdk/Type_Pose.h>

typedef struct {
    bool isPub_Goal;
    bool isPub_InitPose;
    bool isPub_CancelGoal;
}ROS_PUB_FLAG;

class CRosNode:public CThreadBase
{
public:
    CRosNode();
    void Run();

    static void PopMoveGoal(geometry_msgs::PoseStamped goal);
    static void PopInitialPose(geometry_msgs::PoseStamped pose);
    static void PopCmdVel(float x,float y,float z);
    static void PopCancelGoal();
    static void GetGlobalPath(nav_msgs::Path &out);
    static void GetMap(nav_msgs::OccupancyGrid &out);
    static void GetLidar(sensor_msgs::LaserScan &out,Neo_Type::POSE &pose);
    static bool IsAction();
    static bool waitForAction();
    static bool waitForUnAction();
    void cbMap(const nav_msgs::OccupancyGrid::ConstPtr &msg);
    void cbMoveStatus(const actionlib_msgs::GoalStatusArray &msg);
    void cbScan(const sensor_msgs::LaserScan &msg);
    void cbPath(const nav_msgs::Path &msg);
    void cbTF(const tf2_msgs::TFMessage &msg);

    ros::NodeHandle nh;
    ros::NodeHandle nhp;
    ros::Subscriber sub_map_;
    ros::Subscriber sub_odom_;
    ros::Subscriber sub_moveStatus_;
    ros::Subscriber sub_scan_;
    ros::Subscriber sub_path_;
    ros::Subscriber sub_tf_;
    ros::Publisher  pub_goal_;
    ros::Publisher  pub_initialPose_;
    ros::Publisher  pub_cancelGoal_;

    tf::TransformListener *tf_listener;

    static nav_msgs::OccupancyGrid map_base_;
    static sensor_msgs::LaserScan scan_;
    static nav_msgs::Path path_;
    static Neo_Packet::ROBOTSTATUS_PACKET_RESPONSE robot_status;
    static Neo_Packet::ROBOTSTATUS_PACKET_RESPONSE laser_pose;
    static bool isAction;
};

#endif //NEO_BRIDGE_CROSNODE_H
