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
    string sortString(string s) {
		int C[256]={};
		FORR(c,s) C[c]++;
		string T;
		int i,j;
		FOR(i,512) {
			FOR(j,256) if(C[j]) {
				C[j]--;
				T+=(char)j;
			}
			FOR(j,256) if(C[255-j]) {
				C[255-j]--;
				T+=(char)(255-j);
			}
		}
		return T;
		
        
    }
};

