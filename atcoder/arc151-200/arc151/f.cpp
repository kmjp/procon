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


int T;
ll C[2][3];

bool hoge() {
	int i,j,k,l,r,x,y; string s;
	ll NA=0,NB=0,NC=0,SA=0,SB=0,SC=0;
	FOR(i,2) FOR(j,3) cin>>C[i][j];
	FOR(j,3) if(C[0][j]&&C[1][j]) {
		if(C[0][j]<C[1][j]) NA++,SA+=min(C[0][j],C[1][j]);
		if(C[0][j]>C[1][j]) NB++,SB+=min(C[0][j],C[1][j]);
		if(C[0][j]==C[1][j]) NC++,SC+=min(C[0][j],C[1][j]);
	}
	if(NC==0) {
		return SA>=SB;
	}
	else if(NC==1) {
		if(NA==2) return 1;
		if(NB==2) return 0;
		if(SA-SB>=SC) return 1;
		if(SA-SB<=-SC) return 0;
		return (SA+SB+SC)%2;
	}
	else if(NC==2) {
		if(NA) return 1;
		if(NB) return 0;
		return SC%2;
	}
	else if(NC==3) {
		return SC%2==0;
	}
}

void solve() {
	
	
	cin>>T;
	while(T--) {
		if(hoge()) {
			cout<<"Takahashi"<<endl;
		}
		else {
			cout<<"Aoki"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
