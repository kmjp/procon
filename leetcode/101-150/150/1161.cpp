
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

int num[10100];
int sum[10100];

class Solution {
public:

	void dfs(TreeNode* root,int l) {
		if(root==NULL) return;
		num[l]++;
		sum[l]+=root->val;
		dfs(root->left,l+1);
		dfs(root->right,l+1);
	}
    int maxLevelSum(TreeNode* root) {
        ZERO(num);
        ZERO(sum);
        dfs(root,1);
        int mi=-1000000001;
        int id=0;
        int i;
        FOR(i,10010) if(num[i] && sum[i]>mi) mi=sum[i],id=i;
        return id;
    }

};

