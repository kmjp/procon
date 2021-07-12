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
TreeNode* leaf[505050];
int numv;
class Solution {
public:
	void dfs(TreeNode* root,int isr) {
		if(!root) return;
		numv++;
		if(root->left==NULL&&root->right==NULL&&!isr) leaf[root->val]=root;
		dfs(root->left,0);
		dfs(root->right,0);
	}
	int isvalid(TreeNode* root,int L,int R) {
		if(!root) return 1;
		numv--;
		if(root->val<L||root->val>R) return 0;
		return isvalid(root->left,L,root->val-1)&isvalid(root->right,root->val+1,R);
		
	}
	
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int i;
        int N=trees.size();
        FOR(i,505050) leaf[i]=NULL;
        numv=0;
        FOR(i,N) dfs(trees[i],1);
		vector<int> ref;
		FOR(i,N) {
			if(!leaf[trees[i]->val]) ref.push_back(i);
		}
		if(ref.size()>1) return NULL;
		if(ref.size()==0) return NULL;
		FOR(i,N) {
			if(leaf[trees[i]->val]) {
				numv--;
				if(trees[i]->left) {
					leaf[trees[i]->val]->left=trees[i]->left;
				}
				if(trees[i]->right) {
					leaf[trees[i]->val]->right=trees[i]->right;
				}
			}
		}
		if(isvalid(trees[ref[0]],0,1<<20)&&numv==0) return trees[ref[0]];
		return NULL;
    }
};
