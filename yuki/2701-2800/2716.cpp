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

int N,Q;
string S;
ll SD[202020];
ll SR[202020];

ll getD(ll v) {
	if(SD[N]==0) return 1LL<<60;
	ll a=N*((v-1)/SD[N]);
	v-=(v-1)/SD[N]*SD[N];
	assert(v<=SD[N]);
	a+=lower_bound(SD,SD+N+1,v)-SD;
	return a;
}
ll getR(ll v) {
	if(SR[N]==0) return 1LL<<60;
	ll a=N*((v-1)/SR[N]);
	v-=(v-1)/SR[N]*SR[N];
	assert(v<=SR[N]);
	a+=lower_bound(SR,SR+N+1,v)-SR;
	return a;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		SD[i+1]=SD[i];
		SR[i+1]=SR[i];
		if(S[i]=='D') SD[i+1]++;
		if(S[i]=='R') SR[i+1]++;
	}
	
	while(Q--) {
		ll H,W,P;
		cin>>H>>W>>P;
		
		cout<<min(getD(SD[P]+H),getR(SR[P]+W))%N<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
