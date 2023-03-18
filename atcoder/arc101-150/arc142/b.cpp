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
int A[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int nex=1;
	FOR(y,N) FOR(x,N) if((y+x)%2==0) A[y][x]=nex++;
	FOR(y,N) FOR(x,N) if((y+x)%2==1) A[y][x]=nex++;
	/*
	FOR(i,N/2) {
		for(x=i;x<N-i;x++) {
			A[i][x]=nex++;
		}
		for(y=i+1;y<N-1-i;y++) {
			A[y][i]=nex++;
			A[y][N-1-i]=nex++;
		}
		for(x=i;x<N-i;x++) {
			A[N-1-i][x]=nex++;
		}
	}
	*/
	FOR(y,N) FOR(x,N) {
		int a=0,b=0;
		for(int ty=max(0,y-1);ty<=min(y+1,N-1);ty++) {
			for(int tx=max(0,x-1);tx<=min(x+1,N-1);tx++) {
				if(A[y][x]<A[ty][tx]) a++;
				if(A[y][x]>A[ty][tx]) b++;
			}
		}
		assert(a!=b);
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
