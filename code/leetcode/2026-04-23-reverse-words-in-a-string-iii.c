void swap(char *str, int start, int end)
{
	while (start < end) {
		str[start] ^= str[end];
		str[end] ^= str[start];
		str[start] ^= str[end];
		start++;
		end--;
	}
}

char* reverseWords(char *s)
{
	int start = 0;
	int end = 0;
	int len = strlen(s);

	while (end <= len) {
		if (s[end] == ' ' || s[end] == '\0') {
			swap(s, start, end - 1);
			start = end + 1;
		}
		end++;
	}

	return s;
}