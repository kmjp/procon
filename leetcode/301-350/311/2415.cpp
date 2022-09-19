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
 vector<TreeNode*> V[20];
class Solution {
public:
	
    TreeNode* dfs(TreeNode* root,int level) {
		if(root==NULL) return NULL;
		V[level].push_back(root);
		dfs(root->left,level+1);
		dfs(root->right,level+1);
		return root;
	}
    TreeNode* reverseOddLevels(TreeNode* root) {
		int i;
		FOR(i,20) V[i].clear();
		dfs(root,0);
		for(i=1;i<20;i+=2) if(V[i].size()) {
			vector<int> A;
			FORR(a,V[i]) A.push_back(a->val);
			reverse(ALL(V[i]));
			int j;
			FOR(j,V[i].size()) V[i][j]->val=A[j];
		}
		return root;
		
		
    }
};
