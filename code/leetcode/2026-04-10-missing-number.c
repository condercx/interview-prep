int missingNumber(int* nums, int numsSize)
{
	int res = numsSize;

	for (int i = 0; i < numsSize; i++) {
		res ^= nums[i];
		res ^= i;
	}

	return res;
}