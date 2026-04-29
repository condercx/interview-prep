#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(const char *s)
{
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}

	return len;
}

char* my_strcpy(char *dst, const char *src)
{
	int i = 0;
	while(src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';

	return dst;
}

char* my_strcat(char *dst, const char *src)
{
	int i = 0, j = 0;

	while (dst[i] != '\0')
		i++;

	while (src[j] != '\0') {
		dst[i] = src[j];
		i++;
		j++;
	}

	dst[i] = '\0';
	return dst;
}

int my_atoi(const char *s)
{
	int result = 0;
	int sign   = 1;
	int i      = 0;

	while (s[i] == ' ')
		i++;

	if (s[i] == '-') {
		sign = -1;
		i++;
	} else if (s[i] == '+') {
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9') {
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return sign * result;
}

char* my_itoa(int num, char *str)
{
	int i    = 0;
	int sign = 1;

	if (num < 0) {
		sign = -1;
		num = -num;
	}

	if (num == 0) {
		str[i++] = '0';
		str[i]   = '\0';
		return str;
	}

	while (num > 0) {
		str[i++] = (num % 10) + '0';
		num /= 10;
	}

	if (sign == -1) str[i++] = '-';

	str[i] = '\0';

	int left = 0, right = i - 1;
	while (left < right) {
		str[left]  ^= str[right];
		str[right] ^= str[left];
		str[left]  ^= str[right];
		left++;
		right--;
	}

	return str;
}

void *my_memmove(void *dst, const void *src, int n)
{
	char *d = (char*)dst;
	char *s = (char*)src;

	if (d == s) return dst;

	if (d < s) {
		for (int i = 0; i < n; i++) {
			d[i] = s[i];
		}
	} else {
		for (int i = n - 1; i >= 0; i--) {
			d[i] = s[i];
		}
	}

	return dst;
}
/* ====== 测试函数 ====== */

void test_strlen()
{
	char s[64];
	printf("\n=== 测试 my_strlen ===\n");
	printf("请输入字符串：");
	scanf("%s", s);
	printf("my_strlen  = %d\n", my_strlen(s));
	printf("库函数strlen = %zu\n", strlen(s));
}

void test_strcpy()
{
	char src[64], dst[64];
	printf("\n=== 测试 my_strcpy ===\n");
	printf("请输入源字符串：");
	scanf("%s", src);
	my_strcpy(dst, src);
	printf("my_strcpy结果  = %s\n", dst);
	printf("库函数strcpy结果 = %s\n", src);
}

void test_strcat()
{
	char dst[128], src[64];
	printf("\n=== 测试 my_strcat ===\n");
	printf("请输入第一个字符串：");
	scanf("%s", dst);
	printf("请输入第二个字符串：");
	scanf("%s", src);
	printf("my_strcat结果 = %s\n", my_strcat(dst, src));
}

void test_atoi()
{
	char s[64];
	printf("\n=== 测试 my_atoi ===\n");
	printf("请输入数字字符串：");
	scanf("%s", s);
	printf("my_atoi  = %d\n", my_atoi(s));
	printf("库函数atoi = %d\n", atoi(s));
}

void test_itoa()
{
	int  num;
	char str[64];
	printf("\n=== 测试 my_itoa ===\n");
	printf("请输入整数：");
	scanf("%d", &num);
	printf("my_itoa结果 = %s\n", my_itoa(num, str));
}

void test_memmove()
{
	char buf[64];
	printf("\n=== 测试 my_memmove ===\n");
	printf("请输入字符串：");
	scanf("%s", buf);
	int len = strlen(buf);
	/* 测试重叠情况：将buf向后移动2位 */
	my_memmove(buf + 2, buf, len + 1);
	printf("向后移动2位结果 = %s\n", buf + 2);
}

/* ====== 主函数 ====== */

int main()
{
	int choice;

	while (1) {
		printf("\n====== 字符串函数测试 ======\n");
		printf("1. strlen\n");
		printf("2. strcpy\n");
		printf("3. strcat\n");
		printf("4. atoi\n");
		printf("5. itoa\n");
		printf("6. memmove\n");
		printf("0. 退出\n");
		printf("请选择：");
		scanf("%d", &choice);

		switch (choice) {
			case 1: test_strlen();  break;
			case 2: test_strcpy();  break;
			case 3: test_strcat();  break;
			case 4: test_atoi();    break;
			case 5: test_itoa();    break;
			case 6: test_memmove(); break;
			case 0:
				printf("退出程序\n");
				return 0;
			default:
				printf("无效输入\n");
		}
	}

	return 0;
}