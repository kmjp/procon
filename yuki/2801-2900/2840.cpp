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
int A[3030];
int K;

int from[111010];
int to[111010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N<=20) K=100000;
	else if(N<=200) K=50000;
	else K=10000;

	int ret=-1;
	int S=0;
	from[0]=1;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		for(j=K;j>=0;j--) from[j+A[i]]=min(2,from[j+A[i]]+from[j]);
	}
	
	FOR(i,K+1) if(from[i]>=2) ret=max(ret,S-i*2);
	if(ret==0) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
