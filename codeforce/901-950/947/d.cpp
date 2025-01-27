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

int T,N;
int A,B;
vector<int> E[202020];
int D[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		cin>>A>>B;
		A--,B--;
		FOR(i,N) {
			E[i].clear();
			D[0][i]=D[1][i]=D[2][i]=1<<20;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		D[0][A]=D[1][B]=0;
		queue<int> Q;
		Q.push(A);
		Q.push(N+B);
		while(Q.size()) {
			int id=Q.front()/N;
			int cur=Q.front()%N;
			Q.pop();
			FORR(e,E[cur]) if(chmin(D[id][e],D[id][cur]+1)) Q.push(id*N+e);
		}
		int ret=(D[0][B]+1)/2;
		FOR(i,N) {
			if((D[0][i]+D[1][i]==D[0][B]&&D[0][i]==D[1][i])||(D[0][i]+D[1][i]==D[0][B]&&D[0][i]+1==D[1][i])) x=i;
		}
		FOR(i,N) D[0][i]=1<<20;
		ret+=2*(N-1);
		D[0][x]=0;
		Q.push(x);
		int ma=0;
		while(Q.size()) {
			int id=Q.front()/N;
			int cur=Q.front()%N;
			Q.pop();
			ma=max(ma,D[0][cur]);
			FORR(e,E[cur]) if(chmin(D[id][e],D[id][cur]+1)) Q.push(id*N+e);
		}
		ret-=ma;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
