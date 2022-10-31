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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int id;
int L[101010],R[101010];
int D[101010];
int ML[101010],MR[101010];
class Solution {
public:
	void dfs(TreeNode* root,int d) {
		if(root==NULL) return;
		D[id]=d;
		L[root->val]=id++;
		dfs(root->left,d+1);
		dfs(root->right,d+1);
		R[root->val]=id;
	}
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        id=1;
        dfs(root,0);
        int i;
        FOR(i,id) ML[i+1]=max(ML[i],D[i+1]);
        MR[id]=0;
        for(i=id-1;i>=1;i--) MR[i]=max(MR[i+1],D[i]);
        
        
        vector<int> V;
        FORR(q,queries) {
			V.push_back(max(ML[L[q]-1],MR[R[q]]));
		}
		return V;
    }
};
