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


typedef complex<double> Comp;

vector<Comp> fft(vector<Comp> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		double deg=(rev?-1:1) * 2*acos(-1)/m;
		Comp wr(cos(deg),sin(deg));
		for(i=0;i<n;i+=m) {
			Comp w(1,0);
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				Comp t1=v[j1],t2=w*v[j2];
				v[j1]=t1+t2, v[j2]=t1-t2;
				w*=wr;
			}
		}
	}
	if(rev) FOR(i,n) v[i]*=1.0/n;
	return v;
}

vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

int N;
ll A[101010];
ll S[101010];
ll mi[101010];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

double hoge(int a,int b) {
	return log(a+b)+b*log(a);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	
	ll a=1<<20,b=1<<20;
	
	mi[N-1]=A[N-1];
	for(i=N-2;i>=0;i--) {
		mi[i]=min(mi[i+1],A[i]);
		if(hoge(A[i],mi[i+1])<hoge(a,b)) {
			a=A[i];
			b=mi[i+1];
		}
	}
	
	
	
	ll ret=1;
	FOR(i,N) {
		ll sum=S[N]-S[i+1];
		(ret*=modpow(A[i],sum))%=mo;
		
	}
	vector<Comp> D(1<<19);
	FOR(i,N) D[A[i]]+=1;
	auto E=MultPoly(D,D);
	for(i=1;i<=200000;i++) {
		ll x=E[i].real()+0.1;
		if(i%2==0) x=x-D[i/2].real()+0.1;
		x/=2;
		ret=ret*modpow(i,x)%mo;
	}
	(ret*=modpow((a+b)*modpow(a,b)%mo))%=mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
