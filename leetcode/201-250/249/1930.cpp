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

int L[202020][26];
int R[202020][26];
int ret[26][26];

class Solution {
public:
    int countPalindromicSubsequence(string s) {
		ZERO(L);
		ZERO(R);
		ZERO(ret);
		int N=s.size();
		int i,j;
		FOR(i,N) {
			FOR(j,26) L[i+1][j]=L[i][j];
			L[i+1][s[i]-'a']++;
		}
		for(i=N;i>=1;i--) {
			FOR(j,26) {
				R[i][j]=R[i+1][j];
				if(L[i-1][j]&&R[i+1][j]) {
					ret[j][s[i-1]-'a']=1;
				}
			}
			R[i][s[i-1]-'a']++;
		}
		int sum=0;
		FOR(i,26) FOR(j,26) sum+=ret[i][j];
        return sum;
    }
};
