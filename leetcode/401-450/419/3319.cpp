#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
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
 
vector<int> C;

class Solution {
public:
	int dfs(TreeNode* root) {
		if(!root) return -1;
		int p=dfs(root->left);
		int q=dfs(root->right);
		if(p==0||q==0||p!=q) return 0;
		if(p==-1) {
			C.push_back(1);
			return 1;
		}
		else {
			C.push_back(p*2+1);
			return p*2+1;
		}
		
	}
	
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
		C.clear();
		dfs(root);
		sort(ALL(C));
		reverse(ALL(C));
		if(k<=C.size()) return C[k-1];
		return -1;
        
    }
};
