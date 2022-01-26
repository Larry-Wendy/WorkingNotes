# 1.25 工作日报
| 内容                     | 时间                    |
| ------------------------ | ----------------------- |
| 整理背景项目             | 11:30-12:30             |
| 了解ROS、ROS2与Micro-ROS | 14:00-15:00             |
| 了解ROS(2)常用工具       | 15:00-16:00             |
| 了解FreeRTOS             | 16:00-18:00;19:00-20:00 |
|                          | 11:07上班/20:10下班     |



***

## 一、FreeRTOS

### 1. 优点

* 用户无需关心时间信息

* 模块化、可拓展性强

* 效率高

* 中断进程更短

### 2. 核心功能

<img src="https://pic2.zhimg.com/v2-228540dcb8d56250a521c1b342514275_b.jpg" alt="img" style="zoom:50%;" />

ESP-IDF **FreeRTOS** is based on Vanilla FreeRTOS v10.4.3

#### 任务管理

**创建指定affinity的任务并准备运行**

> BaseType_t **xTaskCreatePinnedToCore**(TaskFunction_t *pvTaskCode*, const char *const *pcName*, const uint32_t *usStackDepth*, void *const *pvParameters*, UBaseType_t *uxPriority*, TaskHandle_t *const *pvCreatedTask*, const BaseType_t *xCoreID*)

* `pvTaskCode`：指向任务入口函数的指针。任务必须实现永不返回（即连续循环），或者应该使用 vTaskDelete 函数终止。
* `pcName`：任务的描述性名称。这主要是为了方便调试。由 configMAX_TASK_NAME_LEN 定义的最大长度 - 默认为 16。
* `usStackDepth`：指定为字节数的任务堆栈的大小。请注意，这与香草不同**自由实时操作系统**.
* `pvParameters`：将用作正在创建的任务的参数的指针。
* `uxPriority`：任务应该运行的优先级。包含 MPU 支持的系统可以通过设置优先级参数的位 portPRIVILEGE_BIT 来选择在特权（系统）模式下创建任务。例如，要创建优先级为 2 的特权任务，应将 uxPriority 参数设置为 (2 | portPRIVILEGE_BIT)。
* `pvCreatedTask`：用于传回一个句柄，通过该句柄可以引用创建的任务。
* `xCoreID`：如果值为 tskNO_AFFINITY，则创建的任务不会固定到任何 CPU，调度程序可以在任何可用的内核上运行它。值 0 或 1 表示任务应固定到的 CPU 的索引号。指定大于 (portNUM_PROCESSORS - 1) 的值将导致函数失败。



**创建新任务并准备运行**

> static BaseType_t **xTaskCreate**(TaskFunction_t pvTaskCode, const char *constpcName, const uint32_t usStackDepth, void *const pvParameters, UBaseType_t uxPriority, TaskHandle_t *const pxCreatedTask)

- `pvTaskCode`：指向任务入口函数的指针。任务必须实现永不返回（即连续循环），或者应该使用 vTaskDelete 函数终止。
- `pcName`：任务的描述性名称。这主要是为了方便调试。由 configMAX_TASK_NAME_LEN 定义的最大长度 - 默认为 16。
- `usStackDepth`：指定为字节数的任务堆栈的大小。请注意，这与香草不同**自由实时操作系统**.
- `pvParameters`：将用作正在创建的任务的参数的指针。
- `uxPriority`：任务应该运行的优先级。包含 MPU 支持的系统可以通过设置优先级参数的位 portPRIVILEGE_BIT 来选择在特权（系统）模式下创建任务。例如，要创建优先级为 2 的特权任务，应将 uxPriority 参数设置为 (2 | portPRIVILEGE_BIT)。
- `pvCreatedTask`：用于传回一个句柄，通过该句柄可以引用创建的任务。

如果程序使用线程局部变量（用“__thread”关键字指定的变量），那么它们的存储空间将分配在任务的堆栈上。



**创建具有指定亲和性的新任务。**

> TaskHandle_t **xTaskCreateStaticPinnedToCore**(TaskFunction_t pvTaskCode, const char *constpcName, const uint32_t ulStackDepth, void *constpvParameters, UBaseType_t uxPriority, StackType_t *const pxStackBuffer, StaticTask_t *constpxTaskBuffer, const BaseType_t xCoreID)

- `pvTaskCode`：指向任务入口函数的指针。任务必须实现永不返回（即连续循环），或者应该使用 vTaskDelete 函数终止。
- `pcName`：任务的描述性名称。这主要是为了方便调试。字符串的最大长度由 configMAX_TASK_NAME_LEN 定义**自由实时操作系统**配置.h。
- `ulStackDepth`：指定为字节数的任务堆栈的大小。请注意，这与香草不同**自由实时操作系统**.
- `pvParameters`：将用作正在创建的任务的参数的指针。
- `uxPriority`：任务运行的优先级。
- `pxStackBuffer`: 必须指向至少有 ulStackDepth 索引的 StackType_t 数组 - 然后该数组将用作任务的堆栈，无需动态分配堆栈。
- `pxTaskBuffer`: 必须指向一个StaticTask_t 类型的变量，该变量将用于保存任务的数据结构，无需动态分配内存。
- `xCoreID`：如果值为 tskNO_AFFINITY，则创建的任务不会固定到任何 CPU，调度程序可以在任何可用的内核上运行它。值 0 或 1 表示任务应固定到的 CPU 的索引号。指定大于 (portNUM_PROCESSORS - 1) 的值将导致函数失败。



**创建一个新任务并将其添加到准备运行的任务列表中**

> staticTaskHandle_t xTaskCreateStatic(TaskFunction_t pvTaskCode, const char *const pcName, const uint32_t ulStackDepth, void *const pvParameters, UBaseType_t uxPriority, StackType_t *const puxStackBuffer, StaticTask_t *const pxTaskBuffer)

如果使用 xTaskCreateStatic() 创建任务，则应用程序编写者必须提供所需的内存。因此，xTaskCreateStatic() 允许在不使用任何动态内存分配的情况下创建任务。

- `pvTaskCode`：指向任务入口函数的指针。任务必须实现永不返回（即连续循环），或者应该使用 vTaskDelete 函数终止。
- `pcName`：任务的描述性名称。这主要是为了方便调试。字符串的最大长度由 configMAX_TASK_NAME_LEN 定义**自由实时操作系统**配置.h。
- `ulStackDepth`：指定为字节数的任务堆栈的大小。请注意，这与香草不同**自由实时操作系统**.
- `pvParameters`：将用作正在创建的任务的参数的指针。
- `uxPriority`：任务运行的优先级。
- `pxStackBuffer`: 必须指向至少有 ulStackDepth 索引的 StackType_t 数组 - 然后该数组将用作任务的堆栈，无需动态分配堆栈。
- `pxTaskBuffer`: 必须指向一个StaticTask_t 类型的变量，该变量将用于保存任务的数据结构，无需动态分配内存。



优先级

vTaskDelay()

<img src="https://pic2.zhimg.com/v2-fbb486969ad4a338f067182f92939631_b.jpg" alt="img" style="zoom:50%;" />

### 3. 实操

#### 3.1 Task创建和删除

- 函数主体`void myTask()`
- 创建`xTaskCreate()`
- 删除`xTaskDelete(Handle)`
  - 放外面：按句柄删除
  - 放task里面：自己删除(NULL)

#### 3.2 Task传参

用创建任务时用(void*)将地址传过去，然后再在函数中转换回对应的类型

* 单变量

Create: `(void *) &testNum`

Task: `int *pInt; pInt = (int *)pvParam;`

* 数组

Create: `(void *) testNum`

Task: `int *pArray; pArray = (int *)pvParam;`

* 结构体(多参数就用结构体传)

定义结构体

typedef struct  myStruct

{

​    int Mem1;

​    float Mem2;

} xStruct;

xStruct xStrTest = {4, 2.2};

Create: `(void *) &xStrTest`

Task: `xStruct *pStrTest; pStrTest = (xt)`

* 字符串

 定义字符串

static const char *pString = "this is a string!";

Create: `(void *)pString`

Task: `char *pTxt; pTxt=(char *)pvParam; printf("i got string = %s\n",pTxt);`

#### 3.3 任务的优先级

默认设定优先级范围为0-24

* 设定优先级：taskcreate倒数第二个参数

* 查看优先级：`UBaseType_t iPriority = 0; iPriority = uxTaskPriorityGet(pxTask);`

* 相同级别的优先级：谁先创建，谁先运行

* 修改优先级

`vTaskPrioritySet(myHandle1, 3);`

#### 3.4 任务的挂起

任务的状态：running（执行）, ready（就绪）, blocked（阻塞）, suspended（挂起）

<img src="/home/maoyuxuan/.config/Typora/typora-user-images/image-20220126190740825.png" alt="image-20220126190740825" style="zoom:50%;" />

* 阻塞态有超时判断，挂起态没有
* 任务挂起

vTaskSuspend(myHandle);

vTaskSuspend(NULL);

vTaskResume(myHandle);

* 调度器

vTaskSuspendAll(); 该任务运行中不受其他任务调度的影响（对时间敏感），恢复之前不能调用其他RTOS API

vTaskResumeAll();

* 从中断中恢复

xTaskResumeFr
