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
	vector<TreeNode*> R;
	set<int> S;
	TreeNode* dfs(TreeNode* root,int remain) {
		if(root==NULL) return NULL;
		if(S.count(root->val)) {
			dfs(root->left,0);
			dfs(root->right,0);
		}
		else {
			if(remain==0) R.push_back(root);
			root->left=dfs(root->left,1);
			root->right=dfs(root->right,1);
		}
		
		if(S.count(root->val)) return NULL;
		return root;
	}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		S.clear();
		FORR(v,to_delete) S.insert(v);
        set<int> S(ALL(to_delete));
        R.clear();
        dfs(root,0);
        return R;
    }
};

