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

const ll mo=1000000007;


class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> cand={{0},{1},{2}};
        int i,j;
        for(i=2;i<=m;i++) {
			vector<vector<int>> A;
			FORR(c,cand) {
				FOR(j,3) if(c.back()!=j) {
					A.push_back(c);
					A.back().push_back(j);
				}
			}
			
			swap(cand,A);
		}
		
		vector<pair<vector<int>,vector<int>>> C;
		FORR(c,cand) FORR(d,cand) {
			int i;
			FOR(i,c.size()) if(c[i]==d[i]) break;
			if(i==c.size()) C.push_back({c,d});
		}
	 	
		
		map<vector<int>,ll> M;
		FORR(c,cand) M[c]=1;
		FOR(i,n-1) {
			map<vector<int>,ll> M2;
			FORR(a,C) {
				(M2[a.second]+=M[a.first])%=mo;
			}
			
			swap(M,M2);
		}
		ll ret=0;
		FORR(m,M) ret+=m.second;
		return ret%mo;
        
        
    }
};
