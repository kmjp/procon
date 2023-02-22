#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int N;
ll X[805],Y[805],T[805];
ll D[808][808];

ll issq(ll V) {
	return V;
	if(V<0) return -1;
	ll a=sqrt(V);
	if((a-1)*(a-1)>=V) return a-1;
	if(a*a>=V) return a;
	if((a+1)*(a+1)>=V) return a+1;
	return -1;
}

ll hoge(ll p,ll q) {
	if(p==q) return 0;
	ll s=p+q;
	int i;
	for(i=40;i>=0;i--) {
		ll s2=s-(1LL<<i);
		if(s2<0) continue;
		if((p+q-s2)*(p+q-s2)<=4*p*q) s=s2;
	}
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>T[i];
	FOR(y,N) FOR(x,y) {
		if(T[x]==T[y]) {
			D[y][x]=issq((X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y]));
		}
		else {
			D[y][x]=hoge(X[x]*X[x]+Y[x]*Y[x],X[y]*X[y]+Y[y]*Y[y]);
		}
		D[x][y]=D[y][x];
	}
	FOR(k,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],max(D[x][k],D[k][y]));
	cout<<D[0][N-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
