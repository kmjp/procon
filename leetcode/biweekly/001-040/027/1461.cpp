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

int ok[1<<20];

class Solution {
public:
    bool hasAllCodes(string s, int k) {
		vector<int> V;
		ZERO(ok);
		int i,x;
		int v=0;
		FOR(i,s.size()) {
			v=v*2+(s[i]-'0');
			v&=(1<<k)-1;
			if(i>=k-1) {
				ok[v]=1;
			}
		}
		FOR(i,1<<k) if(ok[i]==0) return 0;
			
		return 1;
        
    }
};
