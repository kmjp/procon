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

int N,X[4];

map<vector<int>,int> MP;
vector<vector<int>> V;

vector<int> E[22];

int state[50050][12];
ll dp[50][20202];
ll mo=1000000007;

int isok(vector<int> v) {
	int cur=0, st=0, ng=0;
	FORR(r,v) {
		cur+=r;
		if(cur==X[st]) st++,cur=0;
		else if(cur>X[st]) return 0;
	}
	return 1+(st==3);
}

int getstate(vector<int> v) {
	
	int ret=isok(v);
	
	if(ret>0) {
		if(ret==2) return 0;
		MP[v]=MP.size();
		V.push_back(v);
		E[v.size()].push_back(MP[v]);
		return MP[v];
	}
	while(1) {
		v.erase(v.begin());
		if(isok(v)==2) return 0;
		if(MP.count(v)) return MP[v];
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X[0]>>X[1]>>X[2];
	
	V.push_back(vector<int>());
	V.push_back(vector<int>());
	
	MP[vector<int>()]=1;
	E[0].push_back(1);
	FOR(i,18) {
		FORR(r,E[i]) {
			vector<int> v=V[r];
			for(x=1;x<=10;x++) {
				v.push_back(x);
				state[r][x]=getstate(v);
				v.pop_back();
			}
		}
	}
	
	dp[0][1]=1;
	FOR(i,N) FOR(j,V.size()) for(x=1;x<=10;x++) (dp[i+1][state[j][x]] += dp[i][j])%=mo;
	ll ret=0;
	FOR(j,V.size()) ret += dp[N][j];
	cout<<dp[N][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
