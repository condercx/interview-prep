int removeElement(int* nums, int numsSize, int val) {
	if(numsSize == 0) return 0;
	int slowIndex = 0;
	int fastIndex = 0;

	while(fastIndex < numsSize) {
		if (nums[fastIndex] != val) {
			nums[slowIndex] = nums[fastIndex];
			slowIndex++;
		}
		fastIndex++;
	}

	return slowIndex;
}