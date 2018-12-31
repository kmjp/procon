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

	vector<int> dfs(TreeNode* root) {
		if(root->left==NULL) swap(root->right,root->left);
		// 0-camera 1-covered 2-not
		if(root->left==NULL) {
			return {1,101010,0};
		}
		else if(root->right==NULL) {
			auto a=dfs(root->left);
			
			return {min({a[0],a[1],a[2]})+1,a[0],a[1]};
		}
		else {
			auto a=dfs(root->left);
			auto b=dfs(root->right);
			
			return {
				min({a[0],a[1],a[2]})+min({b[0],b[1],b[2]})+1,
				min({a[0]+b[0],a[0]+b[1],a[1]+b[0]}),
				a[1]+b[1]
			};
			
		}
		
		
	}
    int minCameraCover(TreeNode* root) {
        auto a=dfs(root);
        return min(a[0],a[1]);
    }
};
