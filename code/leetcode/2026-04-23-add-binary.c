char* addBinary(char* a, char* b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	int maxLen = (len_a > len_b ? len_a : len_b) + 2;

	char* res = (char*)calloc(maxLen, sizeof(char));
	int carry = 0;
	int idx = maxLen - 2;

	for(len_a--, len_b--; len_a >= 0 || len_b >= 0 || carry != 0; idx--) {
		int na = len_a >= 0 ? a[len_a--] - '0' : 0;
		int nb = len_b >= 0 ? b[len_b--] - '0' : 0;

		int sum = na + nb + carry;
		res[idx] = (sum % 2) + '0';
		carry = sum / 2;
	}

	return res[0] == '\0' ? res + 1 : res;
}