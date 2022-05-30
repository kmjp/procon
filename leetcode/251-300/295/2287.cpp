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
    int rearrangeCharacters(string s, string target) {
		int C[256]={},D[256]={};
		FORR(c,s) C[c]++;
		FORR(c,target) D[c]++;
		int ma=1010;
		int i;
		FOR(i,256) if(D[i]) ma=min(ma,C[i]/D[i]);
		return ma;
		
        
    }
};
