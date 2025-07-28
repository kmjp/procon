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

int N,M,K,T,Q;
ll E[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	N++;
	
	FOR(x,N) FOR(y,N) E[x][y]=(x==y)?0:1LL<<60;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1][y-1]=E[y-1][x-1]=min(E[x-1][y-1],(ll)k);
	}
	cin>>K>>T;
	FOR(i,K) {
		cin>>x;
		E[x-1][N-1]=1;
		E[N-1][x-1]=T-1;
	}
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>j>>k;
			i--,j--;
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][i]+k+E[j][y]);
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][j]+k+E[i][y]);
		}
		else if(i==2) {
			cin>>k;
			k--;
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+1+E[N-1][y]);
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][N-1]+T-1+E[k][y]);
		}
		else if(i==3) {
			ll ret=0;
			FOR(y,N-1) FOR(x,N-1) if(E[x][y]<1LL<<60) ret+=E[x][y];
			cout<<ret<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
