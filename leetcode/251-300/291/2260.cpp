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
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> P;
        int i;
        int mi=1<<20;
        FOR(i,cards.size()) {
			if(P.count(cards[i])) mi=min(mi,i-P[cards[i]]+1);
			P[cards[i]]=i;
		}
        
        if(mi==1<<20) mi=-1;
        return mi;
    }
};
