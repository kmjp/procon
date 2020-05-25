typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
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
int ret;
class Solution {
public:
	void go(TreeNode* root,int mask) {
		mask ^= 1<<(root->val);
		if(root->left) go(root->left,mask);
		if(root->right) go(root->right,mask);
		if(root->left==NULL&&root->right==NULL) {
			if(__builtin_popcount(mask)<=1) ret++;
		}
	}
    int pseudoPalindromicPaths (TreeNode* root) {
        ret=0;
        go(root,0);
        return ret;
    }
}

