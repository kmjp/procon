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
ll K;
ll A[202020];
ll num[202020];
int L[202020],R[202020];

void merge(int a) {
	int b=R[a];
	assert(A[a]==A[b]);
	num[a]=num[b]=num[a]+num[b];
	R[a]=R[b];
	L[R[a]]=a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A[0]=A[N+3]=-1;
	A[1]=A[N+2]=0;
	FOR(i,N) {
		cin>>A[i+2];
		num[i+2]=1;
	}
	FOR(i,N+4) {
		L[i]=i-1;
		R[i]=i+1;
	}
	int cur=1;
	while(cur<=N+2) {
		if(A[cur]==A[R[cur]]) {
			merge(cur);
		}
		else {
			cur=R[cur];
		}
	}
	set<pair<int,int>> S;
	cur=1;
	while(cur<=N+2) {
		if(A[cur]>0&&A[cur]>A[L[cur]]&&A[cur]>A[R[cur]]) {
			S.insert({num[cur],cur});
		}
		cur=R[cur];
	}
	while(S.size()) {
		int cur=S.begin()->second;
		S.erase(S.begin());
		ll v=min(A[cur]-max(A[L[cur]],A[R[cur]]),K/num[cur]);
		A[cur]-=v;
		if(v==0) break;
		K-=v*num[cur];
		if(A[cur]==A[L[cur]]) {
			cur=L[cur];
			merge(cur);
		}
		if(A[cur]==A[R[cur]]) {
			merge(cur);
		}
		if(A[cur]>0&&A[cur]>A[L[cur]]&&A[cur]>A[R[cur]]) {
			S.insert({num[cur],cur});
		}
	}
	
	ll ret=0;
	cur=1;
	while(cur<=N+2) {
		if(A[cur]>0||A[R[cur]]>0) {
			ret+=abs(A[cur]-A[R[cur]]);
		}
		cur=R[cur];
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
