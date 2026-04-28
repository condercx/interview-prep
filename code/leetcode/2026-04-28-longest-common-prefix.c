char* longestCommonPrefix(char** strs, int strsSize)
{
	char *sc = strs[0];

	for (int com = 0; sc[com] != '\0'; com++) {
		for (int i = 1; i < strsSize; i++) {
			if (sc[com] != strs[i][com]) {
				sc[com] = '\0';
				return sc;
			}
		}
	}

	return sc;
}