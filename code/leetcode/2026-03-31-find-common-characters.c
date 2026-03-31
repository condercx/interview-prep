/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** words, int wordsSize, int* returnSize) {
	if (words == NULL || wordsSize == 0) {
		*returnSize = 0;
		return NULL;
	}

	int hashmap[wordsSize][26];
	memset(hashmap, 0, sizeof(hashmap));
	char **ret = (char**)malloc(sizeof(char*) * 100);

	for (int i = 0; i < 100; i++) {
		ret[i] = (char*)malloc(sizeof(char) * 2);
	}

	for (int i = 0; i < wordsSize; i++) {
		for (int j = 0; j < strlen(words[i]); j++) {
			hashmap[i][words[i][j] - 'a']++;
		}
	}

	int size = 0;
	for (int i = 0; i < 26; i++) {
		int min = hashmap[0][i];
		for (int j = 1; j < wordsSize; j++) {
			if (hashmap[j][i] < min) {
				min = hashmap[j][i];
			}
		}

		while (min > 0) {
			ret[size][0] = i + 'a';
			ret[size][1] = '\0';
			size++;
			min--;
		}
	}

	*returnSize = size;
	return ret;
}