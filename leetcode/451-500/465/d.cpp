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
vector<int> D[70707];
vector<int> C[70707];
ll dp[70707];

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt;


class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        
        int x,y;
        if(D[1].empty()) {
			for(x=1;x<=70000;x++) for(y=x;y<=70000;y+=x) D[y].push_back(x);
        }
        
        FORR(n,nums) {
			FORR(d,D[n]) C[d].push_back(n);
		}
		
		ZERO(dp);
		for(x=1;x<=70000;x++) if(C[x].size()) {
			FORR(v,C[x]) {
				ll a=bt(v-1)+1;
				bt.add(v,a);
			}
			
			dp[x]=bt(1<<19);
			sort(ALL(C[x]));
			FORR(v,C[x]) bt.add(v,mo-bt(v));
			C[x].clear();
		}
		
		ll ret=0;
		for(x=70000;x>=1;x--) {
			for(y=2*x;y<=70000;y+=x) dp[x]+=mo-dp[y];
			dp[x]%=mo;
			(ret+=x*dp[x])%=mo;
		}
		return ret;
        
    }
};
