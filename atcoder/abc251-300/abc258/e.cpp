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

ll N,Q,X;
ll W[202020];
ll S[202020];
ll num[202020];
ll nex[202020][50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>X;
	FOR(i,N) {
		cin>>W[i];
	}
	FOR(i,2*N) {
		S[i+1]=S[i]+W[i%N];
	}
	
	FOR(i,N) {
		ll a=X/S[N];
		ll b=X%S[N];
		num[i]=a*N;
		
		x=lower_bound(S,S+2*N,S[i]+b)-&S[i];
		num[i]+=x;
		nex[i][0]=(i+x)%N;
		
	}
	FOR(i,48) {
		FOR(j,N) nex[j][i+1]=nex[nex[j][i]%N][i];
	}
	while(Q--) {
		ll K;
		cin>>K;
		K--;
		ll cur=0;
		FOR(i,44) if(K&(1LL<<i)) cur=nex[cur][i];
		cout<<num[cur]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
