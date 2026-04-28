char* frequencySort(char* s)
{
	int map[128] = {0};
	int len = strlen(s);
	int i;

	for (i = 0; i < len; i++) {
		map[s[i]]++;
	}

	for (i = 0; i < len;) {
		int maxValue = 0;
		int maxIdx = 0;
		for (int j = 0; j < 128; j++) {
			if (map[j] > maxValue) {
				maxValue = map[j];
				maxIdx = j;
			}
		}
		map[maxIdx] = 0;

		for (int j = 0; j < maxValue; j++) {
			s[j + i] = (char)maxIdx;
		}

		i += maxValue;
	}

	return s;
}