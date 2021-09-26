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
string S[202],T[202],R[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	
	while(1) {
		FOR(x,N) if(S[0][x]=='#') break;
		if(x<N) break;
		FOR(y,N-1) swap(S[y],S[y+1]);
	}
	while(1) {
		FOR(y,N) if(S[y][0]=='#') break;
		if(y<N) break;
		FOR(y,N) S[y]=S[y].substr(1)+".";
	}
	
	FOR(y,N) cin>>T[y];
	FOR(i,4) {
		while(1) {
			FOR(x,N) if(T[0][x]=='#') break;
			if(x<N) break;
			FOR(y,N-1) swap(T[y],T[y+1]);
		}
		while(1) {
			FOR(y,N) if(T[y][0]=='#') break;
			if(y<N) break;
			FOR(y,N) T[y]=T[y].substr(1)+".";
		}
		
		FOR(y,N) if(S[y]!=T[y]) break;
		if(y==N) {
			cout<<"Yes"<<endl;
			return;
		}
		
		FOR(y,N) R[y]=T[y];
		FOR(y,N) FOR(x,N) T[y][x]=R[x][N-1-y];
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
