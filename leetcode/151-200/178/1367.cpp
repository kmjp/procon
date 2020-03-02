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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool result;
    void go2(ListNode* head, TreeNode* root) {
		if(root->val!=head->val) return;
		head=head->next;
		if(head==NULL) {
			result=true;
			return;
		}
		if(root->left) go2(head,root->left);
		if(root->right) go2(head,root->right);
		
	}
    
    void go(ListNode* head, TreeNode* root) {
		go2(head,root);
		if(root->left) go(head,root->left);
		if(root->right) go(head,root->right);
	}
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        result=false;
        go(head,root);
        return result;
    }
};

