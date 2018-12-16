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


int nex(int v) {
	int ret=0;
	for(int i=1;i<=6;i++) {
		if(((v>>(i-1))&1)==((v>>(i+1))&1)) {
			ret |= 1<<i;
		}
	}
	return ret;
}

int hist[256];

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        MINUS(hist);
        int cur=0,i;
        FOR(i,8) cur |= cells[i]<<i;
        
        hist[cur]=0;
        for(i=1;i<=N;i++) {
			cur=nex(cur);
			if(hist[cur]==-1) {
				hist[cur]=i;
			}
			else if(i<N-1000) {
				int p=i-hist[cur];
				i+=(N-i)/p*p;
			}
		}
        vector<int> V;
        FOR(i,8) V.push_back((cur>>i)&1);
        return V;
    }

};
