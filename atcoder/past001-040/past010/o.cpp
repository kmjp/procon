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
vector<int> E[1010];
int id[1010];
vector<pair<int,int>> cand;
int C[2],lp;
int memo[1010][1010];

void dfs(int cur,int s) {
	if(id[cur]!=-1) {
		if(id[cur]!=s) lp=1;
		return;
	}
	id[cur]=s;
	C[s]++;
	FORR(e,E[cur]) dfs(e,s^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(id);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	
	vector<int> D(3);
	FOR(i,N) D[(i+1)%3]++;
	MINUS(memo);
	cand.push_back({0,0});
	int tot=0;
	FOR(i,N) if(id[i]==-1) {
		ZERO(C);
		lp=0;
		dfs(i,0);
		
		if(lp==0) {
			vector<pair<int,int>> add;
			FORR2(a,b,cand) {
				if(memo[a][b]==i) continue;
				memo[a][b]=i;
				if(a+C[0]<=D[1]&&b+C[1]<=D[2]) add.push_back({a+C[0],b+C[1]});
				if(a+C[1]<=D[1]&&b+C[0]<=D[2]) add.push_back({a+C[1],b+C[0]});
				if(tot-a-b+C[0]+C[1]<=D[0]) add.push_back({a,b});
			}
			cand=add;
		}
		tot+=C[0]+C[1];
	}
	
	FORR2(a,b,cand) {
		if(D[1]==a&&D[2]==b) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
