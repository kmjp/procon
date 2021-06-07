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
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		ll ret=1LL<<60;
		sort(ALL(packages));
		vector<ll> PS;
		PS.push_back(0);
		FORR(p,packages) PS.push_back(PS.back()+p);
		
		FORR(v,boxes) {
			sort(ALL(v));
			int pre=0;
			ll tmp=0;
			FORR(a,v) {
				int cur=lower_bound(ALL(packages),a+1)-packages.begin();
				tmp+=1LL*a*(cur-pre)-(PS[cur]-PS[pre]);
				pre=cur;
			}
			if(pre<packages.size()) continue;
			ret=min(ret,tmp);
		}
		
		
		if(ret==1LL<<60) return -1;
		
		return ret%1000000007;
        
    }
};
