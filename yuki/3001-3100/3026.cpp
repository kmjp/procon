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


const int B=205020;
const int DI=60;
vector<int> D[B];
int FD[202020];
ll dp[B/DI][B/DI];
vector<int> pos[B];
const ll mo=998244353;
int N,Q;
int A[B];
vector<pair<int,int>> pre[B],nex[B];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=200000;i++) if(D[i].empty()) {
		for(j=i;j<=200000;j+=i) {
			FD[j]=i;
			x=j;
			while(x%i==0) x/=i;
			D[j].push_back(j/x);
		}
	}
	
	FOR(i,B) pos[i].push_back(0);
	
	cin>>N;
	FOR(i,B) A[i]=1;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		FORR(d,D[A[i]]) {
			x=FD[d];
			y=d;
			while(y>1) {
				nex[pos[y].back()].push_back({i,x});
				pre[i].push_back({pos[y].back(),x});
				pos[y].push_back(i);
				y/=x;
			}
		}
	}
	FOR(i,B) if(pos[i].back()!=0) nex[pos[i].back()].push_back({N+1,FD[i]});
	
	FOR(x,B/DI-1) FOR(y,B/DI-1) dp[x][y]=1;
	for(i=0;i<=N+DI;i++) FORR2(p,v,pre[i]) (dp[p/DI+1][i/DI+1]*=v)%=mo;
	FOR(x,B/DI-1) FOR(y,B/DI-1) {
		if(y<=x) dp[x][y]=1;
		(dp[x+1][y]*=dp[x][y])%=mo;
	}
	FOR(x,B/DI-1) FOR(y,B/DI-1) {
		if(y<=x) dp[x][y]=1;
		(dp[x][y+1]*=dp[x][y])%=mo;
	}
	
	cin>>Q;
	ll ret=1;
	while(Q--) {
		ll qa,qb;
		cin>>qa>>qb;
		x=(qa*ret%mo)%N+1;
		y=(qb*ret%mo)%N+1;
		if(x>y) swap(x,y);
		y++;
		ret=1;
		if(y-x<=3*DI) {
			ret=A[x];
			for(i=x+1;i<y;i++) {
				FORR2(a,b,pre[i]) if(a<x) ret=ret*b%mo;
			}
		}
		else {
			int L=(x+DI-1)/DI*DI;
			int R=y/DI*DI;
			ret=dp[L/DI][R/DI];
			while(x<L) {
				L--;
				int m=1;
				FORR2(a,b,nex[L]) if(a>=R) m*=b;
				ret=ret*m%mo;
			}
			while(R<y) {
				int m=1;
				FORR2(a,b,pre[R]) if(a<x) m*=b;
				ret=ret*m%mo;
				R++;
			}
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
