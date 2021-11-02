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

int N,M;
int P[808];
int X[808],Y[808];
int S[808],T[808];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,M) cin>>S[i]>>T[i];
	ll ma=0;
	FOR(k,4) {
		if(k==2) {
			FOR(i,M) S[i]=-S[i];
		}
		if(k==1||k==3) {
			FOR(i,M) T[i]=-T[i];
		}
		map<pair<int,int>,ll> C;
		FOR(x,N) FOR(y,M) {
			C[{X[x]-S[y],Y[x]-T[y]}]+=P[x];
		}
		FORR2(a,b,C) ma=max(ma,b);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
