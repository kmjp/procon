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
    vector<pair<int,int>> V[2020];
    
    void dfs(TreeNode* root,int id,int h) {
		if(root==NULL) return;
		V[id].push_back({h,root->val});
		dfs(root->left,id-1,h+1);
		dfs(root->right,id+1,h+1);
	}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
		int i;
		FOR(i,2020) V[i].clear();
		dfs(root,1001,0);
		
		vector<vector<int>> R;
		FOR(i,2020) if(V[i].size()) {
			sort(ALL(V[i]));
			vector<int> V2;
			FORR(v,V[i]) V2.push_back(v.second);
			R.push_back(V2);
		}
		return R;
		
    }
};
