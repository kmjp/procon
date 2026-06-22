#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


const ll mo=1000000007;

class Solution {
public:
	pair<ll,ll> hoge(vector<int>& value, vector<int>& decay,int v) {
		int i,N=value.size();
		// vˆÈã‚ª‰½ŒÂ‚©
		ll ret=0;
		ll sum=0;
		FOR(i,N) if(value[i]>=v) {
			ll a=(value[i]-v+1+decay[i]-1)/decay[i];
			ret+=a;
			if(ret>1000000000) return {1000000002,0};
			sum+=value[i]*a-decay[i]*(a*(a-1)/2);
		}
		cout<<v<<" "<<ret<<" "<<sum<<endl;
		return {ret,sum};
	}

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
		
		int ret=(1<<30)-1;
		int i,j,N=value.size();
		
		auto p=hoge(value,decay,0);
		if(p.first<=m) {
			return p.second%mo;
		}
		else {
			for(i=29;i>=0;i--) if(hoge(value,decay,ret-(1<<i)).first<=m) ret-=1<<i;
			auto p=hoge(value,decay,ret);
			return (p.second+(m-p.first)*max(0,(ret-1)))%mo;
		}
    }
};
