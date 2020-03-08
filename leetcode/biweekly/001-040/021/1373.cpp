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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    ll ret;
    vector<ll> dfs(TreeNode* root) {
		ll now=root->val;
		ll mi=root->val;
		ll ma=root->val;
		
		if(root->left) {
			auto V=dfs(root->left);
			if(mi==1LL<<60 || V[0]==1LL<<60 || V[1]>=mi) mi=(1LL<<60),ma=-(1LL<<60);
			else mi=min(mi,V[0]);
			now+=V[2];
		}
		if(root->right) {
			auto V=dfs(root->right);
			if(mi==1LL<<60 || V[0]==1LL<<60 || V[0]<=ma) mi=(1LL<<60),ma=-(1LL<<60);
			else ma=max(ma,V[1]);
			now+=V[2];
		}
		
		if(mi<=ma) ret=max(ret,now);
		//cout<<root->val<<" "<<mi<<" "<<ma<<" "<<now<<endl;
		return {mi,ma,now};
	}
    
    int maxSumBST(TreeNode* root) {
        ret=0;
        dfs(root);
        return ret;
    }
};

