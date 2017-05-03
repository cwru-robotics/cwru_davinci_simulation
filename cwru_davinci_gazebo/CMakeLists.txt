cmake_minimum_required(VERSION 2.8.3)
project(cwru_davinci_gazebo)

#Some minor change.

find_package(catkin REQUIRED COMPONENTS roscpp roslint)

catkin_package(
        # INCLUDE_DIRS
	# DEPENDS
	# LIBRARIES
	CATKIN_DEPENDS roscpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${catkin_INCLUDE_DIRS})

roslint_cpp()

roslint_add_test()

# Executables
add_executable(sim_to_davinci src/sim_to_davinci.cpp)
add_executable(davinci_to_sim src/davinci_to_sim.cpp)

#Link Executables
target_link_libraries(sim_to_davinci ${catkin_LIBRARIES})
target_link_libraries(davinci_to_sim ${catkin_LIBRARIES})
