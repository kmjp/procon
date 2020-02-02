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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,mat.size()) {
			int c=0;
			FORR(m,mat[i]) c+=m;
			V.push_back({c,i});
		}
		sort(ALL(V));
		vector<int> R;
		FOR(i,k) R.push_back(V[i].second);
		return R;
        
    }
};

