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
string S[2020];
int D[4020][4020];
int E[4020][4020];

int ok(int v) {
	if(v>min(H,W)) return 0;
	
	ZERO(E);
	int y,x;
	for(y=v-1;y<H;y++) for(x=v-1;x<W;x++) {
		int num=D[y+1][x+1]-D[y+1-v][x+1]-D[y+1][x+1-v]+D[y+1-v][x+1-v];
		if(num==v*v) E[y+1][x+1]++;
	}
	FOR(y,4010) FOR(x,4010) if(x&&y) E[y][x]+=E[y-1][x]+E[y][x-1]-E[y-1][x-1];
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
		if(E[y+v][x+v]-E[y][x+v]-E[y+v][x]+E[y][x]==0) return 0;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			D[y+1][x+1]=(S[y][x]=='#');
		}
	}
	
	FOR(y,4010) FOR(x,4010) if(x&&y) D[y][x]+=D[y-1][x]+D[y][x-1]-D[y-1][x-1];
	
	
	int cur=1;
	for(i=10;i>=0;i--) {
		if(ok(cur+(1<<i))) cur+=1<<i;
	}
	cout<<cur<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
