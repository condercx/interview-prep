/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sockCollocation(int* sockets, int socketsSize, int* returnSize)
{
	int *ans = (int*)calloc(2, sizeof(int));
	*returnSize = 2;
	int n = 0;
	int bit = 0;

	for (int i = 0; i < socketsSize; i++) {
		n ^= sockets[i];
	}

	while ((n & 1 << bit) == 0) {
		bit++;
	}

	int tmp = 1 << bit;
	for (int i = 0; i < socketsSize; i++) {
		if (ans[i] & tmp) {
			ans[0] ^= sockets[i];
		} else {
			ans[1] ^= sockets[i];
		}
	}

	return ans;
}