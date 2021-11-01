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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> V;
        while(head) {
			V.push_back(head->val);
			head=head->next;
		}
		int i;
		vector<int> B;
		for(i=1;i<(int)V.size()-1;i++) {
			if(V[i-1]<V[i]&&V[i]>V[i+1]) B.push_back(i);
			if(V[i-1]>V[i]&&V[i]<V[i+1]) B.push_back(i);
		}
		if(B.size()<2) {
			return {-1,-1};
		}
		else {
			int mi=1<<30;
			FOR(i,B.size()-1) mi=min(mi,B[i+1]-B[i]);
			return {mi,B.back()-B[0]};
		}
    }
};
