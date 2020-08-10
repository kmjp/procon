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

int mi[1024];
class Solution {
public:
    int longestAwesome(string s) {
		mi[0]=0;
		int ma=0;
		int i;
		FOR(i,1024) mi[i]=1010101;
		mi[0]=0;
		int mask=0,j;
		FOR(i,s.size()) {
			mask^=1<<(s[i]-'0');
			ma=max(ma,i+1-mi[mask]);
			FOR(j,10) ma=max(ma,i+1-mi[mask^(1<<j)]);
			mi[mask]=min(mi[mask],i+1);
		}
		return ma;
        
    }
};
