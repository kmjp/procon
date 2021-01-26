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
    int minCharacters(string a, string b) {
		int C[2][27]={};
		FORR(c,a) C[0][c-'a']++, C[0][26]++;
		FORR(c,b) C[1][c-'a']++, C[1][26]++;
		int ret=1<<20;
		int i,j;
		FOR(i,26) {
			ret=min(ret,C[0][26]+C[1][26]-C[0][i]-C[1][i]);
		}
		FOR(i,25) {
			int a=0,b=0;
			FOR(j,26) {
				if(j<=i) a+=C[0][j],b+=C[1][j];
				else a+=C[1][j],b+=C[0][j];
			}
			ret=min(ret,a);
			ret=min(ret,b);
			
		}
		return ret;
        
    }
};

