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
    int lastStoneWeightII(vector<int>& S) {
		bitset<10000> bs;
		bs[5000]=1;
		FORR(c,S) bs=(bs<<c)|(bs>>c);
		int i;
		FOR(i,5000) if(bs[5000+i]) return i;
		return -1;
		
        
    }
};

