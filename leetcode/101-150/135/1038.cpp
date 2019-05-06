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


vector<int> V;

class Solution {
public:
	void dfs(TreeNode* root) {
		if(!root) return;
		V.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}
	void dfs2(TreeNode* root) {
		if(!root) return;
		int sum=0;
		FORR(v,V) if(v>=root->val) sum+=v;
		root->val=sum;
		dfs2(root->left);
		dfs2(root->right);
	}
    TreeNode* bstToGst(TreeNode* root) {
        V.clear();
        dfs(root);
        dfs2(root);
        return root;
    }
};
