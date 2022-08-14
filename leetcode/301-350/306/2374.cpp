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
    int edgeScore(vector<int>& edges) {
		ll sc[101010]={};
		int i;
		int N=edges.size();
        FOR(i,N) sc[edges[i]]+=i;
        ll ma=0;
        int id=0;
        FOR(i,N) {
			if(sc[i]>ma) ma=sc[i],id=i;
		}
		return id;
        
    }
};
