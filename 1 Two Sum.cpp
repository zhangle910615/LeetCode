#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int,int> imap;
		for (int i = 0;i < (int)nums.size();++i) {
			imap[nums[i]] = i;
		}
		for (int i = 0;i <(int) nums.size();++i) {
			int x = target - nums[i];
			if (imap.find(x) != imap.end() && imap[x]>0) {
				result.push_back(i + 1);
				result.push_back(imap[x] + 1);
				break;
			}
		}
		return result;
	}
};
void main() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	int target = 9;
	Solution s;
	cout << (s.twoSum(nums, target))[0] << endl;
	cout << (s.twoSum(nums, target))[1] << endl;
}