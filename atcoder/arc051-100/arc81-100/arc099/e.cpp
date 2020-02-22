#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int C[700][700];
vector<int> E[707];
int vis[707];
int cnt[2];
int ok[707][707];

void dfs(int cur,int c) {
	if(vis[cur]!=-1) {
		if(vis[cur]==c) return;
		cout<<"-1"<<endl;
		exit(0);
		return;
	}
	cnt[c]++;
	vis[cur]=c;
	FORR(e,E[cur]) dfs(e,c^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		C[x-1][y-1]=C[y-1][x-1]=1;
	}
	FOR(x,N) {
		C[x][x]=1;
		FOR(y,N) if(C[x][y]==0) E[x].push_back(y);
	}
	
	
	ok[0][0]=1;
	int sum=0;
	MINUS(vis);
	FOR(i,N) if(vis[i]==-1) {
		cnt[0]=cnt[1]=0;
		dfs(i,0);
		
		FOR(x,sum+1) if(ok[x][sum-x]) {
			ok[x+cnt[0]][sum-x+cnt[1]]=1;
			ok[x+cnt[1]][sum-x+cnt[0]]=1;
		}
		
		sum+=cnt[0]+cnt[1];
	}
	
	int mi=1<<30;
	FOR(x,N+1) if(ok[x][N-x]) mi=min(mi,x*(x-1)/2+(N-x)*(N-x-1)/2);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
