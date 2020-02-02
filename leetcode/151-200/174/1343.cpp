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
	vector<ll> V;
	ll hoge(TreeNode* root) {
		ll sum=root->val;
		if(root->left) sum+=hoge(root->left);
		if(root->right) sum+=hoge(root->right);
		V.push_back(sum);
		return sum;
	}
    int maxProduct(TreeNode* root) {
		V.clear();
		ll sum=hoge(root);
		
		ll ma=0;
		FORR(s,V) ma=max(ma,s*(sum-s));
		return ma%1000000007;
        
    }
};

