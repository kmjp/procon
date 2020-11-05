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


int N;
ll A[202020],P[202020],B[202020];
const ll mo=200003;

typedef complex<long double> Comp;

vector<Comp> fft(vector<Comp> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		long double deg=(rev?-1:1) * 2*acos(-1)/m;
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
	if(rev) FOR(i,n) v[i]*=(long double)1.0/n;
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll cur=1;
	FOR(i,mo-1) {
		A[cur]=i;
		P[i]=cur;
		cur=cur*2%mo;
	}
	
	vector<Comp> X(1<<19);
	ll ret=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		B[i]=x;
		if(x) {
			X[A[x]]+=1;
			//cout<<x<<" "<<1LL*x*x%mo<<" "<<A[x]<<endl;
		}
		ret-=B[i]*B[i]%mo;
	}
	
	auto Y=MultPoly(X,X,true);
	//cout<<ret<<endl;
	FOR(i,Y.size()) {
		ll a=floor(Y[i].real()+0.3);
		ret+=a*P[i%(mo-1)];
	}
	
	cout<<ret/2<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
