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
    vector<int> frequencySort(vector<int>& nums) {
		map<int,int> M;
		FORR(n,nums) M[n]++;
		vector<pair<int,int>> V;
		FORR(m,M) V.push_back({m.second,-m.first});
		sort(ALL(V));
		vector<int> R;
		FORR(v,V) {
			int i;
			FOR(i,v.first) R.push_back(-v.second);
		}
        return R;
    }
};

