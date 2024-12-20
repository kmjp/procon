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
vector<pair<int,int>> Es[802020];
vector<pair<int,int>> E[802020];
map<pair<int,int>,int> EID;
int st,ta;
int dp[808080];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		EID.clear();
		int num=N;
		FOR(i,2*(N+M)) {
			E[i].clear();
			Es[i].clear();
			dp[i]=1<<30;
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			x--,y--;
			Es[x].push_back({y,k});
			Es[y].push_back({x,k});
			EID[{x,y}]=num++;
			EID[{y,x}]=num++;
			E[EID[{x,y}]].push_back({EID[{y,x}],0});
			E[EID[{y,x}]].push_back({EID[{x,y}],0});
		}
		FOR(i,N) {
			map<int,vector<int>> C;
			FORR2(e,c,Es[i]) C[c].push_back(e);
			vector<int> D;
			FORR2(a,vs,C) {
				if(vs.size()>1) {
					FOR(j,vs.size()) E[EID[{i,vs[j]}]].push_back({EID[{i,vs[(j+1)%vs.size()]}],0});
				}
				E[i].push_back({EID[{i,vs[0]}],0});
				E[EID[{i,vs[0]}]].push_back({i,1});
			}
		}
		cin>>st>>ta;
		st--,ta--;
		dp[st]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,st});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
		}
		cout<<dp[ta]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
