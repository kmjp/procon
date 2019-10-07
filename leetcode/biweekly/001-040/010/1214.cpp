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

set<int> A,B;

class Solution {
public:
    void dfs(TreeNode* root,set<int> & A) {
		if(root==NULL) return;
		A.insert(root->val);
		dfs(root->left,A);
		dfs(root->right,A);
	}
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        A.clear();
        B.clear();
        dfs(root1,A);
        dfs(root2,B);
        FORR(a,A) {
			if(B.count(target-a)) return 1;
		}
		return 0;
        
    }
};
