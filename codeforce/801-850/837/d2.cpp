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
string S;
vector<int> E[2020];
int D[2020][2020];
int P[2020][2020];
vector<pair<int,pair<int,int>>> V;
int dp[2020][2020];
void dfs(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	P[id][cur]=pre;
	V.push_back({d,{id,cur}});
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) E[i].clear();
		V.clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		FOR(i,N) dfs(i,i,i,0);
		sort(ALL(V));
		int ret=0;
		FORR2(d,p,V) {
			x=p.first;
			y=p.second;
			if(d==0) {
				dp[x][y]=1;
			}
			else if(d==1) {
				dp[x][y]=1+(S[x]==S[y]);
			}
			else {
				dp[x][y]=max(dp[x][P[x][y]],dp[y][P[y][x]]);
				if(S[x]==S[y]) dp[x][y]=max(dp[x][y],dp[P[x][y]][P[y][x]]+2);
			}
			ret=max(ret,dp[x][y]);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
