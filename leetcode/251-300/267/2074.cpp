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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
		vector<int> V;
		ListNode* r=head;
		while(r) {
			V.push_back(r->val);
			r=r->next;
		}
		int cur=0;
		for(int i=1;i<=500;i++) {
			int s=min(i,(int)V.size()-cur);
			if(s>0&&s%2==0) {
				reverse(V.begin()+cur,V.begin()+min(cur+i,(int)V.size()));
			}
			cur+=i;
		}
		reverse(ALL(V));
		r=head;
		while(r) {
			r->val=V.back();
			V.pop_back();
			r=r->next;
		}
		return head;
        
    }
};
