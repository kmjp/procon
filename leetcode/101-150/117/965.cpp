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
	set<int> S;
	void walk(TreeNode* root) {
		if(root==NULL) return;
		S.insert(root->val);
		walk(root->left);
		walk(root->right);
		
	}
    bool isUnivalTree(TreeNode* root) {
        S.clear();
        walk(root);
        return S.size()==1;
    }
};
