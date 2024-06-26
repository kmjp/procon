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

ll N,M;
ll X[202020],Y[202020];
ll S[100],D[100],O[100],Z[100];


void taka() {
	cout<<"Takahashi"<<endl;
	exit(0);
}
void aoki() {
	cout<<"Aoki"<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		Y[i]^=X[i]%2;
	}
	
	S[0]=0;
	D[0]=0;
	D[1]=0;
	for(i=1;i<=20;i++) {
		set<int> V;
		for(j=1;j<=i;j++) {
			V.insert(S[j-1]^S[i-j]);
			if(j>1&&j<i) V.insert(D[j-1]^D[i-j]);
		}
		while(V.count(S[i])) S[i]++;
		V.clear();
		for(j=1;j<=i;j++) {
			if(j<i) V.insert(S[j-1]^D[i-j]);
			if(j>1) V.insert(D[j-1]^S[i-j]);
		}
		while(V.count(D[i])) D[i]++;
		V.clear();
		for(j=1;j<=i;j++) {
			V.insert(S[j-1]^O[i-j]);
			if(j>1) V.insert(D[j-1]^O[i-j]);
		}
		while(V.count(O[i])) O[i]++;
		V.clear();
		for(j=1;j<=i;j++) {
			V.insert(O[j-1]^O[i-j]);
		}
		while(V.count(Z[i])) Z[i]++;
		
		cerr<<i<<" "<<S[i]<<" "<<D[i]<<" "<<O[i]<<" "<<Z[i]<<endl;
	}
	
	if(M==0) {
		if(N%2==1) taka();
		if(N%2==0) aoki();
	}
	
	ll nim=0;
	nim^=X[0]-1;
	nim^=N-X[M-1];
	FOR(i,M-1) {
		ll s=X[i+1]-X[i]-1;
		s%=2;
		if(Y[i]==Y[i+1]) {
			nim^=s;
		}
		else {
			nim^=s^1;
		}
	}
	if(nim) taka();
	else aoki();
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
