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


int C[1010][26];

ll from[1010],to[1010];
const ll mo=1000000007;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
		ZERO(C);
		FORR(w,words) {
			int i;
			FOR(i,w.size()) C[i][w[i]-'a']++;
		}
        ZERO(from);
        from[0]=1;
        int i,j;
        FORR(c,target) {
			ZERO(to);
			ll sum=0;
			FOR(i,1010) {
				if(i) to[i]=sum*C[i-1][c-'a']%mo;
				sum+=from[i];
			}
			swap(from,to);
		}
        ll ret=0;
        FOR(i,1005) ret+=from[i];
        return ret%mo;
        
        
    }
};
