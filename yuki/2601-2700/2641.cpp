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

int H,W;
string S[1010101],T[1010101];
vector<int> LD[1010101],LU[1010101],RD[1010101],RU[1010101],R[1010101],L[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) T[y]+='.';
		LD[y].resize(W);
		LU[y].resize(W);
		RD[y].resize(W);
		RU[y].resize(W);
		L[y].resize(W);
		R[y].resize(W);
		FOR(x,W) if(S[y][x]=='#') {
			LD[y][x]=LU[y][x]=RD[y][x]=RU[y][x]=1;
			if(y&&x) LD[y][x]+=LD[y-1][x-1];
			if(y&&x+1<W) RD[y][x]+=RD[y-1][x+1];
		}
	}
	for(y=H-1;y>=0;y--) {
		FOR(x,W) if(S[y][x]=='#') {
			if(y+1<H&&x) LU[y][x]+=LU[y+1][x-1];
			if(y+1<H&&x+1<W) RU[y][x]+=RU[y+1][x+1];
			k=min({LU[y][x],LD[y][x],RD[y][x],RU[y][x]});
			if(k>1) {
				k--;
				chmax(R[y-k][x-k],2*k+1);
				chmax(L[y-k][x+k],2*k+1);
			}
		}
	}
	FOR(y,H) {
		FOR(x,W) {
			if(y&&x) chmax(R[y][x],R[y-1][x-1]-1);
			if(y&&(x+1<W)) chmax(L[y][x],L[y-1][x+1]-1);
			if(R[y][x]>0||L[y][x]>0) T[y][x]='#';
		}
		if(S[y]!=T[y]) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
