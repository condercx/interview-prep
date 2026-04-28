void swap(char *s, int left, int right)
{
	s[left] ^= s[right];
	s[right] ^= s[left];
	s[left] ^= s[right];
}

int vowels(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	  || c == 'A' || c == 'E' || c =='I' || c == 'O' || c == 'U') {
		return 1;
	} else {
		return 0;
	}
}
char* reverseVowels(char* s)
{
	int left = 0;
	int right = strlen(s) - 1;

	while (left < right) {
		while (left < right && !vowels(s[left])) {
			left++;
		}  
		while (left < right && !vowels(s[right])) {
			right--;
		}
		if (left < right) {
			swap(s, left, right);
			left++;
			right--;
		}
	}

	return s;
}