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
int dp[202020];
int ma;
vector<int> cand[202020];

int dfs(int cur,int pre) {
	
	FORR(e,E[cur]) if(e!=pre) cand[cur].push_back(dfs(e,cur));
	
	sort(ALL(cand[cur]));
	reverse(ALL(cand[cur]));
	if(cur==0) {
		if(cand[cur].size()>=4) {
			int sum=1+cand[cur][0]+cand[cur][1]+cand[cur][2]+cand[cur][3];
			ma=max(ma,sum);
		}
		return 0;
	}
	else {
		if(cand[cur].size()>=3) {
			int sum=1+cand[cur][0]+cand[cur][1]+cand[cur][2];
			ma=max(ma,sum);
			dp[cur]=sum;
			return sum;
		}
		else {
			return 0;
		}
	}
}
void dfs2(int cur,int pre,int par) {
	if(par>=0) {
		cand[cur].push_back(par);
	}
	sort(ALL(cand[cur]));
	reverse(ALL(cand[cur]));
	if(cand[cur].size()>=4) {
		ma=max(ma,1+cand[cur][0]+cand[cur][1]+cand[cur][2]+cand[cur][3]);
	}
	
	FORR(e,E[cur]) if(e!=pre) {
		if(cand[cur].size()>=4) {
			int sum=1;
			if(cand[cur][0]==dp[e]) sum=1+cand[cur][1]+cand[cur][2]+cand[cur][3];
			else if(cand[cur][1]==dp[e]) sum=1+cand[cur][0]+cand[cur][2]+cand[cur][3];
			else if(cand[cur][2]==dp[e]) sum=1+cand[cur][0]+cand[cur][1]+cand[cur][3];
			else sum=1+cand[cur][0]+cand[cur][1]+cand[cur][2];
			dfs2(e,cur,sum);
		}
		else {
			dfs2(e,cur,0);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	dfs2(0,0,-1);
	if(ma==0) {
		cout<<-1<<endl;
	}
	else {
		cout<<3*ma+2<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
