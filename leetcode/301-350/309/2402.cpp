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

int C[101];
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
		ZERO(C);
		multiset<pair<ll,ll>> M;
		queue<ll> Q;
		set<int> A;
		
		int i;
		FOR(i,n) A.insert(i);
		
		FORR(a,meetings) {
			M.insert({a[0],100+a[1]});
		}
		while(M.size()) {
			auto m=*M.begin();
			ll x=m.second;
			M.erase(M.begin());
			if(x<100) {
				if(Q.size()) {
					M.insert({m.first+Q.front(),x});
					C[x]++;
					Q.pop();
				}
				else {
					A.insert(x);
				}
			}
			else {
				x-=100;
				if(A.empty()) {
					Q.push(x-m.first);
				}
				else {
					int cur=*A.begin();
					A.erase(cur);
					C[cur]++;
					M.insert({x,cur});
				}
			}
		}
		int ma=0;
		FOR(i,n) if(C[i]>C[ma]) ma=i;
		return ma;
        
    }
};
