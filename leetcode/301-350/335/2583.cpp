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
class Solution {
public:
	map<int,ll> sum;
	void dfs(TreeNode* root,int d) {
		if(root==NULL) return;
		sum[d]+=root->val;
		dfs(root->left,d+1);
		dfs(root->right,d+1);
	}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        sum.clear();
        dfs(root,0);
        vector<ll> A;
        FORR(s,sum) A.push_back(s.second);
        sort(ALL(A));
        reverse(ALL(A));
        if(k<=A.size()) return A[k-1];
        return -1;
        
    }
};
