/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int *res = (int*)malloc(sizeof(int) * numsSize);
	int even = 0;
	int odd = numsSize - 1;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 2 == 0) {
			res[even++] = nums[i];
		} else {
			res[odd--] = nums[i];
		}
	}

	return res;
}