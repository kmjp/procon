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
ll X[1010101];

ll A[1<<20];
ll B[1<<20][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ll S=0;
	FOR(i,N) {
		cin>>X[i];
		S+=(1<<20)-X[i];
		A[X[i]]++;
		FOR(j,20) B[X[i]][j]+=X[i]%(1<<j);
	}
	
	int mask;
	FOR(i,20) {
		FOR(mask,1<<20) if(!(mask&(1<<i))) {
			A[mask]+=A[mask^(1<<i)];
			FOR(j,20) B[mask][j]+=B[mask^(1<<i)][j];
		}
	}
	
	
	while(Q--) {
		ll K;
		cin>>K;
		
		ll ret=0;
		if(K>=S) {
			ret=(1<<20)+(K-S)/N;
			cout<<ret<<"\n";
			continue;
		}
		for(i=19;i>=0;i--) {
			ll add=(N-A[ret|(1<<i)])*(1LL<<i)-(B[ret][i]-B[ret^(1<<i)][i]);
			if(add<=K) {
				K-=add;
				ret|=1<<i;
			}
		}
		cout<<ret<<"\n";
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
