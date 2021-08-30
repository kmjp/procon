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


int H,W,C;
ll A[1010][1010];
ll B[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>C;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		B[y][x]=1LL<<60;
	}
	ll mi=1LL<<60;
	FOR(y,H) FOR(x,W) {
		B[y][x]=A[y][x];
		if(y) {
			mi=min(mi,B[y-1][x]+C+A[y][x]);
			B[y][x]=min(B[y][x],B[y-1][x]+C);
		}
		if(x) {
			mi=min(mi,B[y][x-1]+C+A[y][x]);
			B[y][x]=min(B[y][x],B[y][x-1]+C);
		}
		
	}
	FOR(y,H) FOR(x,W) {
		B[y][x]=1LL<<60;
	}
	FOR(y,H) for(x=W-1;x>=0;x--) {
		B[y][x]=A[y][x];
		if(y) {
			mi=min(mi,B[y-1][x]+C+A[y][x]);
			B[y][x]=min(B[y][x],B[y-1][x]+C);
		}
		if(x<W-1) {
			mi=min(mi,B[y][x+1]+C+A[y][x]);
			B[y][x]=min(B[y][x],B[y][x+1]+C);
		}
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
