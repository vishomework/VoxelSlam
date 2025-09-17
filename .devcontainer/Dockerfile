FROM osrf/ros:noetic-desktop-full

ARG USERNAME=yutou
ARG USER_UID=1000
ARG USER_GID=1000

ENV DEBIAN_FRONTEND=noninteractive

# 预先设置地区信息，避免交互式提示
RUN apt-get update && \
    apt-get install -y locales && \
    locale-gen en_US.UTF-8 && \
    update-locale LANG=en_US.UTF-8

ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8

# Install basic tools and dependencies
RUN apt-get update && \
    apt-get install -y \
    nautilus \
    gedit \
    cmake \
    git \
    libboost-all-dev \
    build-essential \
    libtbb-dev && \
    rm -rf /var/lib/apt/lists/*

# Add GTSAM PPA repository and install
RUN apt-get update && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:borglab/gtsam-release-4.0 -y && \
    apt-get update && \
    apt-get install -y libgtsam-dev libgtsam-unstable-dev && \
    rm -rf /var/lib/apt/lists/*


# Create user and configure sudo privileges
RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    apt-get update && \
    apt-get install -y sudo && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER $USERNAME
WORKDIR /home/$USERNAME

ENV LIVOX_1="/home/yutou/voxelslam/packages/LIVOX_1/ws_livox/devel/setup.bash"
ENV livox_2="/home/yutou/voxelslam/packages/livox_2/ws_livox/devel/setup.bash"
ENV ROS_DISTRO_BASH="/opt/ros/noetic/setup.bash"
ENV CATKIN_WS_BASH="/home/yutou/voxelslam/ros_ws/devel/setup.bash"

RUN echo "source $ROS_DISTRO_BASH" >> /home/$USERNAME/.bashrc && \
    echo "source $CATKIN_WS_BASH" >> /home/$USERNAME/.bashrc 
    # echo "source $livox_2" >> /home/$USERNAME/.bashrc && \
    # echo "source $LIVOX_1" >> /home/$USERNAME/.bashrc 

# CMD ["/bin/bash"]
CMD ["/bin/bash", "-c", "source ${ROS_DISTRO_BASH} && source ${CATKIN_WS_BASH} && roslaunch all run.launch"]