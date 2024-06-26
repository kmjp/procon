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
string S;
const ll mo=998244353;

ll from[1<<9],to[1<<19];
int ok[1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>S;
	int mask;
	FOR(mask,1<<K) {
		FOR(i,K) if(((mask>>i)&1) !=((mask>>(K-1-i))&1)) ok[mask]=1;
	}
	
	from[0]=1;
	FOR(i,N) {
		ZERO(to);
		FOR(mask,1<<(K-1)) {
			if(S[i]!='B') if(i<K-1||ok[(mask<<1)]) to[(mask<<1)&((1<<(K-1))-1)]+=from[mask];
			if(S[i]!='A') if(i<K-1||ok[(mask<<1)+1]) to[(((mask<<1)+1))&((1<<(K-1))-1)]+=from[mask];
		}
		FOR(mask,1<<(K-1)) from[mask]=to[mask]%mo;
		
	}
	ll ret=0;
	FOR(mask,1<<(K-1)) ret+=from[mask];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
