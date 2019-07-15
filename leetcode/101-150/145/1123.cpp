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
    pair<int,TreeNode*> hoge(TreeNode* root, int depth) {
		if(root->left==NULL&root->right==NULL) {
			return {depth, root};
		}
		else if(root->left==NULL) {
			return hoge(root->right,depth+1);
		}
		else if(root->right==NULL) {
			return hoge(root->left,depth+1);
		}
		else {
			auto a=hoge(root->left,depth+1);
			auto b=hoge(root->right,depth+1);
			
			if(a.first>b.first) return a;
			if(a.first<b.first) return b;
			return {a.first, root};
		}
		
	}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return hoge(root,0).second;
    }
};

