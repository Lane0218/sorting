# 分治法分析实验

本项目实现了多种经典排序算法的C++实现，包括插入排序、选择排序、冒泡排序、归并排序、Shell排序和快速排序。每种排序算法都配有正确性测试、性能测试和关键操作次数统计功能。

实验内容和实验报告见[Lane's Blog](https://www.lane0218.top/KB/bthamqot/)

## 功能
- 实现六种排序算法：插入排序、选择排序、冒泡排序、归并排序、Shell排序、快速排序（含左右指针法、空穴法、前后指针法和在空穴法的基础上优化的版本）。
- 统计排序过程中的关键操作次数，如比较次数和移动次数。
- 提供性能测试和排序正确性验证功能。
- 支持在Linux环境下通过Makefile进行编译和运行。

## 使用说明

1. 在Linux环境下进入项目目录：
```bash
cd 路径/至/项目目录
```

2. 编译项目：
```bash
make
```

3. 运行程序：
```bash
./sort
```
如果想将程序输出重定向到文件中，可在命令行中执行：
```bash
./sort > output.txt
```

## 补充说明
程序中快速排序算法的函数名称如下：
- QuickSort：快速排序（左右指针法）
- QuickSort_v2：快速排序（空穴法）
- QuickSort_v3：快速排序（前后指针法）
- QuickSort_v4：快速排序（在空穴法的基础上优化）

本项目仅限个人学习和参考之用，请严格遵守学术诚信规范，严禁任何形式的抄袭行为。
