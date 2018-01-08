# cwru_davinci_simulation
[![Build Status](https://travis-ci.com/cwru-robotics/cwru_davinci_simulation.svg?token=vmJpRsmqSqhkx1eZReGx&branch=master)](https://travis-ci.com/cwru-robotics/cwru_davinci_simulation)

This repository has the necessary source code and models for running a Gazebo simulation of the daVinci robot. The files present in this repository are meant for launching a gazebo simulation with the davinci tools. No tasks are launched here. For launching da Vinci tasks please refer to the [dvrk task example repository](https://github.com/cwru-robotics/cwru_davinci_example_tasks)

## Installation
You will need the Mimic plugin from the [cwru_robotics fork of roboticsgroup_gazebo_plugins](https://github.com/cwru-robotics/roboticsgroup_gazebo_plugins).
## Example usage

In order to launch the gazebo simulation with the davinci in lab configuration, please call the following roslaunch script. 
```bash
roslaunch cwru_davinci_simulation lab_configuration.launch
```
