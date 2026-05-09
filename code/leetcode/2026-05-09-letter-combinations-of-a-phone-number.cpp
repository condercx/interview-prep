#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	const string letterMap[10] = {
			"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
		};
public:
	vector<string> res;
	string s;
	void backtrack(const string &digits, int index) {
		if (index == digits.size()) {
			res.push_back(s);
			return;
		}

		int digit = digits[index] - '0';
		string letters = letterMap[digit];
		for (int i = 0; i < letters.size(); i++) {
			s.push_back(letters[i]);
			backtrack(digits, index + 1);
			s.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		backtrack(digits, 0);

		return res;
	}
};