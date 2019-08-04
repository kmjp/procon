
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


vector<int> C;
int X;
class Solution {
public:
	int hoge(TreeNode* root,int x) {
		if(root->val==x) {
			if(root->left) C.push_back(hoge(root->left,x));
			if(root->right) C.push_back(hoge(root->right,x));
			return 0;
		}
		else {
			int c=1;
			if(root->left) c+=hoge(root->left,x);
			if(root->right) c+=hoge(root->right,x);
			return c;
		}
		
	}

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        C.clear();
        X=x;
        hoge(root,x);
        int lef=n-1;
        FORR(c,C) lef-=c;
        C.push_back(lef);
        
        FORR(c,C) if(c*2>=n) return 1;
        return 0;
        
        
    }



};

