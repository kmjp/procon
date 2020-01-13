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
    void dfs(TreeNode* root,int a,int b) {
		if(!root) return;
		if(a==0) ret+=root->val;
		
		dfs(root->left,b,root->val%2);
		dfs(root->right,b,root->val%2);
	}
    
    int sumEvenGrandparent(TreeNode* root) {
        ret=0;
        dfs(root,1,1);
        return ret;
    }
};
