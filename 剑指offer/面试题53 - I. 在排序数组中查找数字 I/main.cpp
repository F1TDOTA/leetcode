#include <vector>
#include <map>
using namespace std;


class Solution1 {
public:
    int search(vector<int>& nums, int target) {
		int total_len = nums.size();
		int out_count = 0;
		for (int i = 0; i < total_len; ++i) {
			if (nums.at(i) == target) {
				++out_count;
			}
		}
		return total_len;
	}
};

class Solution2 {
public:
	int search(vector<int>& nums, int target){
		
		map<int, int> map_result;
		int total_len = nums.size();

		for (int i = 0; i < total_len; ++i) {
			if (nums.at(i) == target)
				map_result[i] = map_result[i] + 1;
		}
		return map_result[target];
	}
};


class Solution3 {
public:
	int search(vector<int>& nums, int target) {
		int left, right, mid = -1;

		left = 0;
		right = nums.size() - 1;
		

		while (left <= right) {
			mid = left + (right - left)/2;
			if (nums.at(mid) == target) {
				int count = 0;
				for (int k = left; k <= right; ++k)
					if (nums.at(k) == target)
						++count;
				
				return count;
			} else if (nums.at(mid) > target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return 0;
	}
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int total_len = nums.size();
		int out_count = 0;

		for (int i = 0; i < total_len; ++i) {
			if (nums[i] == target) {
				++out_count;
			} else if (nums[i] > target) {
				break;
			}
		}
		return out_count;
	}
};


int main(int argc, char*argv[]) {
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(9);
	nums.push_back(9);
	nums.push_back(10);
	

	Solution a;
	int result = a.search(nums, 8);
	printf("--%d\n", result);

	return 0;
}