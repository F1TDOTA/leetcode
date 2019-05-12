#include <STDIO.H>
#include <stdlib.h>

/*
����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 1. �����㷨
// 2. ���ַ�
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

// 3. ˫ָ��
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
