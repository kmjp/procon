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


TreeNode tree[101010];

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		set<int> C;
        FORR(v,descriptions) {
			tree[v[0]].left=tree[v[0]].right=NULL;
			tree[v[1]].left=tree[v[1]].right=NULL;
		}
        FORR(v,descriptions) {
			tree[v[0]].val=v[0];
			tree[v[1]].val=v[1];
			if(v[2]==0) {
				tree[v[0]].right=&tree[v[1]];
			}
			else {
				tree[v[0]].left=&tree[v[1]];
			}
			C.insert(v[1]);
			
		}
        FORR(v,descriptions) {
			if(C.count(v[0])==0) return &tree[v[0]];
		}
		return NULL;
    }
};
