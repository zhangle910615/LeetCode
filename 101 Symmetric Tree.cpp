#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
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
class Solution {
    bool mirror(TreeNode* rt1,TreeNode* rt2){  /*To judge whether two trees are mirrors of each other*/
        if(rt1==NULL) return rt2==NULL;
        if(rt2==NULL) return false;
        if(rt1->val!=rt2->val) return false;
        return mirror(rt1->left,rt2->right)&&mirror(rt1->right,rt2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return mirror(root->left,root->right);
    }
};
int main(){
	TreeNode* root=NULL;
	BuildTree(root);
	Solution S;
	cout<<S.isSymmetric(root)<<endl;
	return 0;
}