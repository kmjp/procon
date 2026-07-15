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
int cost[1<<20];

__int128 comb(ll N_, ll C_) {
	
	__int128 ret=1;
	
	if(C_*2>N_) C_=N_-C_;
	for(int i=1;i<=C_;i++) {
		ret=ret*N_/i;
		N_--;
		if(ret>1<<20) break;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<1<<20;i++) {
		x=i;
		while(x) {
			cost[i]++;
			x/=10;
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		ll ret=0;
		for(i=0;i<=N&&K>0;i++) {
			__int128 b=comb(N,i);
			ll a=min(b,(__int128)K);
			FOR(j,a) {
				ret+=1LL*cost[K--]*i;
			}
				
		}
		if(K>0) ret=-1;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
