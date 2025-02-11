#include "algorithm.h"
#include "utils.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    // ---------------需要修改的部分Begin---------------------
    int num_repeat = 10;    // 程序运行次数
    int vector_size = 1000; // 待排序数组大小
    // ---------------需要修改的部分End---------------------
    
    vector<double> sum_times(10, 0.0);

    vector<int> vec_test(vector_size);
    // 生成随机数组
    generate_vector(vec_test, vector_size);
    
    // ---------------需要修改的部分Begin---------------------
    sort_test(vec_test);            // 验证程序正确性，如不需要请注释此行
    sort_operation_count(vec_test); // 输出算法比较和移动次数，如不需要请注释此行
    // ---------------需要修改的部分End---------------------
    
    
    // ---------------需要修改的部分Begin---------------------
    // 统计程序运行时间，如不需要请注释此段代码
    for (int i = 0; i < num_repeat; i++)
    {
        vector<int> vec(vector_size);
        generate_vector(vec, vector_size);
        sort_time(vec,sum_times);
    }
    print_out(sum_times,num_repeat);    // 输出程序平均运行时间
    // ---------------需要修改的部分End---------------------

    return 0;
}