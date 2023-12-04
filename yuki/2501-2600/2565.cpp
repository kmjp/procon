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
vector<int> E[101010];
int D[3][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,3) FOR(j,N) D[i][j]=1<<20;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	D[0][0]=D[1][N-2]=D[2][N-1]=0;
	queue<int> Q;
	Q.push(0);
	Q.push(N+N-2);
	Q.push(2*N+N-1);
	while(Q.size()) {
		int id=Q.front()/N;
		int cur=Q.front()%N;
		Q.pop();
		FORR(e,E[cur]) if(D[id][e]==1<<20) {
			D[id][e]=D[id][cur]+1;
			Q.push(id*N+e);
		}
	}
	int ret=1<<20;
	ret=min(ret,D[0][N-2]+D[1][N-1]+D[2][0]);
	ret=min(ret,D[0][N-1]+D[2][N-2]+D[1][0]);
	if(ret==1<<20) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
