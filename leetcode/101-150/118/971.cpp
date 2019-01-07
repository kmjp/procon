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
	void dfs(TreeNode* root, vector<int>& R,vector<int>& V,int& id) {
		if(root==NULL) return;
		if(V[id]!=root->val) {
			R={-1};
			return;
		}
		
		id++;
		
		if(root->left && root->right && root->right->val==V[id]) {
			R.push_back(root->val);
			swap(root->left,root->right);
		}
		
		dfs(root->left,R,V,id);
		if(R.size() && R[0]==-1) return;
		dfs(root->right,R,V,id);
		
	}
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> R;
        int id=0;
        dfs(root,R,voyage,id);
        return R;
    }
};
