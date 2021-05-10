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
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		vector<pair<int,int>> ev;
		vector<int> R(queries.size());
		FORR(a,intervals) {
			ev.push_back({a[0],-100000000+(a[1]-a[0]+1)});
			ev.push_back({a[1],100000000+(a[1]-a[0]+1)});
		}
		int i;
		FOR(i,queries.size()) ev.push_back({queries[i],i});
		sort(ALL(ev));
		multiset<int> S;
		FORR(x,ev) {
			int e=x.second;
			if(e<0) {
				e+=100000000;
				S.insert(e);
			}
			else if(e>1000000) {
				e-=100000000;
				S.erase(S.find(e));
			}
			else {
				if(S.empty()) R[e]=-1;
				else R[e]=*S.begin();
			}
		}
		return R;
		
        
    }
};
