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
ll p10[101010];

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> sum,num,dsum;


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
		int i,N=s.size();
		p10[0]=1;
		
		FOR(i,N+2) {
			sum.add(i,-sum(i));
			dsum.add(i,-dsum(i));
			num.add(i,-num(i));
			p10[i+1]=p10[i]*10%mo;
		}
		int n=0;
		for(i=N-1;i>=0;i--) if(s[i]!='0') {
			int x=s[i]-'0';
			num.add(i,1);
			sum.add(i,p10[n++]*x%mo);
			dsum.add(i,x);
		}
		vector<int> ret;
		FORR(q,queries) {
			int L=q[0],R=q[1]+1;
			ll s=sum(R-1)-sum(L-1)+mo;
			ll d=dsum(R-1)-dsum(L-1);
			int nd=num(N)-num(R-1);
			s=s*modpow(p10[nd])%mo;
			s=s*d%mo;
			ret.push_back(s);
		}
		return ret;
		
        
    }
};

