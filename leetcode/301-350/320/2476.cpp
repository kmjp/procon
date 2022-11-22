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
set<int> S;
class Solution {
public:
	void dfs(TreeNode* root) {
		if(!root) return;
		S.insert(root->val);
		dfs(root->left);
		dfs(root->right);
	}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        S.clear();
        dfs(root);
        vector<vector<int>> ret;
        FORR(a,queries) {
			vector<int> R={-1,-1};
			auto it=S.lower_bound(a);
			
			if(it!=S.end()&&*it==a) {
				R[0]=R[1]=a;
			}
			else {
				if(it!=S.end()) R[1]=*it;
				if(it!=S.begin()) R[0]=*--it;
			}
			ret.push_back(R);
		}
		return ret;
    }
};
