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

int T;
int N,M;
vector<int> E[2020];
int C[2020];
int D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>C[i];
			E[i].clear();
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		FOR(x,N) FOR(y,N) D[x][y]=1<<30;
		D[0][N-1]=0;
		queue<int> Q;
		Q.push(N-1);
		while(Q.size()) {
			int X=Q.front()/2000;
			int Y=Q.front()%2000;
			Q.pop();
			FORR(e1,E[X]) FORR(e2,E[Y]) if(C[e1]!=C[e2]&&D[e1][e2]>=1<<30) {
				D[e1][e2]=D[X][Y]+1;
				Q.push(e1*2000+e2);
			}
		}
		if(D[N-1][0]==1<<30) {
			cout<<-1<<endl;
		}
		else {
			cout<<D[N-1][0]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
