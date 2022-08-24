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
    string largestPalindromic(string num) {
        int C[10]={};
        FORR(c,num) C[c-'0']++;
        
        string S;
        char c=0;
        int i;
        for(i=9;i>=0;i--) {
			if(i||S.size()) {
				S+=string(C[i]/2,i+'0');
				C[i]%=2;
			}
			if(C[i]&&c==0) c='0'+i;
		}
		string T=S;
		reverse(ALL(T));
		if(c) S+=c;
		S+=T;
		return S;
		
    }
};
