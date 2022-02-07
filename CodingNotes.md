* 头文件加斜杠：头文件路径

* 修改完了要保存，编译的才是新程序

* Guru Meditation Error: Core  1 panic'ed (StoreProhibited). Exception was unhandled.
  * 修改分配内存从1024变为2048

* ％d整型输出，％ld长整型输出，

  ％o以八进制数形式输出整数，

  ％x以十六进制数形式输出整数，或输出字符串的地址。

  ％u以十进制数输出unsigned型数据(无符号数)。注意：%d与%u有无符号的数值范围，也就是极限的值，不然数值打印出来会有误。

  ％c用来输出一个字符，

  ％s用来输出一个字符串，

  ％f用来输出实数，以小数形式输出，默认情况下保留小数点6位。

  %.100f用来输出实数，保留小数点100位。

  ％e以指数形式输出实数

* Handle输入函数要引用地址
* **刚开始Task1的优先级为1，Task2优先级为2，后来Task1的优先级被设置为3**
  **但是在输出的时候直接输出111-222-111-222（并不是UP那样222-111-111-222）,但是查看优先级确实是3**

* ninja: build stopped: subcommand failed.
  ninja failed with exit code 1
  * 代码有语法错误
* vscode无法联想函数
  * 添加一些相关头文件
  * 软链接 命令行输ln -s ~/esp/esp-idf
  * 添加文件夹至工作目录

* 创建动态字符串
  * 定义char指针
  * **动态分配内存malloc(size);**
  * 设置内容snprintf（char*, size, "xxxx%d!\n",i）;
  * 打印：printf(char*)
  * **释放内存：free(char*)**
* micro ros 分支要选foxy版本
