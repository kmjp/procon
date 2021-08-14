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

int N,P,K;
ll A[40][40];
ll B[40][40];


ll hoge(ll X) {
	int x,y,z;
	FOR(y,N) FOR(x,N) {
		if(A[y][x]==-1) B[y][x]=X;
		else B[y][x]=A[y][x];
	}
	FOR(z,N) FOR(x,N) FOR(y,N) B[x][y]=min(B[x][y],B[x][z]+B[z][y]);
	int ret=0;
	FOR(y,N) FOR(x,y) if(B[x][y]<=P) ret++;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>K;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	
	x=hoge(P+1);
	if(x>K) {
		cout<<0<<endl;
	}
	else if(x==K) {
		cout<<"Infinity"<<endl;
	}
	else {
		int L=0,R=P+1;
		for(i=29;i>=0;i--) {
			if(L+(1<<i)<P+1&&hoge(L+(1<<i))>K) L+=1<<i;
			if(R-(1<<i)>0&&hoge(R-(1<<i))<K) R-=1<<i;
		}
		cout<<R-L-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
