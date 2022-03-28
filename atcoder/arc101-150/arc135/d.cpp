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
ll A[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	for(y=H-2;y>=0;y--) {
		for(x=W-2;x>=0;x--) {
			ll v=A[y+1][x+1];
			A[y][x]-=v;
			A[y][x+1]-=v;
			A[y+1][x]-=v;
			A[y+1][x+1]-=v;
		}
	}
	/*
	FOR(y,H) {
		FOR(x,W) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	*/
	for(y=1;y<H;y++) for(x=1;x<W;x++) {
		
		ll mi=0;
		if(x%2==y%2) {
			if(A[y][0]>0&&A[0][x]>0) mi=min(A[y][0],A[0][x]);
			if(A[y][0]<0&&A[0][x]<0) mi=max(A[y][0],A[0][x]);
			A[y][0]-=mi;
			A[0][x]-=mi;
			if(x%2==0) {
				A[y][x]+=mi;
				A[0][0]+=mi;
			}
			else {
				A[y][x]-=mi;
				A[0][0]-=mi;
			}
		}
		else if(x%2==1) {
			if(A[y][0]<0&&A[0][x]>0) mi=min(-A[y][0],A[0][x]);
			if(A[y][0]>0&&A[0][x]<0) mi=max(-A[y][0],A[0][x]);
			A[0][0]-=mi;
			A[y][0]+=mi;
			A[0][x]-=mi;
			A[y][x]+=mi;
		}
		else {
			if(A[y][0]>0&&A[0][x]<0) mi=min(A[y][0],-A[0][x]);
			if(A[y][0]<0&&A[0][x]>0) mi=max(A[y][0],-A[0][x]);
			A[0][0]-=mi;
			A[y][0]-=mi;
			A[0][x]+=mi;
			A[y][x]+=mi;
		}
		
		
	}
	
	ll sum=0;
	FOR(y,H) FOR(x,W) sum+=abs(A[y][x]);
	cout<<sum<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
