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





class FindElements {
public:
	set<int> S;
	void hoge(TreeNode* root,int v) {
		if(!root) return;
		S.insert(v);
        hoge(root->left,v*2+1);
        hoge(root->right,v*2+2);
	}
    FindElements(TreeNode* root) {
		S.clear();
		S.insert(0);
        root->val=0;
        hoge(root->left,1);
        hoge(root->right,2);
    }
    
    bool find(int target) {
        return S.count(target);
    }
};

