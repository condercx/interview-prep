int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	int left_sum = 0;

	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}

	for (int j = 0; j < numsSize; j++) {
		if (left_sum * 2 + nums[j] == sum) {
			return j;
		}

		left_sum += nums[j];
	}

	return -1;
}