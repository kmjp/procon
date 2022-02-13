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


ll S[101010];

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
		sort(ALL(beans));
        int i;
        int N=beans.size();
        FOR(i,N) S[i+1]=S[i]+beans[i];
        ll mi=S[N];
        
        FOR(i,N) {
			mi=min(mi,S[i]+(S[N]-S[i])-1LL*beans[i]*(N-i));
		}
        return mi;
        
    }
};
