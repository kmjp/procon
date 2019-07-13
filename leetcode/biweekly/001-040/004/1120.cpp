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

double ma;
class Solution {
	public:
	pair<int,double> hoge(TreeNode* root) {
		if(root==NULL) return {0,0};
		pair<int,double> P={1,root->val};
		pair<int,double> a=hoge(root->left);
		pair<int,double> b=hoge(root->right);
		P.first+=a.first+b.first;
		P.second+=a.second+b.second;
		
		ma=max(ma,P.second/P.first);
		return P;
		
	}
	
    double maximumAverageSubtree(TreeNode* root) {
        ma=0;
        
        hoge(root);
        return ma;
    }
};

