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
int A[4][100000];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mi=1<<30;
	cin>>N;
	FOR(i,4) {
		FOR(j,N) cin>>A[i][j];
		sort(A[i],A[i]+N);
	}
	int B[4]={};
	while(1) {
		if(B[0]>=N||B[1]>=N||B[2]>=N||B[3]>=N) break;
		x=0,y=1<<30,j=0;
		FOR(i,4) {
			x=max(x,A[i][B[i]]);
			y=min(y,A[i][B[i]]);
			if(y==A[i][B[i]]) j=i;
		}
		mi=min(mi,x-y);
		B[j]++;
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
