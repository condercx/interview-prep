#include <bits/stdc++.h>
using namespace std;

//哈希表
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				break;
			}

			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			unordered_set<int> set;

			for (int k = i + 1; k < nums.size(); k++) {
				if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2]) {
					continue;
				}

				int target = 0 - (nums[i] + nums[k]);

				if (set.find(target) != set.end()) {
					res.push_back({nums[i], target, nums[k]});
					set.erase(target);
				} else {
					set.insert(nums[k]);
				}
			}
		}

		return res;
	}
};


//双指针
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				break;
			}

			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				} else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				} else {
					res.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[right] == nums[right - 1]) {
						right--;
					}
					while (left < right && nums[left] == nums[left + 1]) {
						left++;
					}

					left++;
					right--;
				}
			}
		}

		return res;
	}
};