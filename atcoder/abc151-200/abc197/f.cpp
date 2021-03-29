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
vector<int> E[1010][26];
int D[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) D[x][y]=(x==y?0:1LL<<30);
	FOR(i,M) {
		cin>>x>>y>>s;
		E[x-1][s[0]-'a'].push_back(y-1);
		E[y-1][s[0]-'a'].push_back(x-1);
		if(x!=y) D[x-1][y-1]=D[y-1][x-1]=1;
	}
	
	queue<int> Q;
	FOR(i,N) Q.push(i*1000+i);
	FOR(x,N) FOR(y,N) if(D[x][y]==1) Q.push(x*1000+y);
	
	while(Q.size()) {
		int u=Q.front()/1000;
		int v=Q.front()%1000;
		Q.pop();
		if(u==0&&v==N-1) {
			cout<<D[u][v]<<endl;
			return;
		}
		FOR(i,26) {
			FORR(x,E[u][i]) FORR(y,E[v][i]) {
				if(D[x][y]>D[u][v]+2) {
					D[x][y]=D[u][v]+2;
					Q.push(x*1000+y);
				}
			}
		}
		
		
	}
	
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
