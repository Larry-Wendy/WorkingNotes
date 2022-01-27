# 1.27 工作日报
| 内容             | 时间                |
| ---------------- | ------------------- |
| FreeRTOS任务操作 | 10:30-12:00;        |
| FreeRTOS队列     | 14:00-15:30         |
| 激光雷达小车拆解 | 15:30-16:00         |
| FreeRTOS队列     | 16:00-17:00         |
| 尝试部署MicroROS | 17:00-18:30         |
| 构建ROS2         | 19:00-19:30         |
|                  | 10:08上班/19:08下班 |



## 七层网络结构

### 应用层

网络服务与最终用户的一个接口。

协议有：**HTTP FTP TFTP SMTP SNMP DNS TELNET HTTPS POP3 DHCP**

### 表示层

数据的表示、安全、压缩。（在五层模型里面已经合并到了应用层）

格式有，**JPEG、ASCll、EBCDIC、加密格式等** [2] 

### 会话层

建立、管理、终止会话。（在五层模型里面已经合并到了应用层）

**对应主机进程，指本地主机与远程主机正在进行的会话**

### 传输层

定义传输数据的协议端口号，以及流控和差错校验。

协议有：**TCP UDP，数据包一旦离开网卡即进入网络传输层**

### 网络层

进行逻辑地址寻址，实现不同网络之间的路径选择。

协议有：**ICMP IGMP IP（IPV4 IPV6）**

### 数据链路层

建立逻辑连接、进行硬件地址寻址、差错校验 [3] 等功能。（由底层网络定义协议）

将比特组合成字节进而组合成帧，用MAC地址访问介质，错误发现但不能纠正。

### 物理层

建立、维护、断开物理连接。（由底层网络定义协议）

![这里写图片描述](https://img-blog.csdn.net/20170822222325781?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvU2lsZW5jZU9P/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 部署MicroROS

### idf-component-microros 使用说明

* 安装依赖环境

`get-idf`

`pip3 install catkin_pkg lark-parser empy colcon-common-extensions importlib-resources`

* clone[组件](https://github.com/micro-ROS/micro_ros_espidf_component.git)到esp/esp-idf/component
* 重新get-idf
* 测试示例程序int32_publisher
  * set-target esp32s3报错：工具链不匹配
    * 关闭终端重开
    * rm -rf build/ sdkconfig

### 在计算机上安装ROS2

ros2 foxy 版本默认需要ubuntu 20.04支持，因此在 18.04 上无法直接通过 apt 安装，需要从源码去编译。

参考：https://zhuanlan.zhihu.com/p/364745633

* 安装依赖
* 下载源码
* 编译源码
  * 报错：CMake Error at CMakeLists.txt:7 (cmake_minimum_required):
      CMake 3.11 or higher is required.  You are running version 3.10.2
  * 考虑更新CMake版本 现有：cmake version 3.10.2
  * 
