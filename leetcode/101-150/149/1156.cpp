
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

int S[202020][26];

class Solution {
public:

    int maxRepOpt1(string text) {
        ZERO(S);
        int N=text.size();
        int i,j;
        FOR(i,N) {
			text[i]-='a';
			FOR(j,26) S[i+1][j]=S[i][j];
			S[i+1][text[i]]++;
		}
		
		int ma=0;
		FOR(i,N) {
			int c=text[i];
			int cur=i+1;
			for(j=20;j>=0;j--) if(cur+(1<<j)<=N) {
				if(S[cur+(1<<j)][c]-S[i][c]>=cur+(1<<j)-i-1) cur+=1<<j;
			}
			
			if(S[cur][c]-S[i][c]==cur-i) {
				ma=max(ma,cur-i);
			}
			else {
				if(S[cur][c]-S[i][c]==S[N][c]) ma=max(ma,cur-i-1);
				else ma=max(ma,cur-i);
			}
			
		}
		return ma;
        
    }




};

