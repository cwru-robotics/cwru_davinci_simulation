/*

Copyright (C) 2017 Tom Shkurti

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include <vector>

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>

// These names come from the way the joints are referred to in the simulator.
// They are substantially more compact, and no LESS obtuse.
static ros::Publisher j1_1_0;
static ros::Publisher j1_2_0;
static ros::Publisher j1_2_1;
static ros::Publisher j1_2_2;
static ros::Publisher j1_2_3;
static ros::Publisher j1_2_4;
static ros::Publisher j1_2_5;
static ros::Publisher j1_3_0;
static ros::Publisher j1_4_0;
static ros::Publisher j1_5_0;
static ros::Publisher j1_6_0;
static ros::Publisher j1_7_0;
static ros::Publisher j1_7_m;

static ros::Publisher j2_1_0;
static ros::Publisher j2_2_0;
static ros::Publisher j2_2_1;
static ros::Publisher j2_2_2;
static ros::Publisher j2_2_3;
static ros::Publisher j2_2_4;
static ros::Publisher j2_2_5;
static ros::Publisher j2_3_0;
static ros::Publisher j2_4_0;
static ros::Publisher j2_5_0;
static ros::Publisher j2_6_0;
static ros::Publisher j2_7_0;
static ros::Publisher j2_7_m;

void cb1(const sensor_msgs::JointState::ConstPtr& incoming)
{
  std::vector<double> positions = incoming->position;

  std_msgs::Float64 m1_1_0;
  std_msgs::Float64 m1_2_0;
  std_msgs::Float64 m1_2_1;
  std_msgs::Float64 m1_2_2;
  std_msgs::Float64 m1_2_3;
  std_msgs::Float64 m1_2_4;
  std_msgs::Float64 m1_2_5;
  std_msgs::Float64 m1_3_0;
  std_msgs::Float64 m1_4_0;
  std_msgs::Float64 m1_5_0;
  std_msgs::Float64 m1_6_0;
  std_msgs::Float64 m1_7_0;
  std_msgs::Float64 m1_7_m;

  m1_1_0.data = positions[0];
  m1_2_0.data = positions[1];
  m1_2_1.data = positions[1];
  m1_2_2.data = positions[1];
  m1_2_3.data = -positions[1];
  m1_2_4.data = -positions[1];
  m1_2_5.data = positions[1];
  m1_3_0.data = positions[2];
  m1_4_0.data = positions[3];
  m1_5_0.data = positions[4];
  m1_6_0.data = positions[5] - 0.5 * positions[6];
  m1_7_0.data = positions[6];
  m1_7_m.data = -positions[6];

  j1_1_0.publish(m1_1_0);
  j1_2_0.publish(m1_2_0);
  j1_2_1.publish(m1_2_1);
  j1_2_2.publish(m1_2_2);
  j1_2_3.publish(m1_2_3);
  j1_2_4.publish(m1_2_4);
  j1_2_5.publish(m1_2_5);
  j1_3_0.publish(m1_3_0);
  j1_4_0.publish(m1_4_0);
  j1_5_0.publish(m1_5_0);

  j1_6_0.publish(m1_6_0);
  j1_7_0.publish(m1_7_0);
  j1_7_m.publish(m1_7_m);
}

void cb2(const sensor_msgs::JointState::ConstPtr& incoming)
{
  std::vector<double> positions = incoming->position;

  std_msgs::Float64 m2_1_0;
  std_msgs::Float64 m2_2_0;
  std_msgs::Float64 m2_2_1;
  std_msgs::Float64 m2_2_2;
  std_msgs::Float64 m2_2_3;
  std_msgs::Float64 m2_2_4;
  std_msgs::Float64 m2_2_5;
  std_msgs::Float64 m2_3_0;
  std_msgs::Float64 m2_4_0;
  std_msgs::Float64 m2_5_0;
  std_msgs::Float64 m2_6_0;
  std_msgs::Float64 m2_7_0;
  std_msgs::Float64 m2_7_m;

  m2_1_0.data = positions[0];
  m2_2_0.data = positions[1];
  m2_2_1.data = positions[1];
  m2_2_2.data = positions[1];
  m2_2_3.data = -positions[1];
  m2_2_4.data = -positions[1];
  m2_2_5.data = positions[1];
  m2_3_0.data = positions[2];
  m2_4_0.data = positions[3];
  m2_5_0.data = positions[4];
  m2_6_0.data = positions[5] - 0.5 * positions[6];
  m2_7_0.data = positions[6];
  m2_7_m.data = -positions[6];

  j2_1_0.publish(m2_1_0);
  j2_2_0.publish(m2_2_0);
  j2_2_1.publish(m2_2_1);
  j2_2_2.publish(m2_2_2);
  j2_2_3.publish(m2_2_3);
  j2_2_4.publish(m2_2_4);
  j2_2_5.publish(m2_2_5);
  j2_3_0.publish(m2_3_0);
  j2_4_0.publish(m2_4_0);
  j2_5_0.publish(m2_5_0);
  j2_6_0.publish(m2_6_0);
  j2_7_0.publish(m2_7_0);
  j2_7_m.publish(m2_7_m);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "davinci_to_sim");
  ros::NodeHandle nh;

  j1_1_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint1_position_controller/command", 1, true);
  j1_2_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_position_controller/command", 1, true);
  j1_2_1 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_1_position_controller/command", 1, true);
  j1_2_2 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_2_position_controller/command", 1, true);
  j1_2_3 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_3_position_controller/command", 1, true);
  j1_2_4 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_4_position_controller/command", 1, true);
  j1_2_5 = nh.advertise<std_msgs::Float64>("/davinci/one_joint2_5_position_controller/command", 1, true);
  j1_3_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint3_position_controller/command", 1, true);
  j1_4_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint4_position_controller/command", 1, true);
  j1_5_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint5_position_controller/command", 1, true);
  j1_6_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint6_position_controller/command", 1, true);
  j1_7_0 = nh.advertise<std_msgs::Float64>("/davinci/one_joint7_position_controller/command", 1, true);
  j1_7_m = nh.advertise<std_msgs::Float64>("/davinci/one_joint7_position_controller_mimic/command", 1, true);

  j2_1_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint1_position_controller/command", 1, true);
  j2_2_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_position_controller/command", 1, true);
  j2_2_1 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_1_position_controller/command", 1, true);
  j2_2_2 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_2_position_controller/command", 1, true);
  j2_2_3 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_3_position_controller/command", 1, true);
  j2_2_4 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_4_position_controller/command", 1, true);
  j2_2_5 = nh.advertise<std_msgs::Float64>("/davinci/two_joint2_5_position_controller/command", 1, true);
  j2_3_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint3_position_controller/command", 1, true);
  j2_4_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint4_position_controller/command", 1, true);
  j2_5_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint5_position_controller/command", 1, true);
  j2_6_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint6_position_controller/command", 1, true);
  j2_7_0 = nh.advertise<std_msgs::Float64>("/davinci/two_joint7_position_controller/command", 1, true);
  j2_7_m = nh.advertise<std_msgs::Float64>("/davinci/two_joint7_position_controller_mimic/command", 1, true);

  ros::Subscriber sub1 = nh.subscribe("/dvrk/PSM2/set_position_joint", 10, cb1);
  ros::Subscriber sub2 = nh.subscribe("/dvrk/PSM1/set_position_joint", 10, cb2);

  while (ros::ok())
  {
    ros::spinOnce();
  }

  return 0;
}
