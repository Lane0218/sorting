#include "algorithm.h"

// 随机数最大值
#define UP_BOUND 123456

void generate_vector(vector<int> &nums, int vector_size);
void print_out(vector<double> &sum_times,int num_repeat);
bool are_vectors_qual(const vector<int>& v1, const vector<int>& v2);
void sort_test(vector<int> &nums);
void sort_time(vector<int> &nums,vector<double> &sum_times);
void sort_operation_count(vector<int> &nums);