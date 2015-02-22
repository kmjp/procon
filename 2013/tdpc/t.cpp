#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A[2024][1024];
ll mo=1000000007;
ll N,K;

vector<ll> mult(vector<ll>& v,vector<ll>& v2) {
	int i,j;
	vector<ll> t(2*K,0);
	FOR(i,K) FOR(j,K) t[i+j] += v[i]*v2[j]%mo;
	for(i=K;i<2*K-1;i++) {
		ll ti=t[i]%mo;
		FOR(j,K) t[j] += A[i][j]*ti % mo;
	}
	FOR(j,K) ((t[j]%=mo)+=mo)%=mo;
	t.resize(K);
	return t;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	if(N<=K) return _P("1\n");
	
	FOR(i,K) A[i][i]=1;
	FOR(i,K) {
		ll t=0;
		for(j=0;j<=2*K;j++) {
			if(j>=K) A[j][i] = t, t-=A[j-K][i];
			(t += A[j][i])%=mo;
			if(t<0) t+=mo;
		}
	}
	
	vector<ll> R(K,0),V(K,0);
	R[0]=V[1]=1;
	N--;
	while(N) {
		if(N%2) R=mult(R,V);
		V=mult(V,V);
		N/=2;
	}
	
	ll ret=0;
	FOR(i,K) ret+=R[i];
	cout << ((ret % mo)+mo)%mo << endl;
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
