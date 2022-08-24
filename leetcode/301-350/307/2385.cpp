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
 
vector<int> E[101001];
int ma=0;
class Solution {
public:
	void dfs(TreeNode* root,int pre) {
		if(root==NULL) return;
		if(pre>=0) {
			E[root->val].push_back(pre);
			E[pre].push_back(root->val);
		}
		dfs(root->left,root->val);
		dfs(root->right,root->val);
	}
	void dfs2(int cur,int pre,int d) {
		ma=max(ma,d);
		FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,d+1);
	}

    int amountOfTime(TreeNode* root, int start) {
        int i;
        FOR(i,100001) E[i].clear();
        ma=0;
        dfs(root,-1);
        dfs2(start,start,0);
        return ma;
    }
};
