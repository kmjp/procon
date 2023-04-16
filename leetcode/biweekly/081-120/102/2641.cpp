#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 

map<int,ll> M;


class Solution {
public:
    void dfs(TreeNode* root,int d) {
		if(!root) return;
		M[d]+=root->val;
		dfs(root->left,d+1);
		dfs(root->right,d+1);
	}
    void dfs2(TreeNode* root,int d) {
		if(!root) return;
		ll sum=0;
		if(root->left) sum+=root->left->val;
		if(root->right) sum+=root->right->val;
		if(root->left)root->left->val=M[d+1]-sum;
		if(root->right)root->right->val=M[d+1]-sum;
		
		dfs2(root->left,d+1);
		dfs2(root->right,d+1);
	}
    TreeNode* replaceValueInTree(TreeNode* root) {
        M.clear();
        dfs(root,0);
        dfs2(root,0);
        root->val=0;
        return root;
    }
};
