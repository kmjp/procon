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
 vector<int> V[101010];
class Solution {
public:
	void dfs(TreeNode* root,int level) {
		if(!root) return;
		V[level].push_back(root->val);
		dfs(root->left,level+1);
		dfs(root->right,level+1);
	}
    bool isEvenOddTree(TreeNode* root) {
        int i;
        FOR(i,101010) V[i].clear();
        dfs(root,0);
        FOR(i,101010) if(V[i].size()>0) {
			if(i%2==0) {
				int pre=0;
				FORR(v,V[i]) {
					if(v%2==0) return 0;
					if(v<=pre) return 0;
					pre=v;
				}
			}
			else {
				int pre=1<<20;
				FORR(v,V[i]) {
					if(v%2) return 0;
					if(v>=pre) return 0;
					pre=v;
				}
			}
		}
        return 1;
    }
};

