void reverseString(char* s, int sSize) {
	int start = 0;
	int end = sSize - 1;

	while(start < end) {
		s[start] ^= s[end];
		s[end] ^= s[start];
		s[start] ^= s[end];
		end--;
		start++;
	}
}