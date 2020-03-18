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
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> V;
        int i;
        FOR(i,n) V.push_back({efficiency[i],speed[i]});
        sort(ALL(V));
        reverse(ALL(V));
        multiset<ll> S;
        ll ret=0;
        ll sum=0;
        FOR(i,n) {
			S.insert(V[i].second);
			sum+=V[i].second;
			if(S.size()>k) {
				sum-=*S.begin();
				S.erase(S.begin());
			}
			ret=max(ret,V[i].first*sum);
		}
		return ret%1000000007;
    }
};

