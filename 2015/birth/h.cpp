#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,B,C;

const int prime_max = 1100000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>A>>B>>C;
	
	FOR(i,NP) {
		ll v[3]={A,B,C};
		int num=0;
		FOR(j,3) {
			ll cv=prime[i];
			while(cv<=v[j]) {
				if(j<2) num -= v[j]/cv;
				else num += v[j]/cv;
				cv*=prime[i];
			}
		}
		if(num<0) return _P("NO\n");
	}
	
	for(ll x=1;x*prime_max<=C;x++) {
		ll R=min(C,(C/x+1)*x-1);
		ll L=C/x*x;
		if(A/L+B/L>C/L) return _P("NO\n");
		if(A/R+B/R>C/R) return _P("NO\n");
	}
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
