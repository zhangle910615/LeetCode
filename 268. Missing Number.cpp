//注意：序列一定是从0开始的，可以逆序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int t = 0;
		for (int n : nums){
			t += n;
		}
		return nums.size()*(nums.size() + 1) / 2 - t;
	}
};
int main(){
	int a[2] = { 2,0};
	vector<int> nums(begin(a), end(a));
	Solution S;
	cout << S.missingNumber(nums);
	cin.get();
	return 0;
}