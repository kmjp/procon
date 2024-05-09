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

int N;
vector<int> E[202020];
int D[3][202020];
int root[202020];
int C[202020];
int MD=-1,MV=-1;

void dfs(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,id,d+1);
	}
}
int dfs2(int cur,int pre,int d,int b) {
	D[2][cur]=d;
	C[cur]=1;
	FORR(e,E[cur]) if(root[e]==0&&e!=pre) {
		C[cur]+=dfs2(e,cur,d+1,b);
	}
	if(2*C[cur]>b) {
		if(d>MD) {
			MD=d;
			MV=cur;
		}
	}
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0,0,0);
	dfs(N-1,N-1,1,0);
	
	if(D[0][N-1]%2!=N%2) {
		cout<<-1<<endl;
		return;
	}
	
	FOR(i,N) if(D[0][i]+D[1][i]==D[0][N-1]) root[i]=1;
	
	FOR(i,N) if(root[i]) dfs2(i,i,0,N+D[0][i]-D[1][i]);
	
	int ret=D[0][N-1]+1;
	if(MV!=-1) {
		ret+=MD;
		vector<int> cand;
		FORR(e,E[MV]) if(D[2][e]>D[2][MV]) cand.push_back(C[e]);
		int w=0;
		sort(ALL(cand));
		reverse(ALL(cand));
		FORR(c,cand) {
			if(w<C[MV]-w-(D[0][MV]+N-C[MV]-D[1][MV])) ret++;
			w+=c;
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
