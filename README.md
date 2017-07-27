# cwru_davinci_simulation
[![Build Status](https://travis-ci.com/cwru-robotics/cwru_davinci_simulation.svg?token=vmJpRsmqSqhkx1eZReGx&branch=master)](https://travis-ci.com/cwru-robotics/cwru_davinci_simulation)
This repository has the necessary source code and models for running a Gazebo simulation of the daVinci robot.

## Example usage
`roslaunch cwru_davinci_gazebo sticky_davinci_gazebo.launch`

To launch a Gazebo simulation with arms positioned consistent with a typical configuration (our "positon yellow"), run:
`roslaunch cwru_davinci_gazebo davinci_yellow_config.launch`

Additional example launch files can be found in the cwru_davinci_sim_examples package:

`roslaunch cwru_davinci_sim_examples davinci_with_model.launch`: World with spawned models.
