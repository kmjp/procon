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

int T,N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			A[N+i]=A[i];
		}
		int mi=1<<20;
		int U=1,D=1;
		
		for(i=1;i<2*N;i++) {
			if(A[i-1]>A[i]) U=0;
			if(A[i-1]<A[i]) D=0;
			U++;
			D++;
			x=(i+1)%N;
			if(U>=N) {
				if(x==0) mi=0;
				mi=min(mi,N-x);
				mi=min(mi,x+2);
			}
			if(D>=N) {
				mi=min(mi,N-x+1);
				mi=min(mi,x+1);
			}
			
		}
		if(mi==1<<20) mi=-1;
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
