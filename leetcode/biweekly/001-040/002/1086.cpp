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

vector<int> S[1010];

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int i;
        FOR(i,1001) S[i].clear();
        FORR(v,items) S[v[0]].push_back(v[1]);
        vector<vector<int>> R;
        FOR(i,1001) if(S[i].size()>=5) {
			sort(ALL(S[i]));
			reverse(ALL(S[i]));
			int x=S[i][0]+S[i][1]+S[i][2]+S[i][3]+S[i][4];
			R.push_back({i,x/5});
		}
		return R;
        
    }
};

