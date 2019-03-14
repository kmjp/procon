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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode* root=new TreeNode(preorder[0]);
		FORR(p,preorder) if(p!=preorder[0]) {
			TreeNode* cur=root;
			while(1) {
				if(p<cur->val) {
					if(cur->left==NULL) {
						cur->left=new TreeNode(p);
						break;
					}
					cur=cur->left;
				}
				else {
					if(cur->right==NULL) {
						cur->right=new TreeNode(p);
						break;
					}
					cur=cur->right;
				}
			}
			
		}
		return root;
        
    }
};
