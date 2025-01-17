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

int T,N,K,PB,PS;
int P[202020],A[202020];

ll dfs(int cur,int K,int start) {
	if(K==0) return 0;
	if(cur==start) return 1LL*K*A[cur];
	return max(1LL*K*A[cur],A[cur]+dfs(P[cur],K-1,(start==-1?cur:start)));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>PB>>PS;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
		}
		FOR(i,N) {
			cin>>A[i];
		}
		
		ll a=dfs(PB-1,K,-1);
		ll b=dfs(PS-1,K,-1);
		if(a>b) {
			cout<<"Bodya"<<endl;
		}
		else if(a<b) {
			cout<<"Sasha"<<endl;
		}
		else {
			cout<<"Draw"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
