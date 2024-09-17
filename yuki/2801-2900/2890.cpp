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
int A[1<<20];
int mi[1<<20],ma[1<<20];
int L,R;

int hoge(int v) {
	if(1LL*v*K>N) return 0;
	int i;
	for(int s=L;s<=R;s++) if(s%2) {
		int cur=s%N;
		FOR(i,K) {
			if(ma[cur%N]<v) break;
			cur+=max(v,mi[cur%N]);
		}
		if(i==K&&cur-(s%N)<=N) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	N*=2;
	FOR(i,K) {
		cin>>A[i];
		A[i]--;
		A[i+K]=A[i]+N;
	}
	int m=0;
	FOR(i,K) if(A[i+1]-A[i]<A[m+1]-A[m]) m=i;
	L=A[m]+1;
	R=A[m+1]-1;
	FOR(i,K) {
		for(x=A[i]+1;x<A[i+1];x++) if(x%2) {
			mi[x%N]=A[i+1]+1-x;
			ma[x%N]=A[i+2]-1-x;
		}
	}
	
	int ret=0;
	for(i=20;i>=1;i--) if(hoge(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
