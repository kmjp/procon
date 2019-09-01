
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

int mask[101010];

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int i,N=s.size();
        mask[0]=0;
        FOR(i,N) {
			mask[i+1]=mask[i];
			mask[i+1]^=1<<(s[i]-'a');
		}
		
		vector<bool> R;
		FORR(q,queries) {
			int nm=mask[q[1]+1]^mask[q[0]];
			int odd=__builtin_popcount(nm);
			R.push_back(odd<=q[2]*2+1);
			
		}
		return R;
        
    }
};



