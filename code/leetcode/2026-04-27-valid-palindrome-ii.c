bool isPalindrome(char *s, int start, int end)
{
	while (start < end) {
		if (s[start] != s[end]) {
			return false;
		}

		start++;
		end--;
	}

	return true;
}

bool validPalindrome(char* s)
{
	if (strlen(s) <= 2) return true;
	int left = 0;
	int right = strlen(s) - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			if (isPalindrome(s, left + 1, right)) {
				return true;
			}

			if (isPalindrome(s, left, right - 1)) {
				return true;
			}

			return false;
		}

		left++;
		right--;
	}

	return true;
}