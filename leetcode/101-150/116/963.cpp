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
    double minAreaFreeRect(vector<vector<int>>& points) {
		int N=points.size();
		ll ret=1LL<<60;
		FORR(a,points) FORR(b,points) FORR(c,points) {
			if((b[0]-a[0])*(c[0]-a[0])+(b[1]-a[1])*(c[1]-a[1])) continue;
			ll v=abs((b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]));
			if(v==0 || v>=ret) continue;
			FORR(d,points) {
				if(a[0]+d[0]!=b[0]+c[0]) continue;
				if(a[1]+d[1]!=b[1]+c[1]) continue;
				ret=v;
				break;
			}
		}
		
		if(ret==1LL<<60) ret=0;
		return ret;
    }

};
