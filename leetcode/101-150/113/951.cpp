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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2==NULL) return 0;
        if(root2 && root1==NULL) return 0;
        if(root1==NULL && root2==NULL) return 1;
        if(root1->val != root2->val) return 0;
        
        if(root1->left==NULL && root1->right!=NULL) swap(root1->left,root1->right);
        if(root1->left && root1->right && root1->left->val>root1->right->val) swap(root1->left,root1->right);
        if(root2->left==NULL && root2->right!=NULL) swap(root2->left,root2->right);
        if(root2->left && root2->right && root2->left->val>root2->right->val) swap(root2->left,root2->right);
        
        return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
    }
};
