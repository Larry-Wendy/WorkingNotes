# MYX 项目开题讨论

## 一、需求分析

设计一款机器人平台，并开发应用示例，体现ESP32-S3芯片算力。



### **目标：**（1、2为基本目标，3、4可选）

1. 将MicroROS系统移植到ESP32-S3，开发一款移动系统主控平台
2. 开发一款移动平台（如小车），实现简单控制
3. 结合AI功能，开发有趣的应用示例
4. 增加结构和类型（机械臂、多足......）



### **要求：**

1. **成本低** -> 低于其他替代方案
2. **开发者友好** -> 文档、接口丰富
3. **（主控平台）通用性好** -> 与结构插接即可
4. **尽量榨干芯片算力**
5. **不要出现别的控制芯片** -> 不用舵机等
6. 结合AI -> 语音识别、图像识别、SLAM、路径规划......

## 二、背景调研

### 1. 之前做过的项目

| 项目（移动机电系统）          | 控制平台                                                     | 结构                       | 功能                 | 评价 |
| ----------------------------- | ------------------------------------------------------------ | -------------------------- | -------------------- | ---- |
| 跳跃机器人                    | STM32F1裸                                                    | 双轮、跳跃垫板、弹簧、凸轮 | 移动、跳跃、姿态控制 |      |
|                               |                                                              |                            |                      |      |
| 机械臂送餐小车                | Arduino Mega裸                                               | 见`小R科技小车`            |                      |      |
|                               |                                                              |                            |                      |      |
| 蛇形机械臂                    | Arduino Uno裸                                                |                            |                      |      |
|                               |                                                              |                            |                      |      |
| 多机器人小车系统              | Arduino Uno裸                                                | TurtleBot                  |                      |      |
|                               |                                                              |                            |                      |      |
| TowerTakeover竞赛小车         | [VEX Brain](https://www.vexrobotics.com/276-4810.html)(FPGA) |                            |                      |      |
|                               |                                                              |                            |                      |      |
| RoboCup场景的强化学习（仿真） | Unity3D                                                      |                            |                      |      |
|                               |                                                              |                            |                      |      |



### 2. 相关开源项目

#### 2.1 [TurtleBot](https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/)



<img src="https://www.turtlebot.com/assets/images/turtlebot_family.png" alt="TurtleBot Family" style="zoom: 67%;" />	

* 低成本的个人机器人工具包与开源软件

* TurtleBot 套件包括一个移动基座，2D/3D 距离传感器，笔记本电脑或单板电脑，以及 TurtleBot 安装硬件套件。
* [开源](https://github.com/ROBOTIS-GIT/turtlebot3.git)，用户还可以从 ROS wiki 下载 TurtleBot SDK。
* 易于购买，建造和组装，使用现成的消费品和零件，可以很容易地从标准的材料。
* 社区维护，许多大学正在使用 TurtleBot 来教授机器人入门课程

**功能：**

* 核心是 SLAM 和导航
* 可以通过笔记本电脑、控制器或基于 android 的智能手机进行远程控制；还可以在人们走进房间时跟着他们的腿走。
*  ROS 机械臂导航能力

#### 2.2 小R科技WIFI机械臂小车

<img src="https://gd3.alicdn.com/imgextra/i3/94674554/TB2duJ1ruuSBuNjSsziXXbq8pXa_!!94674554.jpg" alt="img" style="zoom:50%;" />

<img src="https://gd2.alicdn.com/imgextra/i3/94674554/O1CN01vKgOER1jVmQ3ljKzN_!!94674554-0-picasso.jpg" alt="img" style="zoom:50%;" />



![image-20220124205227845](/home/maoyuxuan/.config/Typora/typora-user-images/image-20220124205227845.png)



[机器人学算法py实现](https://github.com/AtsushiSakai/PythonRobotics.git)

### 三、概念设计

### 四、开发计划

