#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;

/*
  给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

  你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

  示例:

  给定 nums = [2, 7, 11, 15], target = 9

  因为 nums[0] + nums[1] = 2 + 7 = 9
  所以返回 [0, 1]
*/

// normal
int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
    int i, j, temp;
    for (i = 0; i < numsSize; ++i)
    {
        temp = target - nums[i];
        for (j = i+1; j < numsSize; ++j) 
        {
            if (nums[j]  == temp)
            {
                int* presult  = (int*)malloc(2 * sizeof(int));
                if (presult == NULL)
                {
                    *returnSize = 0;
                    return NULL;
                }
                presult[0] = i;
                presult[1] = j;
                *returnSize = 2;
                return presult;                
            }
        }
    }
 
    *returnSize = 0;
    return NULL;
}

// hash算法, 这里不使用C语言了。不重复造软轮子
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, temp;
        std::map<int, int> tmp_map;
        int num_size = nums.size();
        vector<int> vecResult;
        
        for (i = 0; i < num_size; ++i)
        {
            temp = target - nums[i];
            if (tmp_map.find(temp) != tmp_map.end() && tmp_map[temp] != i)
            {
                vecResult.push_back(i);
                vecResult.push_back(tmp_map[temp]);
                return vecResult;
            }
            tmp_map[nums[i]] = i;    
        }
        return vecResult;
    }
};

int main(int argc, char* argv[])
{
    int *nums = (int*) malloc(4*sizeof(int));
    nums[0]   = 5;
    nums[1]   = 25;
    nums[2]   = 75;
    nums[3]   = 15;
	
    int returnSize = 0;


   // int *p = twoSum(nums, 3, 100, &returnSize);
	 int * p = NULL;
    if (!p)
    {
        printf("p is null\n");
    }
    else
    {
        printf("--%d--%d\n", p[0], p[1]);
    }
    return 0;
}
