#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;

/*
  ����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

  ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

  ʾ��:

  ���� nums = [2, 7, 11, 15], target = 9

  ��Ϊ nums[0] + nums[1] = 2 + 7 = 9
  ���Է��� [0, 1]
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

// hash�㷨, ���ﲻʹ��C�����ˡ����ظ���������
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
