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
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		int ma=0;
		map<int,int> M;
		sort(ALL(items));
		M[0]=0;
		FORR(a,items) {
			ma=max(ma,a[1]);
			M[a[0]]=max(M[a[0]],ma);
		}
		vector<int> R;
		FORR(a,queries) {
			auto it=M.lower_bound(a+1);
			it--;
			R.push_back(it->second);
		}
        return R;
    }
};
