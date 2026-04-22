bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	if (numsSize == 0) {
		return false;
	}

	int *hash = (int*)calloc(2000000001, sizeof(int));

	for (int i = 0; i < numsSize; i++) {
		if (hash[nums[i] + 1000000000] == 0) {
			hash[nums[i] + 1000000000] = i + 1;
		} else {
			if ((i + 1 - hash[nums[i] + 1000000000]) <= k) {
				return true;
			} else {
				hash[nums[i] + 1000000000] = i + 1;
			}
		}
	}

	return false;
}