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


int S[101010][4];

class Solution {
public:
    int balancedString(string s) {
        ZERO(S);
        int i,j,N=s.size();
        FOR(i,N) {
			FOR(j,4) S[i+1][j]=S[i][j];
			if(s[i]=='Q') S[i+1][0]++;
			if(s[i]=='W') S[i+1][1]++;
			if(s[i]=='E') S[i+1][2]++;
			if(s[i]=='R') S[i+1][3]++;
		}
		if(S[N][0]==S[N][1]&&S[N][0]==S[N][2]&&S[N][0]==S[N][3]) return 0;
		int R[4]={};
		
		int mi=N;
		FOR(i,N+1) {
			int ma=0;
			FOR(j,4) {
				if(S[i][j]>N/4) break;
				while(S[i][j]+S[N][j]-S[R[j]][j]>N/4) R[j]++;
				ma=max(ma,R[j]);
			}
			if(j<4) break;
			mi=min(mi,ma-i);
			
		}
		return mi;
		
        
    }
};


