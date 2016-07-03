//Calculate the sum of two integers a and b, 
//but you are not allowed to use the operator + and -.
//http://blog.csdn.net/shenzhu0127/article/details/51810349
#include <iostream>
using namespace std;
class Solution {
public:
	int getSum(int a, int b) {
		if (b == 0) return a;
		int sum = a ^ b;
		int carry = (a & b) << 1;
		return getSum(sum, carry);
	}
};
int main(){
	Solution s;
	cout << s.getSum(3, 4) << endl;
	cin.get();
	return 0;
}