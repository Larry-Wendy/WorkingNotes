# 1.19工作日报
| 内容                                              | 时间        |
| ------------------------------------------------- | ----------- |
| 安装VS Code IDE                                   | 11:00-12:00 |
| 学习用vscode烧录blink并监视                       | 14:00-15:00 |
| 了解idf debugger                                  | 15:00-15:30 |
| 尝试用vscode建立新的工程                          | 15:00-16:00 |
| 配置Eclipse                                       | 16:00-17:00 |
| 学习用Eclipse烧录、监视                           | 17:00-17:30 |
| 读blink_example                                   | 17:30-18:00 |
| 看相关项目(moonlight)、比赛(中国青少年机器人大赛) | 18:00-19:00 |
| 整理笔记，梳理简单工程创建流程                    | 19:00-20:30 |

***

### 一、VS Code IDE

[VSCode参考资料目录](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/get-started/vscode-setup.html)

[ESP-IDF for VSCode使用指南](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/toc.md)

[Terminal输出解释](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32s3/api-reference/system/log.html)

| 操作                | 详细步骤                                                     |
| ------------------- | ------------------------------------------------------------ |
| 安装VSCode          | 下载VSCode                                                   |
| 安装ESP-IDF         | 在拓展市场搜索`esp-idf`并安装                                |
|                     | `F1`->`ESP-IDF: Configure ESP-IDF extension`                 |
|                     | USE EXISTING SETUP                                           |
|                     | *修改python路径为python3，File->Add Floder to Workspace*     |
|                     | 安装成功                                                     |
| 复制一个example工程 | `ESP-IDF: Show Examples Projects`                            |
|                     | choose idf path                                              |
|                     | choose a example -> create project using example `xxx`       |
|                     | choose the copy path                                         |
| Build               | 打开工程                                                     |
|                     | set device target to `esp32s3` (底栏)                        |
|                     | ESP-IDF: Build your project                                  |
| Flash               | set device port                                              |
|                     | ESP-IDF: Flash (UART) your project <br />or ESP-IDF: Flash (with JTag) |
| Monitor             | 底栏                                                         |
| Debug               | ESP-IDF: Select OpenOCD Board Configuration                  |
|                     | F5                                                           |
|                     | View -> Output -> OpenOCD.                                   |
|                     | **报错**：需要用调试器，小板子没引出接口，以后需要再学习     |
|                     | 先用打印输出，debugger先不用                                 |
| 创建一个新工程      |                                                              |



### 二、Eclipse

[Eclipse教程](https://github.com/espressif/idf-eclipse-plugin/blob/master/README_CN.md)

| 操作           | 详细步骤                                                |
| -------------- | ------------------------------------------------------- |
| 安装Eclipse    | 解压后双击exe安装                                       |
|                | 确认依赖资源                                            |
| 安装插件       | Installing IDF Plugin using update site URL             |
| 安装ESP-IDF    | 无反应                                                  |
| 安装IDF Tools  | `Espressif` > `ESP-IDF Tools Manager` > `Install Tools` |
|                | provide paths                                           |
| 创建一个新项目 | `File` > `New` > `Espressif IDF Project`                |
|                | 可以选择是否从模板创建                                  |
|                | 确认芯片                                                |
| Build          | 第一个图标                                              |
| 编译并烧录     | 第二个图标                                              |
| 监视           | 打开Terminal                                            |
| 设置           | 双击sdkconfig文件                                       |
|                | `Ctrl`+`S` 保存                                         |

![img](https://github.com/espressif/idf-eclipse-plugin/raw/master/docs/images/9_cmake_build.png)



### 三、手动安装Espressif IoT Development Framework

| 操作             | 步骤                                                         |
| ---------------- | ------------------------------------------------------------ |
| 下载依赖资源     | sudo apt-get install git wget flex bison gperf python3 python3-pip python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0 |
| 下载ESP-IDF      | mkdir -p ~/esp<br/>cd ~/esp<br/>git clone --recursive https://github.com/espressif/esp-idf.git |
| 下载相关工具     | cd ~/esp/esp-idf<br/>./install.sh esp32s3                    |
|                  | cd ~/esp/esp-idf<br/>export IDF_GITHUB_ASSETS="dl.espressif.com/github_assets"<br/>./install.sh |
| **设置环境变量** | . $HOME/esp/esp-idf/export.sh                                |
| *或*             | *在`/dev/bash.bashrc`中加入一行`alias get-idf='. $HOME/esp/esp-idf/export.sh'`以创建别名* |
|                  | **get-idf** （每个终端都要输一次）                           |



### 四、创建一个简单的工程

*编译环境选择：~~VS Code &~~ ESP-IDF*

1. 从hello_world创建工程

cp /home/maoyuxuan/esp/esp-idf/examples/get-started/hello_world my_new_project2 -r

2. get-idf

3. cd my_new_project2

4. idf.py set-target esp32s3

5. idf.py -p /dev/ttyUSB1 flash monitor

   *Ctrl + ]* 退出



