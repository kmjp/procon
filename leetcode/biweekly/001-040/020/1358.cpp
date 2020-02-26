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
    int numberOfSubstrings(string s) {
		int N=s.size();
		int ex[50505][3];
		int i,j;
		ex[N][0]=ex[N][1]=ex[N][2]=N+1;
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			FOR(j,3) ex[i][j]=ex[i+1][j];
			ex[i][s[i]-'a']=i+1;
			int ma=0;
			FOR(j,3) ma=max(ma,ex[i][j]);
			ret+=N+1-ma;
		}
		return ret;
		
        
    }
};
