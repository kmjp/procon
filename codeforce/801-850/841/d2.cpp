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

int T,H,W;
vector<int> A[1010101];
vector<int> B[1010101];

int can(int v) {
	int y,x;
	FOR(y,H+1) {
		B[y].resize(W+1);
		FOR(x,W+1) B[y][x]=0;
	}
	FOR(y,H) FOR(x,W) if(A[y][x]<v) {
		B[max(0,y-(v-1))][max(0,x-(v-1))]++;
		B[max(0,y-(v-1))][x+1]--;
		B[y+1][max(0,x-(v-1))]--;
		B[y+1][x+1]++;
	}
	FOR(y,H) FOR(x,W) {
		if(y+v-1>=H) continue;
		if(x+v-1>=W) continue;
		if(y) B[y][x]+=B[y-1][x];
		if(x) B[y][x]+=B[y][x-1];
		if(y&&x) B[y][x]-=B[y-1][x-1];
		if(B[y][x]==0) {
			return 1;
		}
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			A[y].resize(W);
			FOR(x,W) cin>>A[y][x];
		}
		int ma=0;
		for(i=20;i>=0;i--) if(ma+(1<<i)<=min(H,W)) {
			if(can(ma+(1<<i))) ma+=1<<i;
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
