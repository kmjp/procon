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

int T,N,K;
int A[303030];

int B[303030];
int hoge(ll v) {
	priority_queue<int> Q;
	ll sum=0;
	int i;
	FOR(i,N) {
		sum+=A[i];
		Q.push(A[i]);
		while(sum>v) {
			sum-=Q.top();
			Q.pop();
		}
		if(Q.size()>=K) return K;
		B[i+1]=Q.size();
	}
	sum=0;
	while(Q.size()) Q.pop();
	
	int ma=B[N];
	for(i=N-1;i>=0;i--) {
		sum+=A[i];
		Q.push(A[i]);
		while(sum>v) {
			sum-=Q.top();
			Q.pop();
		}
		ma=max(ma,B[i]+(int)Q.size());
		if(ma>=K) return K;
	}
	return ma;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		
		ll ret=1LL<<50;
		for(i=49;i>=0;i--) if(hoge(ret-(1LL<<i))>=K) ret-=1LL<<i;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
