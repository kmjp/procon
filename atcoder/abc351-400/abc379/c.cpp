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

ll N,M;
ll X[202020],A[202020];
vector<pair<__int128,__int128>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>M;
	__int128 N=x;
	ll sum=N;
	FOR(i,M) cin>>X[i];
	FOR(i,M) cin>>A[i];
	FOR(i,M) {
		V.push_back({X[i],A[i]});
		sum-=A[i];
	}
	__int128 ret=0;
	sort(ALL(V));
	reverse(ALL(V));
	FORR2(x,a,V) {
		assert(x<=N);
		if(x+a-1>=N) a=N-x+1;
		ret+=(__int128)(N+N-(a-1))*a/2-1LL*x*a;
		N-=a;
	}
	if(N>0||sum) {
		cout<<-1<<endl;
	}
	else {
		cout<<(ll)ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
