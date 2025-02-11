#include"algorithm.h"

void InsertSort(vector<int> &nums)
{
    int size=nums.size();
	for (int i = 1; i < size; i++)
	{
		int j = i, key = nums[j];
		while (j > 0 && nums[j - 1] > key)
		{
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = key;
	}
}

void InsertSort_instrumentation(vector<int> &nums)
{
    long long cnt_compare = 0, cnt_move = 0;

    int size=nums.size();
	for (int i = 1; i < size; i++)
	{
		int j = i, key = nums[j];
		while (j > 0 && (cnt_compare++, nums[j - 1] > key))
		{
			nums[j] = nums[j - 1];
            cnt_move++;
			j--;
		}
		nums[j] = key;
	}

    cout << "InsertSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

void SelectSort(vector<int>& nums)
{
    int size=nums.size();
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
            if(nums[j]<nums[min])
                min=j;
        swap(nums[i],nums[min]);
    }
}

void SelectSort_instrumentation(vector<int>& nums)
{
    long long cnt_compare = 0, cnt_move = 0;

    int size=nums.size();
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
            if((cnt_compare++, nums[j]<nums[min]))
                min=j;
        swap(nums[i],nums[min]);
        cnt_move+=3;
    }

    cout << "SelectSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

void BubbleSort(vector<int>& nums)
{
    int size=nums.size();
    for(int i=0;i<size-1;i++)
    {
        int flag=0;
        for(int j=0;j<size-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                flag=1;
                swap(nums[j],nums[j+1]);
            } 
        }
        if(flag==0)
            break;   
    }
}

void BubbleSort_instrumentation(vector<int>& nums)
{
    long long cnt_compare = 0, cnt_move = 0;

    int size=nums.size();
    for(int i=0;i<size-1;i++)
    {
        int flag=0;
        for(int j=0;j<size-i-1;j++)
        {
            if((cnt_compare++,nums[j]>nums[j+1]))
            {
                flag=1;
                swap(nums[j],nums[j+1]);
                cnt_move+=3;
            } 
        }
        if(flag==0)
            break;   
    }

    cout << "BubbleSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

void Merge(vector<int> &nums,vector<int> &tmp_nums, int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    while (i < mid && j <= right)
    {
        if (nums[i] < nums[j])
            tmp_nums[k++] = nums[i++];
        else
            tmp_nums[k++] = nums[j++];
    }
    while (i < mid)
        tmp_nums[k++] = nums[i++];
    while (j <= right)
        tmp_nums[k++] = nums[j++];
    for (int i = left; i <= right; i++)
        nums[i] = tmp_nums[i];
}

void MergeSort_unpacked(vector<int> &nums,vector<int> &tmp_nums,int left,int right)
{
    if(left>=right)
        return;

    int mid=(left+right)/2;
    // [left,mid]
    MergeSort_unpacked(nums,tmp_nums,left,mid);
    // [mid+1,right]
    MergeSort_unpacked(nums,tmp_nums,mid+1,right);
    // left为左边起点，mid+1为右边起点，right为右边终点
    Merge(nums,tmp_nums,left,mid+1,right);
}

void MergeSort(vector<int>& nums)
{
    vector<int> tmp_nums(nums.size());
    // [left,right]
    MergeSort_unpacked(nums, tmp_nums, 0, nums.size()-1);
}

void Merge_instrumentation(vector<int> &nums,vector<int> &tmp_nums, int left, int mid, int right,long long &cnt_compare,long long &cnt_move)
{
    int i = left, j = mid, k = left;
    while (i < mid && j <= right)
    {
        if ((cnt_compare++,nums[i] < nums[j]))
        {
            tmp_nums[k++] = nums[i++];
            cnt_move++;
        }
        else
        {
            tmp_nums[k++] = nums[j++];
            cnt_move++;
        }
    }
    while (i < mid)
    {
        tmp_nums[k++] = nums[i++];
        cnt_move++;
    }
    while (j <= right)
    {
        tmp_nums[k++] = nums[j++];
        cnt_move++;
    }
    for (int i = left; i <= right; i++, cnt_move++)
        nums[i] = tmp_nums[i];
}

void MergeSort_unpacked_instrumentation(vector<int> &nums,vector<int> &tmp_nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    if(left>=right)
        return;

    int mid=(left+right)/2;
    // [left,mid]
    MergeSort_unpacked_instrumentation(nums,tmp_nums,left,mid,cnt_compare,cnt_move);
    // [mid+1,right]
    MergeSort_unpacked_instrumentation(nums,tmp_nums,mid+1,right,cnt_compare,cnt_move);
    // left为左边起点，mid+1为右边起点，right为右边终点
    Merge_instrumentation(nums,tmp_nums,left,mid+1,right,cnt_compare,cnt_move);
}

void MergeSort_instrumentation(vector<int>& nums)
{
    long long cnt_compare = 0, cnt_move = 0;

    vector<int> tmp_nums(nums.size());
    // [left,right]
    MergeSort_unpacked_instrumentation(nums, tmp_nums, 0, nums.size()-1,cnt_compare,cnt_move);

    cout << "MergeSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

// 快速排序（左右指针法）
int QuickSort_partition(vector<int>&nums,int left,int right)
{
    int x=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && nums[j]>=x)
            j--;
        while(i<j && nums[i]<=x)
            i++;
        swap(nums[i],nums[j]);
    }
    swap(nums[left],nums[j]);
    return j;
}

void QuickSort_unpacked(vector<int>&nums,int left,int right)
{
    if(left>=right)
        return;
    
    int q=QuickSort_partition(nums,left,right);
    QuickSort_unpacked(nums,left,q-1);
    QuickSort_unpacked(nums,q+1,right);
}

void QuickSort(vector<int>& nums)
{
    QuickSort_unpacked(nums,0,nums.size()-1);
}

int QuickSort_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    int x=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && (cnt_compare++,nums[j]>=x))
            j--;
        while(i<j && (cnt_compare++,nums[i]<=x))
            i++;
        swap(nums[i],nums[j]);
        cnt_move+=3;
    }
    swap(nums[left],nums[j]);
    cnt_move+=3;
    return j;
}

void QuickSort_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    if(left>=right)
        return;
    
    int q=QuickSort_partition_instrumentation(nums,left,right,cnt_compare,cnt_move);
    QuickSort_unpacked_instrumentation(nums,left,q-1,cnt_compare,cnt_move);
    QuickSort_unpacked_instrumentation(nums,q+1,right,cnt_compare,cnt_move);
}

void QuickSort_instrumentation(vector<int>&nums)
{
    long long cnt_compare = 0, cnt_move = 0;
    QuickSort_unpacked_instrumentation(nums,0,nums.size()-1,cnt_compare,cnt_move);

    cout << "QuickSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

// 快速排序（空穴法）
int QuickSort_v2_partition(vector<int>&nums,int left,int right)
{
    int key=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && nums[j]>=key)
            j--;
        nums[i]=nums[j];
        while(i<j && nums[i]<=key)
            i++;
        nums[j]=nums[i];
    }
    nums[i]=key;
    return i;
}

void QuickSort_v2_unpacked(vector<int>&nums,int left,int right)
{
    if(left>=right)
        return;
    
    int q=QuickSort_v2_partition(nums,left,right);
    QuickSort_v2_unpacked(nums,left,q-1);
    QuickSort_v2_unpacked(nums,q+1,right);
}

void QuickSort_v2(vector<int>& nums)
{
    QuickSort_v2_unpacked(nums,0,nums.size()-1);
}

int QuickSort_v2_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    int key=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && (cnt_compare++,nums[j]>=key))
            j--;
        nums[i]=nums[j];
        cnt_move++;
        while(i<j && (cnt_compare++,nums[i]<=key))
            i++;
        nums[j]=nums[i];
        cnt_move++;
    }
    nums[i]=key;
    return i;
}

void QuickSort_v2_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    if(left>=right)
        return;
    
    int q=QuickSort_v2_partition_instrumentation(nums,left,right,cnt_compare,cnt_move);
    QuickSort_v2_unpacked_instrumentation(nums,left,q-1,cnt_compare,cnt_move);
    QuickSort_v2_unpacked_instrumentation(nums,q+1,right,cnt_compare,cnt_move);
}

void QuickSort_v2_instrumentation(vector<int>&nums)
{
    long long cnt_compare = 0, cnt_move = 0;
    QuickSort_v2_unpacked_instrumentation(nums,0,nums.size()-1,cnt_compare,cnt_move);

    cout << "QuickSort_v2:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

// 快速排序（前后指针法）
int QuickSort_v3_partition(vector<int>&nums,int left,int right)
{
    int key=nums[left];
    int pre=left,cur=left+1;
    while(cur<=right)
    {
        if(nums[cur]<key && cur!=++pre)
            swap(nums[cur],nums[pre]);
        cur++;
    }
    swap(nums[left],nums[pre]);
    return pre;
}

void QuickSort_v3_unpacked(vector<int>&nums,int left,int right)
{
    if(left>=right)
        return;
    
    int q=QuickSort_v3_partition(nums,left,right);
    QuickSort_v3_unpacked(nums,left,q-1);
    QuickSort_v3_unpacked(nums,q+1,right);
}

void QuickSort_v3(vector<int>& nums)
{
    QuickSort_v3_unpacked(nums,0,nums.size()-1);
}

int QuickSort_v3_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    int key=nums[left];
    int pre=left,cur=left+1;
    while(cur<=right)
    {
        if((cnt_compare++,nums[cur]<key) && cur!=++pre)
        {
            swap(nums[cur],nums[pre]);
            cnt_move+=3;
        } 
        cur++;
    }
    swap(nums[left],nums[pre]);
    cnt_move+=3;
    return pre;
}

void QuickSort_v3_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    if(left>=right)
        return;
    
    int q=QuickSort_v3_partition_instrumentation(nums,left,right,cnt_compare,cnt_move);
    QuickSort_v3_unpacked_instrumentation(nums,left,q-1,cnt_compare,cnt_move);
    QuickSort_v3_unpacked_instrumentation(nums,q+1,right,cnt_compare,cnt_move);
}

void QuickSort_v3_instrumentation(vector<int>&nums)
{
    long long cnt_compare = 0, cnt_move = 0;
    QuickSort_v3_unpacked_instrumentation(nums,0,nums.size()-1,cnt_compare,cnt_move);

    cout << "QuickSort_v3:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

// 快速排序（在空穴法的基础上优化）
int QuickSort_v4_partition(vector<int>&nums,int left,int right)
{
    int key=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && nums[j]>=key)
            j--;
        nums[i]=nums[j];
        while(i<j && nums[i]<=key)
            i++;
        nums[j]=nums[i];
    }
    nums[i]=key;
    return i;
}

void QuickSort_v4_unpacked(vector<int>&nums,int left,int right)
{
    if(left>=right)
        return;
    
    // 如果元素个数不足10个，采用直接插入排序
    if(right-left+1<10)
    {
        for (int i = left+1; i <=right; i++)
        {
            int j = i, key = nums[j];
            while (j > left && nums[j - 1] > key)
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = key;
        }
        return;
    }

    // 三数取中
    int mid=(left+right)/2;
    if(nums[mid]<nums[left])
        swap(nums[mid],nums[left]);
    if(nums[right]<nums[left])
        swap(nums[right],nums[left]);
    if(nums[right]<nums[mid])
        swap(nums[right],nums[mid]);

    int q=QuickSort_v4_partition(nums,left,right);
    QuickSort_v4_unpacked(nums,left,q-1);
    QuickSort_v4_unpacked(nums,q+1,right);
}

void QuickSort_v4(vector<int>& nums)
{
    QuickSort_v4_unpacked(nums,0,nums.size()-1);
}

int QuickSort_v4_partition_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    int key=nums[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j && (cnt_compare++,nums[j]>=key))
            j--;
        nums[i]=nums[j];
        cnt_move++;
        while(i<j && (cnt_compare++,nums[i]<=key))
            i++;
        nums[j]=nums[i];
        cnt_move++;
    }
    nums[i]=key;
    return i;
}

void QuickSort_v4_unpacked_instrumentation(vector<int>&nums,int left,int right,long long &cnt_compare,long long &cnt_move)
{
    if(left>=right)
        return;
    
    int q=QuickSort_v4_partition_instrumentation(nums,left,right,cnt_compare,cnt_move);
    QuickSort_v4_unpacked_instrumentation(nums,left,q-1,cnt_compare,cnt_move);
    QuickSort_v4_unpacked_instrumentation(nums,q+1,right,cnt_compare,cnt_move);
}

void QuickSort_v4_instrumentation(vector<int>&nums)
{
    long long cnt_compare = 0, cnt_move = 0;
    QuickSort_v4_unpacked_instrumentation(nums,0,nums.size()-1,cnt_compare,cnt_move);

    cout << "QuickSort_v4:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}

void ShellSort(vector<int>& nums)
{
    int n = nums.size();
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = nums[i];
            int j;
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
                nums[j] = nums[j - gap];
            nums[j] = temp;
        }
        gap /= 2;
    }
}

void ShellSort_instrumentation(vector<int>& nums)
{
    long long cnt_compare = 0, cnt_move = 0;

    int n = nums.size();
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = nums[i];
            int j;
            for (j = i; j >= gap && (cnt_compare++,nums[j - gap] > temp); j -= gap)
            {
                nums[j] = nums[j - gap];
                cnt_move++;
            }
            nums[j] = temp;
            cnt_move++;
        }
        gap /= 2;
    }

    cout << "ShellSort:\t" << cnt_compare << "\t" << cnt_move << "\n";
    // cout << cnt_compare << "\t" << cnt_move << "\n";
}