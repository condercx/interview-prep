int countSegments(char* s)
{
	int count = 0;
	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		/* 当前非空格，且是单词开头 */
		if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
		count++;
		}
	}

	return count;
}