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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<int,int> M;
class Solution {
public:
	void dfs(TreeNode* root,int depth) {
		if(!root) return;
		if(root->left==NULL && root->right==NULL) M[-depth]+=root->val;
		else {
			dfs(root->left,depth+1);
			dfs(root->right,depth+1);
		}
	}
    int deepestLeavesSum(TreeNode* root) {
        M.clear();
        dfs(root,0);
        return M.begin()->second;
    }
};

