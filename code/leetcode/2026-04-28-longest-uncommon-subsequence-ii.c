int isSub(char *a, char *b)
{
	int i = 0, j = 0;
	int alen = strlen(a);
	int blen = strlen(b);

	while (i < alen && j < blen) {
		if (a[i] == b[j]) {
			i++;
		}
		j++;
	}

	return i == alen;
}

int findLUSlength(char** strs, int strsSize)
{
	int ans = -1;

	for (int i = 0; i < strsSize; i++) {
		int flag = 1;

		for (int j = 0; j < strsSize; j++) {
			if (i == j) continue;

			if (isSub(strs[i], strs[j])) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			int len = strlen(strs[i]);
			ans = ans > len ? ans : len;
		}
	}

	return ans;
}