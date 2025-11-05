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

int N,M;
int D[25][25];

int E[202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N<=5) {
		cout<<-1<<endl;
		return;
	}
	FOR(x,N) FOR(y,N) E[x][y]=(x==y)?0:1010;
	FOR(x,N) FOR(y,N) {
		if(x==y) continue;
		if(N%2==0) {
			if(x+y==N-1) continue;
		}
		else {
			if(x+y==N-2) continue;
		}
		if(x<N/2&&y>=N/2)  E[x][y]=E[y][x]=1;
	}
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	set<int> S={0};
	FOR(y,N) {
		int sum=0;
		FOR(x,N) if(E[x][y]==1||E[x][y]==2) sum+=x+1;
		S.insert(sum);
		
	}
	assert(S.size()==2);
	
	vector<pair<int,int>> E2;
	FOR(x,N) FOR(y,N) if(x<y&&E[x][y]==1) E2.push_back({x+1,y+1});
	cout<<E2.size()<<endl;
	FORR2(a,b,E2) cout<<a<<" "<<b<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
