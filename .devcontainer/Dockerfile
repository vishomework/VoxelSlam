# 使用 Ubuntu 20.04 基础镜像 (ROS Noetic 官方支持)
FROM ubuntu:20.04

# 设置环境变量避免时区交互提示
ENV DEBIAN_FRONTEND=noninteractive

# 更换国内镜像源(阿里云)
RUN sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list && \
    sed -i 's/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list

# 安装核心依赖项
RUN apt-get update && apt-get install -y \
    git \
    cmake \
    build-essential \
    libeigen3-dev \
    libboost-all-dev \
    libopencv-dev \
    python3-dev \
    python3-pip \
    wget \
    fish \
    && rm -rf /var/lib/apt/lists/*

# 创建非 root 用户 
ARG USERNAME=SummerWen
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# 安装 ROS Noetic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu focal main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN apt-get update && apt-get install -y \
    ros-noetic-desktop-full \
    ros-noetic-pcl-ros \
    ros-noetic-tf2-sensor-msgs \
    ros-noetic-libg2o \
    && rm -rf /var/lib/apt/lists/*
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

# 安装额外依赖 (PCL, GTSAM, etc.)
# 这里gtsam要求特定版本4.0.3 需要手动去下压缩包然后解压
# 目录必须是catkin_ws同级目录 编译先make install gtsam 然后切换到catkin_ws目录下catkin_make编译
RUN apt-get update && apt-get install -y \
    libpcl-dev \
    libproj-dev \
    libtbb-dev \
    libglm-dev \
    libglfw3-dev \
    libglew-dev \
    && rm -rf /var/lib/apt/lists/*

# 安装 Python 依赖
RUN pip3 install \
    numpy \
    open3d \
    pybind11

# 安装 VSCode 扩展依赖
RUN apt-get update && apt-get install -y \
    gdb \
    openssh-server \
    && rm -rf /var/lib/apt/lists/*

# 创建工作目录
RUN mkdir -p /resource/Livox_SDK2_ws/src
RUN mkdir -p /resource/livox_ros_driver_ws/src
RUN mkdir -p /workspace/src
WORKDIR /workspace/src

# 克隆 Voxel-SLAM 和依赖库
RUN git clone https://github.com/hku-mars/Voxel-SLAM.git
RUN git clone https://github.com/SMRT-AIST/fast_gicp.git
RUN git clone https://github.com/koide3/ndt_omp.git

# 构建并安装 Livox-SDK2：指定安装前缀
WORKDIR /resource/Livox_SDK2_ws/src
RUN git clone https://github.com/Livox-SDK/Livox-SDK2.git
RUN cd ./Livox-SDK2 && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local && \ 
    make -j $(nproc) && \
    make install  

# 构建并安装 Livox-ros-driver：
WORKDIR /resource/livox_ros_driver_ws/src
RUN git clone https://github.com/Livox-SDK/livox_ros_driver.git
RUN cp -r /resource/livox_ros_driver_ws /workspace/src

# 复制 gtsam-4.0.3 到指定目录
WORKDIR /resource

# 下载并解压 gtsam
RUN wget -qO- https://github.com/borglab/gtsam/archive/refs/tags/4.0.3.tar.gz | tar xz 
# 构建并安装 gtsam-4.0.3
RUN cd gtsam-4.0.3 && mkdir build && cd build && cmake .. && make check && make install

# 设置环境变量
RUN echo "source /workspace/devel/setup.bash" >> ~/.bashrc

WORKDIR /workspace
#RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && \
#                catkin_make -DCMAKE_BUILD_TYPE=Release"
RUN chown $USER_UID:$USER_GID /workspace

SHELL ["/usr/bin/fish", "-c"]
USER $USERNAME