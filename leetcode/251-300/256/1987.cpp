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

const ll mo=1000000007;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
		ll nex[2]={0,0};
		reverse(ALL(binary));
		int add=0;
		FORR(b,binary) {
			add|=b=='0';
			ll pat=(nex[0]+nex[1]+1)%mo;
			nex[b-'0']=pat;
		}
        
        return add+nex[1];
        
    }
};
