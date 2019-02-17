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


int P[101];
int D[101];

class Solution {
public:
	void dfs(int p, TreeNode* root) {
		if(root==NULL) return;
		P[root->val]=p;
		if(p==-1) D[root->val]=0;
		else D[root->val]=D[p]+1;
		dfs(root->val,root->left);
		dfs(root->val,root->right);
		
	}
    bool isCousins(TreeNode* root, int x, int y) {
		int i;
		FOR(i,101) P[i]=i;
		dfs(-1,root);
		
		return (P[x]!=P[y] && D[x]==D[y]);
		
    }
};
