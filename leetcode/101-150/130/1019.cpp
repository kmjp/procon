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
    vector<int> nextLargerNodes(ListNode* head) {
		vector<int> V,R;
		while(head) {
			V.push_back(head->val);
			R.push_back(0);
			head=head->next;
		}
		
		set<pair<int,int>> S;
		int i;
		FOR(i,V.size()) {
			while(S.size()&&S.begin()->first<V[i]) {
				R[S.begin()->second]=V[i];
				S.erase(S.begin());
			}
			S.insert({V[i],i});
		}
		return R;
        
    }
};

