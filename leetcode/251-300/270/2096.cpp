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

string A,B;
class Solution {
public:
	int s,d;
	string S;
	void traverse(TreeNode* root) {
		
		if(root->val==s) A=S;
		if(root->val==d) B=S;
		
		if(root->left) {
			S+="L";
			traverse(root->left);
		}
		if(root->right) {
			S+="R";
			traverse(root->right);
		}
		
		S.pop_back();
	}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        s=startValue;
        d=destValue;
        S="L";
        traverse(root);
        
        reverse(ALL(A));
        reverse(ALL(B));
        while(A.size()&&B.size()&&A.back()==B.back()) {
			A.pop_back();
			B.pop_back();
		}
		FORR(c,A) c='U';
		reverse(ALL(B));
		return A+B;
        
    }
};
