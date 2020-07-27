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
class Solution {
public:
	int ret,D;
	map<int,int> hoge(TreeNode* root) {
		map<int,int> M;
		if(root->left==NULL&&root->right==NULL) {
			M[0]=1;
		}
		else if(root->left==NULL) {
			map<int,int> V=hoge(root->right);
			FORR(v,V) M[v.first+1]=v.second;
		}
		else if(root->right==NULL) {
			map<int,int> V=hoge(root->left);
			FORR(v,V) M[v.first+1]=v.second;
		}
		else {
			map<int,int> A=hoge(root->left);
			map<int,int> B=hoge(root->right);
			FORR(a,A) FORR(b,B) if(a.first+b.first+2<=D) ret+=a.second*b.second;
			FORR(v,A) M[v.first+1]+=v.second;
			FORR(v,B) M[v.first+1]+=v.second;
		}
		return M;
	}
	
    int countPairs(TreeNode* root, int distance) {
		ret=0;
		D=distance;
        hoge(root);
        return ret;
    }
};
