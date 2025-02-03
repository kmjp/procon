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

int N,K;
int A[303][303];

int col(int y,int x) {
	if(A[y][x]==0) return 0;
	if(A[y][x+1]==0) return 0;
	if(A[y+1][x]==0) return 0;
	if(A[y+1][x+1]==0) return 0;
	set<int> V;
	V.insert(A[y][x]);
	V.insert(A[y][x+1]);
	V.insert(A[y+1][x]);
	V.insert(A[y+1][x+1]);
	return V.size()>=3;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) {
		cin>>A[y+1][x+1];
	}
	int cur=0;
	FOR(y,N-1) FOR(x,N-1) {
		cur+=col(y+1,x+1);
	}
	int dif=0;
	FOR(y,N) FOR(x,N) {
		set<int> cand;
		for(i=1;i<=min(K,9);i++) cand.insert(i);
		int v=A[y+1][x+1];
		int pre=col(y,x)+col(y,x+1)+col(y+1,x)+col(y+1,x+1);
		FORR(c,cand) {
			A[y+1][x+1]=c;
			int c2=col(y,x)+col(y,x+1)+col(y+1,x)+col(y+1,x+1);
			dif=max(dif,c2-pre);
		}
		A[y+1][x+1]=v;
		
	}
	cout<<cur+dif<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
