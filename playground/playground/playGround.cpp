#include"common_def.h"

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int str_length = s.size();
		printf("%d\n", str_length);
		if (str_length == 0) {
			return;
		}
		char tmp;
		for (int i = 0; i<str_length; ++i) {
			tmp = s[i];
			s[i] = s[str_length - 1 - i];
			s[str_length - 1 - i] = tmp;
		}
	}

	void printVector(const vector<char> & str) {
		for (int i = 0; i < str.size(); ++i) {
			printf("%c",str[i]);
		}
		printf("\n");
	}
};


void main()
{
	char pre_array[] = { "hello" };
	std::vector<char> rotateArray(std::begin(pre_array), std::end(pre_array)-1);
	Solution mySol;

	mySol.reverseString(rotateArray);
	mySol.printVector(rotateArray);

}

