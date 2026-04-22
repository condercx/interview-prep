char* addStrings(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2  = strlen(num2);
	int maxLen = (len1 > len2 ? len1 : len2) + 2;
	char* res = (char *)calloc(maxLen, sizeof(char));
	int carry = 0;
	int idx = maxLen - 2;
	for (len1--, len2--; len1 >= 0 || len2 >= 0 || carry != 0; idx--) {
		int n1 = len1 >= 0 ? num1[len1--] - '0' : 0;
		int n2 = len2 >= 0 ? num2[len2--] - '0' : 0;

		int sum = n1 + n2 + carry;
		res[idx] = (sum % 10) + '0';
		carry = sum / 10;
	}

	return res[0] == '\0' ? res + 1 : res;
}