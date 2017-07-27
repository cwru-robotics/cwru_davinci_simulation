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
#include <sensor_msgs/JointState.h>

static ros::Publisher joint_publisher_1;
static ros::Publisher joint_publisher_2;

void cb(const sensor_msgs::JointState::ConstPtr& incoming)
{
  std::vector<double> pos = incoming->position;
  std::vector<double> vel = incoming->velocity;
  std::vector<double> eff = incoming->effort;

  sensor_msgs::JointState output_1;
  sensor_msgs::JointState output_2;

  output_1.header = incoming->header;
  output_2.header = incoming->header;

  output_1.name = {
    "outer_yaw"     ,
    "outer_pitch"     ,
    "outer_insertion"   ,
    "outer_roll"      ,
    "outer_wrist_pitch"   ,
    "outer_wrist_yaw"   ,
    "jaw"
  };
  output_2.name = {
    "outer_yaw"     ,
    "outer_pitch"     ,
    "outer_insertion"   ,
    "outer_roll"      ,
    "outer_wrist_pitch"   ,
    "outer_wrist_yaw"   ,
    "jaw"
  };

  output_1.position.push_back(pos[12]);
  output_1.position.push_back(pos[1]);
  output_1.position.push_back(pos[0]);
  output_1.position.push_back(pos[7]);
  output_1.position.push_back(pos[10]);
  output_1.position.push_back(pos[11]);
  output_1.position.push_back(pos[8]);

  output_2.position.push_back(pos[25]);
  output_2.position.push_back(pos[14]);
  output_2.position.push_back(pos[13]);
  output_2.position.push_back(pos[20]);
  output_2.position.push_back(pos[23]);
  output_2.position.push_back(pos[24]);
  output_2.position.push_back(pos[21]);

  output_1.velocity.push_back(vel[12]);
  output_1.velocity.push_back(vel[1]);
  output_1.velocity.push_back(vel[0]);
  output_1.velocity.push_back(vel[7]);
  output_1.velocity.push_back(vel[10]);
  output_1.velocity.push_back(vel[11]);
  output_1.velocity.push_back(vel[8]);

  output_2.velocity.push_back(vel[25]);
  output_2.velocity.push_back(vel[14]);
  output_2.velocity.push_back(vel[13]);
  output_2.velocity.push_back(vel[20]);
  output_2.velocity.push_back(vel[23]);
  output_2.velocity.push_back(vel[24]);
  output_2.velocity.push_back(vel[21]);

  output_1.effort.push_back(eff[12]);
  output_1.effort.push_back(eff[1]);
  output_1.effort.push_back(eff[0]);
  output_1.effort.push_back(eff[7]);
  output_1.effort.push_back(eff[10]);
  output_1.effort.push_back(eff[11]);
  output_1.effort.push_back(eff[8]);

  output_2.effort.push_back(eff[25]);
  output_2.effort.push_back(eff[14]);
  output_2.effort.push_back(eff[13]);
  output_2.effort.push_back(eff[20]);
  output_2.effort.push_back(eff[23]);
  output_2.effort.push_back(eff[24]);
  output_2.effort.push_back(eff[21]);

  joint_publisher_1.publish(output_1);
  joint_publisher_2.publish(output_2);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sim_to_davinci");
  ros::NodeHandle nh;

  joint_publisher_1 = nh.advertise<sensor_msgs::JointState>("/dvrk/PSM1/joint_states", 1, true);
  joint_publisher_2 = nh.advertise<sensor_msgs::JointState>("/dvrk/PSM2/joint_states", 1, true);

  ros::Subscriber state_sub = nh.subscribe("/davinci/joint_states", 10, cb);

  while (ros::ok())
  {
    ros::spinOnce();
  }

  return 0;
}
