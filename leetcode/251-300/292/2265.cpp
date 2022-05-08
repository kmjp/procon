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
class Solution {
public:
	int ret=0;
	pair<int,int> dfs(TreeNode* root) {
		int a=1;
		int b=root->val;
		if(root->left) {
			auto c=dfs(root->left);
			a+=c.first;
			b+=c.second;
		}
		if(root->right) {
			auto c=dfs(root->right);
			a+=c.first;
			b+=c.second;
		}
		if(root->val==b/a) ret++;
		return {a,b};
	}
    int averageOfSubtree(TreeNode* root) {
        ret=0;
        dfs(root);
        return ret;
    }
};