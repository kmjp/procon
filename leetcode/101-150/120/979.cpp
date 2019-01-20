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
	int ret;
	pair<int,int> count(TreeNode* root) {
		pair<int,int> A={1,root->val};
		if(root->left) {
			auto a=count(root->left);
			A.first+=a.first;
			A.second+=a.second;
		}
		if(root->right) {
			auto a=count(root->right);
			A.first+=a.first;
			A.second+=a.second;
		}
		ret+=abs(A.first-A.second);
		return A;
	}
	
    int distributeCoins(TreeNode* root) {
		ret=0;
        count(root);
        return ret;
    }
};
