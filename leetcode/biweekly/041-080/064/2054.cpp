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
    int maxTwoEvents(vector<vector<int>>& events) {
        ll ma=0;
        multiset<ll> L,R;
        L.insert(0);
        R.insert(0);
        vector<pair<int,ll>> V;
        FORR(a,events) {
			R.insert(a[2]);
			ma=max(ma,(ll)a[2]);
			V.push_back({a[0],-a[2]});
			V.push_back({a[1],a[2]});
		}
        sort(ALL(V));
        FORR(a,V) {
			if(a.second<0) {
				R.erase(R.find(-a.second));
			}
			else {
				L.insert(a.second);
			}
			ma=max(ma,(ll)*R.rbegin()+*L.rbegin());
		}
		return ma;
    }
};
