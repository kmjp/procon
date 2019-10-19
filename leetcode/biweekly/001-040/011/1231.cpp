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

int N;
vector<int> V;

class Solution {
public:
	ll ok(ll v) {
		int num=0;
		ll sum=0;
		int i;
		FOR(i,N) {
			sum+=V[i];
			if(sum>=v) {
				num++;
				sum=0;
			}
		}
		return num;
	}

    int maximizeSweetness(vector<int>& sweetness, int K) {
        N=sweetness.size();
        V=sweetness;
        
        ll ma=0;
        int i;
        for(i=29;i>=0;i--) if(ok(ma+(1LL<<i))>=K+1) ma+=1LL<<i;
        return ma;
        
        
    }
};

