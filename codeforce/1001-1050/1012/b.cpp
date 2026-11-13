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

int T;
ll N,K,A[202020],B[202020],C[404040];

int ok(int v) {
	if(v<=0) return 0;
	int i;
	deque<int> D;
	ll sum=0;
	for(i=N-1;i>=0;i--) {
		if(D.size()&&D[0]-i>v) D.pop_front();
		if(D.size()&&N-1-i>=v) sum+=max(0LL,C[D[0]]-C[i]);
		if(sum>K) return 0;
		while(D.size()&&C[D.back()]>C[i]) D.pop_back();
		D.push_back(i);
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		ll sum=0;
		ll mi=1LL<<60;
		int tar=0;
		FOR(i,N) {
			sum+=A[i]-B[i];
			if(sum<mi) {
				mi=sum;
				tar=i;
			}
		}
		rotate(A,A+tar+1,A+N);
		rotate(B,B+tar+1,B+N);
		sum=0;
		FOR(i,N) {
			sum+=A[i];
			C[i+1]=C[i]+A[i]-B[i];
		}
		if(sum==K) {
			cout<<0<<endl;
			continue;
		}
		
		int ret=N;
		for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
