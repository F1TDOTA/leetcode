#include <VECTOR>
#include <algorithm>
using namespace std;
/*
  给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

  注意：答案中不可以包含重复的三元组。

  例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

  满足要求的三元组集合为：
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]

*/

/* force * ---TLE*/
class Solution1 {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        int i,j,k;
        int nums_total = nums.size();
        vector< vector<int> > vec_ret;
        vector< vector<int> >::iterator fit;
        vector<int> vec_tmp;

        // for
        for (i = 0; i < nums_total; ++i) 
            for (j = i+1; j < nums_total; ++j)
                for(k = j+1; k < nums_total; ++k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vec_tmp.clear();
                        vec_tmp.push_back(nums[i]);
                        vec_tmp.push_back(nums[j]);
                        vec_tmp.push_back(nums[k]);
                        sort(vec_tmp.begin(), vec_tmp.end());
                        fit = find(vec_ret.begin(), vec_ret.end(), vec_tmp);
                        if (fit == vec_ret.end())
                            vec_ret.push_back(vec_tmp);
                    }
                    
                }
        return vec_ret;
    }
};

// double point --tle
class Solution2 {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        int i,j,k, temp;
        int low, high;
        int nums_total = nums.size();
        vector< vector<int> > vec_ret;
        vector< vector<int> >::iterator fit;
        vector<int> vec_tmp;

        // sort
        sort(nums.begin(), nums.end());

        // double point
        for (i = 0; i < nums_total; ++i)
        {
            temp = 0 - nums[i];
            printf("---%d--%d\n", i, temp);

            // start while
            low = i + 1; 
            high = nums_total - 1;
            while (low < high)
            {
                int tempadd = nums[low] + nums[high];
                if (tempadd == temp)
                {
                    vec_tmp.clear();
                    vec_tmp.push_back(nums[i]);
                    vec_tmp.push_back(nums[low]);
                    vec_tmp.push_back(nums[high]);
                    fit = find(vec_ret.begin(), vec_ret.end(), vec_tmp);
                    if (fit == vec_ret.end())
                        vec_ret.push_back(vec_tmp);
                    ++low;
                }
                else if (tempadd > temp) 
                    --high;
                else
                    ++low;
            }
        }
        
        return vec_ret;
    }
};

//
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > vec_ret;

        
        return vec_ret;
    }
};


int main(int argc, char* argv[])
{
    // [-1,0,1,2,-1,-4]
    vector<int> inputvec;
    inputvec.push_back(-1);
    inputvec.push_back(0);
    inputvec.push_back(1);
    inputvec.push_back(2);
    inputvec.push_back(-1);
    inputvec.push_back(-4);
    class Solution a;
    vector< vector<int> > ret = a.threeSum(inputvec);
    printf("\n------------my answer------------\n");
    for (vector< vector<int> >::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        for (vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); ++it1)
        {
            printf("%d ", (*it1));
        }
        printf("\n");
    }
      
    return 0;
}
