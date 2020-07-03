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

int N;
int TC,TW;
string S;
int CC[101010],CW[101010];
vector<int> E[101010];
ll ret;

void dfs(int cur,int pre) {
	if(S[cur]=='c') CC[cur]=1;
	if(S[cur]=='w') CW[cur]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		CC[cur]+=CC[e];
		CW[cur]+=CW[e];
		if(S[cur]=='w') ret += 1LL*CC[e]*(TW-1-CW[e]);
	}
	
	if(S[cur]=='w') ret += 1LL*(TC-CC[cur])*(CW[cur]-1);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) if(c=='c') TC++;
	FORR(c,S) if(c=='w') TW++;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
