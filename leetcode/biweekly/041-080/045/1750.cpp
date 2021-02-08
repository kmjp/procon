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
    int minimumLength(string s) {
		int L=0,R=s.size()-1;
		while(1) {
			if(s[L]!=s[R]) break;
			if(L==R) break;
			char c=s[L];
			while(L<=R&&s[L]==c) L++;
			while(L<=R&&s[R]==c) R--;
			if(L>R) break;
		}
		return R-L+1;
		
        
    }
};
