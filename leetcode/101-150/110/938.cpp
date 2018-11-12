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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ret=0;
        if(root->val>=L && root->val<=R) ret=root->val;
        if(root->left) ret+=rangeSumBST(root->left,L,R);
        if(root->right) ret+=rangeSumBST(root->right,L,R);
        return ret;
    }
};
