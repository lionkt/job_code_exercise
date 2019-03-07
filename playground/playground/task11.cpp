#include"common_def.h"

using namespace std;


class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		if (rotateArray.size() == 1)
			return rotateArray[0];
		int leftIx = 0, rightIx = rotateArray.size() - 1;
		int midIx = leftIx;

		//特殊情况处理
		if (rotateArray[0]<rotateArray[rightIx])
			return rotateArray[0];

		//正常情况处理
		while (rotateArray[leftIx] >= rotateArray[rightIx]) {

			//判断终止
			if (rightIx - midIx == 1) {
				midIx = rightIx;
				return rotateArray[midIx];
			}

			midIx = int((leftIx + rightIx) / 2);

			//左中右都一样
			if (rotateArray[leftIx] == rotateArray[rightIx] &&
				rotateArray[leftIx] == rotateArray[midIx]) {
				return sequenceSearch(rotateArray);
			}
			//不一样
			if (rotateArray[leftIx]<=rotateArray[midIx]) {
				leftIx = midIx;
			}
			if (rotateArray[midIx]<=rotateArray[rightIx]) {
				rightIx = midIx;
			}

		}
		return rotateArray[midIx];
	}

	int sequenceSearch(const vector<int> &data) {
		int res = 32767;
		for (int i = 0; i<data.size(); ++i) {
			if (res>data[i])
				res = data[i];
		}
		return res;
	}


};

void _t11main()
{
	//int pre_array[] = { 1,2,3,4,5,6,7,8 };
	int pre_array[] = { 1,2,3,4,5,6,7,8 };

	//int pre_array[] = { 1,0,1,1,1 };

	std::vector<int> rotateArray(std::begin(pre_array), std::end(pre_array));
	
	Solution mySol;
	int res = mySol.minNumberInRotateArray(rotateArray);
	printf("%d\n", res);

}