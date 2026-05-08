#include <bits/stdc++.h>
using namespace std;

//dp解法
class Solution {
public:
	string longestPalindrome(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		int maxLen = 0, left = 0;

		for (int i = s.size(); i >= 0; i--) {
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
					dp[i][j] = true;
				}

				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					left = i;
				}
			}
		}

		return s.substr(left, maxLen);
	}
};

//双指针
class Solution {
public:
	int left, maxLen = 0;
	void extend(string &s, int i, int j, int n) {
		while (i >= 0 && j < n && s[i] == s[j]) {
			if (j - i + 1 > maxLen) {
				left = i;
				maxLen = j - i + 1;
			}
			i--;
			j++;
		}
	}
	string longestPalindrome(string s) {
		for (int i = 0; i < s.size(); i++) {
			extend(s, i, i, s.size());
			extend(s, i, i + 1, s.size());
		}

		return s.substr(left, maxLen);
	}
};

//Manacher 算法
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "#";

		for (char c : s) {
			t += c;
			t += "#";
		}
		int n = t.size();
		vector<int> p(n, 0);
		int center = 0, right = 0;

		for (int i = 0; i < n; i++) {
			if (i < right) {
				p[i] = min(right - i, p[2 * center - i]);
			}

			while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
				p[i]++;
			}

			if (i + p[i] > right) {
				center = i;
				right = i + p[i];
			}
		}

		int maxLen = 0, centerIndex = 0;

		for (int i = 0; i < n; i++) {
			if (p[i] > maxLen) {
				maxLen = p[i];
				centerIndex = i;
			}
		}

		return s.substr((centerIndex - maxLen) / 2, maxLen);
	}
};