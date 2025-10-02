FROM osrf/ros:noetic-desktop-full

ARG USERNAME=yutou
ARG USER_UID=1000
ARG USER_GID=1000

ENV DEBIAN_FRONTEND=noninteractive \
    LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8

# 预先设置地区信息，避免交互式提示
RUN apt-get update && \
    apt-get install -y locales && \
    locale-gen en_US.UTF-8 && \
    update-locale LANG=en_US.UTF-8

# 安装基本工具和依赖
RUN apt-get update && \
    apt-get install -y \
    nautilus \
    gedit \
    cmake \
    git \
    libboost-all-dev \
    build-essential \
    libtbb-dev \
    software-properties-common \
    sudo && \
    rm -rf /var/lib/apt/lists/*

# 添加 GTSAM PPA 仓库并安装
RUN add-apt-repository ppa:borglab/gtsam-release-4.0 -y && \
    apt-get update && \
    apt-get install -y libgtsam-dev libgtsam-unstable-dev && \
    rm -rf /var/lib/apt/lists/*

# 创建用户并配置 sudo 权限
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER $USERNAME
WORKDIR /home/$USERNAME

# 设置环境变量
ENV ROS_DISTRO_BASH="/opt/ros/noetic/setup.bash" \
    CATKIN_WS="/home/$USERNAME/catkin_ws"

# 创建并初始化 catkin 工作空间
RUN mkdir -p $CATKIN_WS/src && \
    /bin/bash -c "source $ROS_DISTRO_BASH && cd $CATKIN_WS && catkin_make"

# 添加到 bashrc
RUN echo "source $ROS_DISTRO_BASH" >> ~/.bashrc && \
    echo "source $CATKIN_WS/devel/setup.bash" >> ~/.bashrc

# 安装 Livox SDK 和驱动
RUN mkdir -p ~/packages && cd ~/packages && \
    # 安装 Livox SDK (第一代)
    git clone https://github.com/Livox-SDK/Livox-SDK.git && \
    cd Livox-SDK && mkdir -p build && cd build && \
    cmake .. && make -j$(nproc) && sudo make install && \
    # 安装 Livox SDK2 (第二代)
    cd ~/packages && \
    git clone https://github.com/Livox-SDK/Livox-SDK2.git && \
    cd Livox-SDK2 && mkdir -p build && cd build && \
    cmake .. && make -j$(nproc) && sudo make install && \
    # 安装 livox_ros_driver (ROS1 驱动)
    cd ~/packages && \
    mkdir -p $CATKIN_WS/src && \
    git clone https://github.com/Livox-SDK/livox_ros_driver.git $CATKIN_WS/src/livox_ros_driver && \
    /bin/bash -c "source $ROS_DISTRO_BASH && cd $CATKIN_WS && catkin_make" && \
    # 安装 livox_ros_driver2
    git clone https://github.com/Livox-SDK/livox_ros_driver2.git $CATKIN_WS/src/livox_ros_driver2 && \
    /bin/bash -c "source $ROS_DISTRO_BASH && cd $CATKIN_WS/src/livox_ros_driver2 && ./build.sh ROS1" && \
    # 安装 Voxel-SLAM 和转换工具
    cd $CATKIN_WS/src && \
    git clone https://github.com/hku-mars/Voxel-SLAM.git && \
    git clone https://github.com/wyq123-star/livox_lidar_rosbag_converter.git && \
    # 构建所有包
    /bin/bash -c "source $ROS_DISTRO_BASH && cd $CATKIN_WS && catkin_make"

# 设置默认命令
CMD ["/bin/bash", "-c", "source $ROS_DISTRO_BASH && source $CATKIN_WS/devel/setup.bash && roslaunch all run.launch"]
