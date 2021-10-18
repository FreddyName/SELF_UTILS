# 记录C++中简单的有用的代码

* c++读取文件目录

  其中**dirent.h**文件用于目录操作，Linux默认在*/usr/include*目录下，主要有三个函数：

  + opendir()   打开目录并返回句柄
  + readdir()    读取句柄并返回dirent结构体
  + close()        关闭句柄

  可以通过dirent->d_name文件名称和dirent->d_type文件类型来进行响应的操作

  **注意**: 字符char* 和 char[] 与string类型的转换

  char[]转string ： 直接用char来构造string对象

  string转char[] ： string.c_str() 返回指向string中的字符串的指针常量，为了兼容c

* c++对于文件的操作

​        基本的文件操作包括打开文件、写入文件、读取文件和关闭文件，打开文件包括最基本的读文件和写文件，写和读的时候也要注意数据类型的不同。在c++里面使用文件操作需要 #include<stdio.h>文件

​    