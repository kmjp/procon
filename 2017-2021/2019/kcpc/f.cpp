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

int N,K;
vector<string> S;
map<int,int> E[501011];
int P[501011][20],Q[501011];
int M;
int win[501011];

void dfs(int cur,int pre,string& S) {
	P[cur][0]=pre;
	if(S.empty()) return;
	int nex=S.back();
	S.pop_back();
	if(E[cur].count(nex)==0) E[cur][nex]=M++;
	dfs(E[cur][nex],cur,S);
}

void dfs2(int cur,string& S) {
	int i;
	FORR(m,E[cur]) {
		S.push_back(m.first);
		dfs2(m.second,S);
		S.pop_back();
		win[cur]+=win[m.second];
	}
	
	if(win[cur]==0) {
		win[P[cur][0]]++;
		win[Q[cur]]--;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	M=2;
	S.resize(N);
	FOR(i,N) {
		cin>>S[i];
		reverse(ALL(S[i]));
		dfs(1,0,S[i]);
	}
	FOR(i,18) FOR(x,M) P[x][i+1]=P[P[x][i]][i];
	FOR(x,M) {
		Q[x]=x;
		FOR(i,18) if((K+1)&(1<<i)) Q[x]=P[Q[x]][i];
	}
	
	dfs2(1,s);
	if(win[1]==0) cout<<"tempura"<<endl;
	else cout<<"yamunaku"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
