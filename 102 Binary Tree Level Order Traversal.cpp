#include <iostream>
#include <vector>
#include <queue>
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
class Solution {
    int deep(TreeNode *rt){          //compute the depth of the tree
        if(!rt) return 0;
        return max(deep(rt->left),deep(rt->right))+1;
    }
    void mapping(TreeNode *rt,vector<vector<int> > &rst,int lev){  //use lev to denote the corrent level of the node
        if(!rt) return;
        rst[lev].push_back(rt->val);
        mapping(rt->left,rst,lev+1);
        mapping(rt->right,rst,lev+1);
        return;
    }                                                        
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = deep(root);
        vector<vector<int> > rst(height);
        mapping(root,rst,0);
        return rst;
    }
};
int main(){
	TreeNode *root=NULL;
	BuildTree(root);
	Solution S;
	vector<vector<int>> iv;
	iv=S.levelOrder(root);
	for(auto &p:iv){
		for(auto q:p)
			cout<<q<<"\t"
		cout<<endl;
	}

	return 0;
}