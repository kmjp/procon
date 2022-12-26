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

int N,L;
int D[302];
ll B[202];

ll F[202],G[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) cin>>D[i];
	for(i=N-1;i>=0;i--) {
		D[i+N]=D[i]+L;
		D[i+2*N]=D[i+N]+L;
	}
	FOR(i,2*N) cin>>B[i];
	
	
	FOR(i,2*N) {
		ll BS=B[(i+1)%(2*N)]-B[i];
		ll DS=D[(i+1)]-D[i];
		
		
		if(BS%DS) {
			cout<<"No"<<endl;
			return;
		}
		F[i]=BS/DS;
	}
	
	FOR(i,2*N) {
		G[i]=F[i]-F[(i+2*N-1)%(2*N)];
		if(G[i]%2) {
			cout<<"No"<<endl;
			return;
		}
		G[i]/=2;
		if(i>=N&&G[i]!=-G[i-N]) {
			cout<<"No"<<endl;
			return;
		}
	}
	FOR(i,2*N) if(G[i]>0) {
		FOR(x,2*N) {
			ll d=min(abs(D[i]-D[x]),2*L-abs(D[i]-D[x]));
			B[x]-=d*G[i];
		}
	}
	if(B[0]<0||B[0]%L) {
		cout<<"No"<<endl;
		return;
	}
	FOR(i,2*N) if(B[i]!=B[0]) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
