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
	void dfs(TreeNode* root,vector<int>& V) {
		if(root) {
			V.push_back(root->val);
			dfs(root->left,V);
			dfs(root->right,V);
		}
	}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> V;
		dfs(root1,V);
		dfs(root2,V);
        sort(ALL(V));
        return V;
    }
};

