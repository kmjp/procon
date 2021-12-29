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
ll S[55][55];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>S[y][x];
		if(y) S[y][x]+=S[y-1][x];
		if(x) S[y][x]+=S[y][x-1];
		if(y&&x) S[y][x]-=S[y-1][x-1];
	}
	
	ll sum=S[H-1][W-1];
	
	int pat=0;
	FOR(y,H) FOR(x,W) {
		ll a=S[y][x];
		if(S[y][W-1]%a) continue;
		if(S[H-1][x]%a) continue;
		vector<int> Xs,Ys;
		int ty,tx;
		FOR(tx,W) if(S[y][tx]%a==0) Xs.push_back(tx);
		FOR(ty,H) if(S[ty][x]%a==0) Ys.push_back(ty);
		FOR(ty,Ys.size()) {
			FOR(tx,Xs.size()) {
				if(S[Ys[ty]][Xs[tx]]!=1LL*a*(tx+1)*(ty+1)) break;
			}
			if(tx!=Xs.size()) break;
		}
		if(ty==Ys.size()) pat++;
		
	}
	cout<<pat-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
