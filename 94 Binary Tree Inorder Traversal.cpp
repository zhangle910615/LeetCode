#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void BuildTree(TreeNode* &root){
		int ch;
		cin>>ch;
		if(ch==-1) root=NULL;
		else{
				root=new TreeNode(ch);
				BuildTree(root->left);
				BuildTree(root->right);
		}
}
class Solution{
public:
		vector<int> inorderTraversal(TreeNode* root){
				vector<int> vec;
				stack<TreeNode*> St;
				TreeNode* p=root;
				while(p!=NULL || !St.empty()){
						while(p!=NULL){
							St.push(p);
							p=p->left;
						}
						if(!St.empty()){
							p=St.top();
							vec.push_back(p->val);
							St.pop();
							p=p->right;
						}
				}
				return vec;
		}
};
int main(){
			TreeNode* root=NULL;
			BuildTree(root);	
			Solution S;
			vector<int> iv;
			iv=S.inorderTraversal(root);
			for(auto i:iv)
					cout<<i<<"\t";
			cout<<endl;
			return 0;
}
