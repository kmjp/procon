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
    int numWays(string s) {
		map<int,int> M;
		int cur=0;
		FORR(c,s) {
			if(c=='1') cur++;
			M[cur]++;
		}
		
		if(cur==0) {
			return 1LL*(s.size()-1)*(s.size()-2)/2%1000000007;
		}
		if(cur%3) return 0;
		return 1LL*M[cur/3]*M[cur*2/3]%1000000007;
		
        
    }
};


