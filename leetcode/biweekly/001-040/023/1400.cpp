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
    bool canConstruct(string s, int k) {
		int C[26]={};
		int i;
		FORR(c,s) C[c-'a']++;
		int num=0;
		FOR(i,26) if(C[i]%2==1) num++;
		return (num<=k) && (s.size()>=k);
    }
};
