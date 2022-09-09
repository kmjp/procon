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

ll N,H,W;

int R[8888][8888];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	ll A=1;
	while(N%(A*2)==0) A*=2;
	ll B=N/A;
	W=N/H;
	
	vector<int> V;
	for(x=1;x<=A;x*=2) {
		FOR(i,x) V.push_back(x);
	}
	for(x=1;x<A;x*=2) {
		FOR(i,x*B) V.push_back(x*B);
	}
	if(H%B==0) {
		FOR(i,N) R[i%H][i/H]=V[i];
	}
	else {
		FOR(i,N) R[i/(N/H)][i%(N/H)]=V[i];
	}
	
	
	FOR(y,H) {
		FOR(x,W) cout<<R[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
