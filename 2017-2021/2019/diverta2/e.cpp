#include <bits/stdc++.h>
using namespace std;
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

ll N,D,H;
ll mo=1000000007;

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	V add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt;
ll fact[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>H>>D;

	fact[0]=1;
	for(i=0;i<=1010000;i++) fact[i+1]=fact[i]*(i+1)%mo;
	
	ll sum=0;
	for(i=1;i<=N;i++) sum+=fact[i];
	sum%=mo;
	
	
	bt.add(1,fact[N]);
	bt.add(D+1,mo-fact[N]);
	for(i=1;i<=H-1;i++) {
		ll cur=bt(i)%mo;
		bt.add(i+1,cur*sum%mo);
		bt.add(i+D+1,mo-cur*sum%mo);
	}
	
	cout<<bt(H)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
