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

int N,M,K;
int P[101010];
vector<int> E[101010],R[101010];
int in[101010];
int win[101010];
int step[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) cin>>P[i], P[i]--;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		R[y].push_back(x);
		in[x]++;
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		
		FORR(e,E[x]) if(win[e]==0) win[x]=1;
		
		if(win[x]==1) {
			step[x]=1<<20;
			FORR(e,E[x]) if(win[e]==0) step[x]=min(step[x],step[e]+1);
		}
		else {
			FORR(e,E[x]) step[x]=max(step[x],step[e]+1);
		}
		
		FORR(r,R[x]) if(--in[r]==0) Q.push(r);
	}
	
	int fastest=1<<20;
	int slowest=1<<20;
	FOR(i,K) {
		if(win[P[i]]) fastest=min(fastest,step[P[i]]);
		else slowest=min(slowest,step[P[i]]);
	}
	if(fastest<slowest) cout<<"A"<<endl;
	else cout<<"B"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
