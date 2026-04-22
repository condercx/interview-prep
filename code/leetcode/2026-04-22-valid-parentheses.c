bool isValid(char* s)
{
	int len = strlen(s);
	char* stack = (char*)malloc(sizeof(char) * len);
	int top = -1;

	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stack[++top] = s[i];
		} else {
			if (top < 0) return false;

			if (s[i] == ')') {
				if (stack[top] != '(') return false;
				else top--;
			}

			if (s[i] == ']') {
				if (stack[top] != '[') return false;
				else top--;
			}

			if (s[i] == '}') {
				if (stack[top] != '{') return false;
				else top--;
			}
		}
	}

	if (top >= 0) return false;
	return true;
}