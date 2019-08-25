
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

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
		vector<int> V;
		ListNode* base=head;
		while(head) {
			V.push_back(head->val);
			while(V.size()) {
				int sum=0;
				int i;
				for(i=V.size()-1;i>=0;i--) {
					sum+=V[i];
					if(sum==0) break;
				}
				if(i==-1) break;
				V.resize(i);
			}
			head=head->next;
		}
		if(V.empty()) return NULL;
		head=base;
		int i;
		FOR(i,V.size()) {
			base->val=V[i];
			if(i==V.size()-1) {
				base->next=NULL;
			}
			else {
				base=base->next;
			}
		}
		return head;
        
    }
};
