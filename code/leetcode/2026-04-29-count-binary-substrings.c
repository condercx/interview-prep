int countBinarySubstrings(char* s)
{
	int ans = 0;
	int len = strlen(s);
	int pre = 0, cur = 1;

	for (int i = 0; i < len - 1; i++) {
		if (s[i] != s[i + 1]) {
			pre = cur;
			cur = 1;
		} else {
			cur++;
		}
		if (cur <= pre) {
			ans++;
		}
	}

	return ans;
}