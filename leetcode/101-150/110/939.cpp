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
    int minAreaRect(vector<vector<int>>& P) {
		set<pair<int,int>> S;
        FORR(p,P) S.insert({p[0],p[1]});
        int ma=1<<30;
        FORR(a,P) FORR(b,P) if(a!=b) {
			if(S.count({a[0],b[1]}) && S.count({b[0],a[1]})) {
				if(a[0]!=b[0] && a[1]!=b[1]) ma=min(ma,abs(a[0]-b[0])*abs(a[1]-b[1]));
			}
		}
		if(ma==1<<30) ma=0;
		return ma;
    }
};