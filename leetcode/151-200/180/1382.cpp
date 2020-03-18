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



class Solution {
public:
	vector<int> V;
	void dfs(TreeNode* root) {
		if(root==NULL) return;
		V.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}
	
	TreeNode* hoge(int L,int R) {
		if(L>=R) return NULL;
		int M=(L+R)/2;
		TreeNode* root=new TreeNode();
		root->val=V[M];
		root->left=hoge(L,M);
		root->right=hoge(M+1,R);
		return root;
	}
	
    TreeNode* balanceBST(TreeNode* root) {
        V.clear();
        dfs(root);
        sort(ALL(V));
        return hoge(0,V.size());
    }
};

