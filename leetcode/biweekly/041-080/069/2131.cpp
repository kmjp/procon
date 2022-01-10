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
    int longestPalindrome(vector<string>& words) {
        int C[26][26]={};
        FORR(a,words) {
			C[a[0]-'a'][a[1]-'a']++;
		}
		int ret=0;
		int y,x;
		FOR(y,26) FOR(x,y) {
			ret+=min(C[x][y],C[y][x])*4;
		}
		int num=0,odd=0;
		FOR(x,26) {
			ret+=C[x][x]/2*4;
			odd+=C[x][x]%2;
		}
		if(odd) ret+=2;
		return ret;
    }
};
