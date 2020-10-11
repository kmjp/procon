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

int same[101010];
int L[4][101010];
int R[4][101010];
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
		ZERO(same);
		int n=a.size();
		int i,j,x;
		FOR(x,2) {
			FOR(i,n) {
				FOR(j,4) L[j][i+1]=L[j][i];
				if(a[i]==a[n-1-i]) L[0][i+1]++;
				if(a[i]==b[n-1-i]) L[1][i+1]++;
				if(b[i]==a[n-1-i]) L[2][i+1]++;
				if(b[i]==b[n-1-i]) L[3][i+1]++;
			}
			if(L[0][n]==n||L[3][n]==n) return 1;
			
			for(i=1;i<=n-1;i++) {
				if(i*2<=n) {
					if(L[1][i]==i&&L[3][n-i]-L[3][i]==n-2*i) return 1;
					if(L[2][i]==i&&L[0][n-i]-L[0][i]==n-2*i) return 1;
				}
			}
			reverse(ALL(a));
			reverse(ALL(b));
		}
		return 0;
    }
};
