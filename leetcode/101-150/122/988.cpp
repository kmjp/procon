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
	vector<string> S;
	
	void dfs(TreeNode* root,string s) {
		if(root==NULL) return;
		s+=(char)('a'+root->val);
		
		if(root->left||root->right) {
			dfs(root->left,s);
			dfs(root->right,s);
		}
		else {
			S.push_back(s);
		}
	}
    string smallestFromLeaf(TreeNode* root) {
        S.clear();
        dfs(root,"");
        FORR(s,S) reverse(ALL(s));
        sort(ALL(S));
        return S[0];
    }
};
