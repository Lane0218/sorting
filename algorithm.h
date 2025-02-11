#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

// 注：函数名带instrumentation的为插桩函数，用于统计关键操作次数

// 插入排序
void InsertSort(vector<int>&nums);
void InsertSort_instrumentation(vector<int> &nums);

// 选择排序
void SelectSort(vector<int>&nums);
void SelectSort_instrumentation(vector<int>&nums);

// 冒泡排序
void BubbleSort(vector<int>&nums);
void BubbleSort_instrumentation(vector<int>&nums);

// 归并排序
void MergeSort(vector<int>&nums);
void MergeSort_unpacked(vector<int> &nums,vector<int> &tmp_nums,int left,int right);
void Merge(vector<int> &nums,vector<int> &tmp_nums, int left, int mid, int right);
void MergeSort_instrumentation(vector<int>& nums);
void MergeSort_unpacked_instrumentation(vector<int> &nums,vector<int> &tmp_nums,int left,int right,long long &cnt_compare,long long &cnt_move);
void Merge_instrumentation(vector<int> &nums,vector<int> &tmp_nums, int left, int mid, int right,long long &cnt_compare,long long &cnt_move);

// 快速排序（左右指针法）
void QuickSort(vector<int>&nums);
void QuickSort_unpacked(vector<int>&nums,int left,int right);
int QuickSort_partition(vector<int>&nums,int left,int right);
void QuickSort_instrumentation(vector<int>&nums);
void QuickSort_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);
int QuickSort_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);

// 快速排序（空穴法）
void QuickSort_v2(vector<int>&nums);
void QuickSort_v2_unpacked(vector<int>&nums,int left,int right);
int QuickSort_v2_partition(vector<int>&nums,int left,int right);
void QuickSort_v2_instrumentation(vector<int>&nums);
void QuickSort_v2_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);
int QuickSort_v2_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);

// 快速排序（前后指针法）
void QuickSort_v3(vector<int>&nums);
void QuickSort_v3_unpacked(vector<int>&nums,int left,int right);
int QuickSort_v3_partition(vector<int>&nums,int left,int right);
void QuickSort_v3_instrumentation(vector<int>&nums);
void QuickSort_v3_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);
int QuickSort_v3_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);

// 快速排序（在空穴法的基础上优化）
void QuickSort_v4(vector<int>&nums);
void QuickSort_v4_unpacked(vector<int>&nums,int left,int right);
int QuickSort_v4_partition(vector<int>&nums,int left,int right);
void QuickSort_v4_instrumentation(vector<int>&nums);
void QuickSort_v4_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);
int QuickSort_v4_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move);

// 希尔排序
void ShellSort(vector<int>&nums);
void ShellSort_instrumentation(vector<int>& nums);