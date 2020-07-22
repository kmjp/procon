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

ll A,B;
const ll M=10000000000LL+19;

ll hoge2(ll p,ll C) {
	ll q=M-p;
	
	ll X=C/p;
	ll Y=C/q;
	
	if(X==0) return Y+1;
	if(Y==0) return X+1;
	
	if(X>=1<<30 || Y>=1<<30 || (X-1)*(Y-1)/2>=1LL<<30) return 1LL<<30;
	if(p<q) swap(p,q);
	
	ll ret=0;
	for(int i=0;p*i<=C;i++) {
		ll v=(C-p*i)/q;
		ret+=v+1;
		if(ret>1LL<<25) break;
	}
	return ret;
	
}

pair<ll,ll> hoge(ll p,ll K) {
	
	ll C=1LL<<61;
	for(int i=60;i>=0;i--) if(hoge2(p,C-(1LL<<i))>=K) C-=1LL<<i;
	ll q=M-p;
	ll a=0,b=0;
	if(p>q) {
		for(int i=0;p*i<=C;i++) {
			ll v=(C-p*i)/q;
			a+=(v+1)*i;
			b+=v*(v+1)/2;
		}
	}
	else {
		for(int i=0;q*i<=C;i++) {
			ll v=(C-q*i)/p;
			b+=(v+1)*i;
			a+=v*(v+1)/2;
		}
	}
	
	return {a,b};
	
}


int ok(int K) {
	ll p=1;
	
	auto r=hoge(p,K);
	if(r.first>A&&r.second>B) return 0;
	if(r.first<=A&&r.second<=B) return 1;
	int i;
	for(i=40;i>=0;i--) if(p+(1LL<<i)<M) {
		auto r=hoge(p+(1LL<<i),K);
		if(r.first>A&&r.second>B) return 0;
		if(r.first<=A&&r.second<=B) return 1;
		if(r.first>A) p+=1LL<<i;
		
	}
	r=hoge(p,K);
	if(r.first>A&&r.second>B) return 0;
	if(r.first<=A&&r.second<=B) return 1;
	auto r2=hoge(p+1,K);
	if(r2.first>A&&r2.second>B) return 0;
	if(r2.first<=A&&r2.second<=B) return 1;
	
	assert(r.first>=A&&r.second<=B&&r2.first<=A&&r2.second>=B);
	ll ax=r2.first-r.first;
	ll ay=r2.second-r.second;
	ll bx=A-r.first;
	ll by=B-r.second;
	if(ax*by-bx*ay<=0) return 1;
	
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	
	int K=0;
	for(i=20;i>=0;i--) if(ok(K+(1<<i))) K+=1<<i;
	cout<<K-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
