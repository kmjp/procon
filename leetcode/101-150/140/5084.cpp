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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
		limit-=root->val;
		
		if(root->left==NULL && root->right==NULL) {
			if(limit>0) return NULL;
		}
		else {
			if(root->left) root->left=sufficientSubset(root->left,limit);
			if(root->right) root->right=sufficientSubset(root->right,limit);
			if(root->left==NULL && root->right==NULL) return NULL;
		}
		return root;
    }
};

