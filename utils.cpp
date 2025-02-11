#include"utils.h"

void generate_vector(vector<int> &nums, int vector_size)
{
    for (int i = 0; i < vector_size; i++)
        nums[i] = rand() % UP_BOUND;
}

void print_out(vector<double> &sum_times,int num_repeat)
{
    cout << "\nAverage time:\n";
    cout << "LibrarySort: " << sum_times[0] / num_repeat << " s\n";
	cout << "InsertSort: " << sum_times[1] / num_repeat << " s\n";
    cout << "SelectSort: " << sum_times[2] / num_repeat << " s\n";
    cout << "BubbleSort: " << sum_times[3] / num_repeat << " s\n";
    cout << "MergeSort: " << sum_times[4] / num_repeat << " s\n";
    cout << "QuickSort: " << sum_times[5] / num_repeat << " s\n";
    cout << "QuickSort_v2: " << sum_times[7] / num_repeat << " s\n";
    cout << "QuickSort_v3: " << sum_times[8] / num_repeat << " s\n";
    cout << "QuickSort_v4: " << sum_times[9] / num_repeat << " s\n";
    cout << "ShellSort: " << sum_times[6] / num_repeat << " s\n";
    
    // cout << sum_times[0] / num_repeat << "\n";
	// cout << sum_times[1] / num_repeat << "\n";
    // cout << sum_times[2] / num_repeat << "\n";
    // cout << sum_times[3] / num_repeat << "\n";
    // cout << sum_times[4] / num_repeat << "\n";
    // cout << sum_times[5] / num_repeat << "\n";
    // cout << sum_times[7] / num_repeat << "\n";
    // cout << sum_times[8] / num_repeat << "\n";
    // cout << sum_times[9] / num_repeat << "\n";
    // cout << sum_times[6] / num_repeat << "\n";
}

bool are_vectors_qual(const vector<int>& v1, const vector<int>& v2) 
{
    return equal(v1.begin(), v1.end(), v2.begin());
}

void sort_test(vector<int> &nums)
{
    cout << "Correctness: \n";

    vector<int> ans(nums.begin(),nums.end());
    sort(ans.begin(),ans.end());

    cout << "InsertSort: ";
    vector<int> nums1(nums.begin(),nums.end());
    InsertSort(nums1);
    if (are_vectors_qual(ans,nums1))
        cout << "correct\n";
    else
        cout << "wrong\n";

    cout << "SelectSort: ";
    vector<int> nums2(nums.begin(),nums.end());
    SelectSort(nums2);
    if (are_vectors_qual(ans,nums2))
        cout << "correct\n";
    else
        cout << "wrong\n";

    cout << "BubbleSort: ";
    vector<int> nums3(nums.begin(),nums.end());
    BubbleSort(nums3);
    if (are_vectors_qual(ans,nums3))
        cout << "correct\n";
    else
        cout << "wrong\n";
    
    cout << "MergeSort: ";
    vector<int> nums4(nums.begin(),nums.end());
    MergeSort(nums4);
    if (are_vectors_qual(ans,nums4))
        cout << "correct\n";
    else
        cout << "wrong\n";
    
    cout << "QuickSort: ";
    vector<int> nums5(nums.begin(),nums.end());
    QuickSort(nums5);
    if (are_vectors_qual(ans,nums5))
        cout << "correct\n";
    else
        cout << "wrong\n";
    
    cout << "QuickSort_v2: ";
    vector<int> nums5_2(nums.begin(),nums.end());
    QuickSort_v2(nums5_2);
    if (are_vectors_qual(ans,nums5_2))
        cout << "correct\n";
    else
        cout << "wrong\n";

    cout << "QuickSort_v3: ";
    vector<int> nums5_3(nums.begin(),nums.end());
    QuickSort_v3(nums5_3);
    if (are_vectors_qual(ans,nums5_3))
        cout << "correct\n";
    else
        cout << "wrong\n";

    cout << "QuickSort_v4: ";
    vector<int> nums5_4(nums.begin(),nums.end());
    QuickSort_v4(nums5_4);
    if (are_vectors_qual(ans,nums5_4))
        cout << "correct\n";
    else
        cout << "wrong\n";
        
    cout << "ShellSort: ";
    vector<int> nums6(nums.begin(),nums.end());
    ShellSort(nums6);
    if (are_vectors_qual(ans,nums6))
        cout << "correct\n";
    else
        cout << "wrong\n";
}

void sort_time(vector<int> &nums,vector<double> &sum_times)
{
    clock_t start_time, end_time;

    vector<int> nums0(nums.begin(),nums.end());
    start_time = clock();
    sort(nums0.begin(),nums0.end());
    end_time = clock();
    sum_times[0] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums1(nums.begin(),nums.end());
    start_time = clock();
    // InsertSort(nums1);
    end_time = clock();
    sum_times[1] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums2(nums.begin(),nums.end());
    start_time = clock();
    // SelectSort(nums2);
    end_time = clock();
    sum_times[2] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums3(nums.begin(),nums.end());
    start_time = clock();
    // BubbleSort(nums3);
    end_time = clock();
    sum_times[3] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums4(nums.begin(),nums.end());
    start_time = clock();
    MergeSort(nums4);
    end_time = clock();
    sum_times[4] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums5(nums.begin(),nums.end());
    start_time = clock();
    QuickSort(nums5);
    end_time = clock();
    sum_times[5] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums5_2(nums.begin(),nums.end());
    start_time = clock();
    QuickSort_v2(nums5_2);
    end_time = clock();
    sum_times[7] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums5_3(nums.begin(),nums.end());
    start_time = clock();
    QuickSort_v3(nums5_3);
    end_time = clock();
    sum_times[8] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums5_4(nums.begin(),nums.end());
    start_time = clock();
    QuickSort_v4(nums5_4);
    end_time = clock();
    sum_times[9] += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    vector<int> nums6(nums.begin(),nums.end());
    start_time = clock();
    ShellSort(nums6);
    end_time = clock();
    sum_times[6] += (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

void sort_operation_count(vector<int> &nums)
{
    cout << "\nOperation count:\n\t\tcompare\tmove \n";

    vector<int> nums1(nums.begin(),nums.end());
    InsertSort_instrumentation(nums1);

    vector<int> nums2(nums.begin(),nums.end());
    SelectSort_instrumentation(nums2);

    vector<int> nums3(nums.begin(),nums.end());
    BubbleSort_instrumentation(nums3);

    vector<int> nums4(nums.begin(),nums.end());
    MergeSort_instrumentation(nums4);

    vector<int> nums5(nums.begin(),nums.end());
    QuickSort_instrumentation(nums5);

    vector<int> nums5_2(nums.begin(),nums.end());
    QuickSort_v2_instrumentation(nums5_2);

    vector<int> nums5_3(nums.begin(),nums.end());
    QuickSort_v3_instrumentation(nums5_3);

    vector<int> nums5_4(nums.begin(),nums.end());
    QuickSort_v4_instrumentation(nums5_4);

    vector<int> nums6(nums.begin(),nums.end());
    ShellSort_instrumentation(nums6);
}