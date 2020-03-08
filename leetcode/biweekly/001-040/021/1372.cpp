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
class Solution {
public:
	int ret;
	void dfs(TreeNode* root,int L,int R) {
		if(root==NULL) return;
		ret=max({ret,L+1,R+1});
		dfs(root->left,R+1,0);
		dfs(root->right,0,L+1);
	}
	
	
    int longestZigZag(TreeNode* root) {
        ret=1;
        dfs(root->left,1,0);
        dfs(root->right,0,1);
        return ret-1;
    }


}
