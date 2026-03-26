/*暴力，没有过*/

int maxSubArray(int* nums, int numsSize) {
	int max = nums[0];

	for (int i = 0; i < numsSize; i++){
		int tmp = 0;
		for (int j = i; j < numsSize; j++){
			tmp += nums[j];
			if (tmp > max) {
				max = tmp;
			}
		}
	}

	return max;
}

/*维护一个max，一次for循环，如果下一个加进来得到负数，那直接重新开始*/
int maxSubArray(int* nums, int numsSize) {
	int max = nums[0];
	int cur = nums[0];

	for (int i = 1; i < numsSize; ++i) {
		cur = (cur > 0) ? cur + nums[i] : nums[i];
		max = (cur > max) ? cur : max;
	}

	return max;
}