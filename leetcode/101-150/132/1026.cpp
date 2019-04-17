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

int ret;

class Solution {
public:
    void dfs(TreeNode* root,int mi,int ma) {
		if(!root) return;
		ret=max(ret,abs(root->val-mi));
		ret=max(ret,abs(root->val-ma));
		mi=min(mi,root->val);
		ma=max(ma,root->val);
        dfs(root->left,mi,ma);
        dfs(root->right,mi,ma);
	}
    int maxAncestorDiff(TreeNode* root) {
        ret=-1;
        dfs(root->left,root->val,root->val);
        dfs(root->right,root->val,root->val);
        return ret;
    }
};

