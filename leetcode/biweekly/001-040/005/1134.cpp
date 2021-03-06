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
    bool isArmstrong(int N) {
		int D=0;
		int v=N;
		int i;
		while(v) {
			D++;
			v/=10;
		}
		ll ret=0;
		v=N;
		while(v) {
			ll a=1;
			FOR(i,D) a*=v%10;
			ret+=a;
			v/=10;
		}
		
        return ret==N;
    }
};

