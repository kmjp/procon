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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		if(root==NULL) {
			root=new TreeNode(0);
			root->val=val;
			root->left=root->right=NULL;
			return root;
		}
		if(val>root->val) {
			TreeNode* nr=new TreeNode(0);
			*nr=*root;
			root->val=val;
			root->left=nr;
			root->right=NULL;
			return root;
		}
		root->right=insertIntoMaxTree(root->right,val);
		return root;
        
    }
};
