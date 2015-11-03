#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *tail = new ListNode(0);
		ListNode *l3 = tail;
		while (l1!=NULL || l2!=NULL) {
			int val1 = 0;
			if (l1 != NULL) {
				val1 = l1->val;
				l1 = l1->next;
			}
			int val2 = 0;
			if (l2 != NULL) {
				val2 = l2->val;
				l2 = l2->next;
			}
			int temp = val1 + val2 + carry;
			l3->next = new ListNode(temp % 10);
			carry = temp / 10;
			l3 = l3->next;
		}
		if (carry > 0)
			l3->next = new ListNode(carry);
		return tail->next;
	}
};
void main() {
	ListNode* l1=new ListNode(2);
	ListNode* l2=new ListNode(5);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution s;
	ListNode *l3 = new ListNode(-1);
	l3=s.addTwoNumbers(l1, l2);
	while (l3) {
		cout << l3->val;
		if (l3->next != NULL)
			cout << "->";
		l3 = l3->next;
	}
	cout << endl;
}