bool isPalindrome(char* s) {
	int left = 0;
	int right = strlen(s) - 1;

	while (left < right) {
		while (!isalnum(s[left]) && left < right) {
			left++;
		}

		while (!isalnum(s[right])&& left < right) {
			right--;
		}

		if (tolower(s[left]) == tolower(s[right])) {
			left++;
			right--;
		} else {
			return false;
		}
	}

	return true;
}