## Voxel_SLAM(Docker-Container)

**Author : Xiaomo Wen $\qquad$ Date : 2025-09-17** 

### [notice before running] 
1.Bridges : Before running the code, there are two "bridges" which need you to prepare : "ROS1-ROS2 Bridge" and "Foxglove Bridge" . See [here](https://github.com/vishomework/ros2_driver) to install them.

2.When the ROS nodes are running,you can check topic in your terminal (Ubuntu22.04-ROS2): run "ros2 topic list" to check if the ROS1-ROS2 Bridge is working correctly ( See topics like "/livox/imu" or "/livox/lidar" ). And you can open the Foxglove to visualize the data.

3.Data bags : Click [here](https://onedrive.live.com/?redeem=aHR0cHM6Ly8xZHJ2Lm1zL2YvYy84YjFlZjE4YWU0MTgxYzhkL0VyRXpuaGtKelR4SmlMdUo4QVFER1MwQnZDeTZLc3VhV0YyRDZjbngwNjFHRVE%5FZT1kTVJTbGY&id=8B1EF18AE4181C8D%21s199e33b1cd09493c88bb89f00403192d&cid=8B1EF18AE4181C8D) to download the data bags from Microsoft OneDrive.

### Here are the four steps to running the algorithm:
#### 1.Clone the source code
        git clone 
#### 2.Create a docker-container
        cd .devcontainer 
        docker-compose build
        docker-compose up -d
        docker exec -it voxel_slam_ros bash 
        [notice] You can use "docker exec -it voxel_slam_ros fish" here, but when sourcing the ".bash" scripts, you should use "bass source" instead.
#### 3.Complie the algorithm
        // In container: "/workspace"
        source /opt/ros/noetic/setup.bash
        sudo cp /usr/local/lib/libmetis-gtsam.so /opt/ros/noetic/lib/
        catkin_make
        [notice] Maybe your system can't find the link file "libmetis-gtsam.so", don't worry, just copy it from "/opt/ros/noetic/lib/". Actually, you don't need to complie and install it again.
#### 4.Run ROS nodes
        // In container: "/workspace"
        [notice] If you don't want to execute the following two lines of code every time when you open the terminal, you can write them into "~/.bashrc".
        source /opt/ros/noetic/setup.bash
        source /devel/setup.bash

        // terminal 1:
        roscore
        // terminal 2:
        roslaunch voxel_slam vxlm_avia.launch
        // terminal 3: 
        rosbag play --clock bags/your-data-bag.bag --pause

        
