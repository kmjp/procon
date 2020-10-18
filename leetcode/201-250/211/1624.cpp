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
    int maxLengthBetweenEqualCharacters(string s) {
		int C[256];
		int i;
		FOR(i,256) C[i]=1000;
		int ma=-1;
		FOR(i,s.size()) {
			ma=max(ma,i-C[s[i]]-1);
			C[s[i]]=min(C[s[i]],i);
		}
        return ma;
    }
};

