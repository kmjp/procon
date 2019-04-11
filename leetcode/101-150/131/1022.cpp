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

ll ret;
ll mo=1000000007;

class Solution {
public:
	void hoge(TreeNode* root, ll v) {
		if(root==NULL) return;
		v=(v*2+root->val)%mo;
		if(root->left==NULL && root->right==NULL) {
			ret+=v;
		}
		else {
			hoge(root->left,v);
			hoge(root->right,v);
		}
	}
    int sumRootToLeaf(TreeNode* root) {
        ret=0;
        hoge(root,0);
        return ret%mo;
    }
};

