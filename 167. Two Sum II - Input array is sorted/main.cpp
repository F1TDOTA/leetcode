#include <STDIO.H>
#include <stdlib.h>

/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 1. 暴力算法
// 2. 二分法
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int i, temp;
    for (i = 0; i < numbersSize; ++i)
    {
        temp = target - numbers[i];

        int low, high;
        low = 0;
        high = numbersSize -1;
        int result_i = 0;

       *returnSize = 0;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if (numbers[mid] == temp)
            {
                if (i == mid)
                {
                    low = mid + 1;
                    continue;
                }
                else
                {
                    result_i = mid;
					*returnSize = 2;
                    break;
                }
            }
            else if (numbers[mid] < temp) 
            {
                low = mid + 1;
            }
            else 
            {
                high = mid  - 1;
            } 
        }
		
		if (*returnSize == 2)
		{
			int* presult = (int*)malloc(2 * sizeof(int));
			if (presult == NULL) {
				return NULL;
			}
			presult[0] = i+1;
			presult[1] = result_i+1;
			return presult;
		}
	}

	return NULL;
}

// 3. 双指针
int* twoSum1(int* numbers, int numbersSize, int target, int* returnSize)
{
	int low = 0;
	int high = numbersSize - 1;
	int *p_result = (int*)malloc(2* sizeof(int));
	if (!p_result)
		return NULL;
	
	*returnSize = 0;
	while(low < high) 
	{
		int temp = numbers[low] + numbers[high];
		if (temp < target)
		{
			++low;
		}
		else if (temp > target) 
		{
			--high;
		}
		else
		{
			p_result[0] = low+1;
			p_result[1] = high+1;
			
			*returnSize = 2;
			return p_result;
		}
	}

	return NULL;
}


int main(int argc, char* argv[])
{
	int *nums = (int*) malloc(4*sizeof(int));
	nums[0] = 5;
	nums[1] = 25;
	nums[2] = 75;
	nums[3] = 15;

	int returnSize = 0;

	int *p = twoSum1(nums, 3, 100, &returnSize);
	printf("--%d--%d\n", p[0], p[1]);
	return 0;
}
