int findLengthOfLCIS(int* nums, int numsSize)
{
	if (numsSize == 1) return 1;

	int maxLen = 1;
	int curLen = 1;

	for (int i = 1; i < numsSize; i++) {
		if (nums[i] > nums[i - 1]) {
			curLen++;
			if (curLen > maxLen) {
				maxLen = curLen;
			}
		} else {
			curLen = 1;
		}
	}

	return maxLen;
}