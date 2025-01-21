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
ll M;
ll P[202020];
ll C[202020];

ll issq(ll V) {
	if(V<0) return -1;
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return -1;
}


int can(ll b) {
	int i;
	__int128 sum=0;
	FOR(i,N) {
		ll a=b/P[i];
		__int128 c=(a+1)/2;
		sum+=c*c*P[i];
		if(sum>M) return 0;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>P[i];
	}
	
	ll border=0;
	for(i=60;i>=0;i--) if(can(border+(1LL<<i))) border+=1LL<<i;
	
	ll sum=0;
	FOR(i,N) {
		ll a=border/P[i];
		ll c=(a+1)/2;
		sum+=c;
		M-=c*c*P[i];
	}
	sum+=M/(border+1);
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
