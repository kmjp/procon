#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

struct mag { ll A[3][3];};
vector<int> NN;
vector<mag> V[51];
vector<int> T[9];

map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	if(n==1) V[1]=1;
	else {
		for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
		if(n>1) V[n]++;
	}
	return V;
}

void enummag(int g) {
	mag m;
	if(V[g].size()) return;
	
	V[g].clear();
	m.A[1][1]=g;
	FOR(m.A[0][0],g*2+1) FOR(m.A[0][1],g*2+1) FOR(m.A[0][2],g*2+1) {
		int x=m.A[0][0]+m.A[0][1]+m.A[0][2];
		m.A[2][2]=x-m.A[0][0]-m.A[1][1];
		m.A[2][1]=x-m.A[0][1]-m.A[1][1];
		m.A[2][0]=x-m.A[0][2]-m.A[1][1];
		m.A[1][0]=x-m.A[0][0]-m.A[2][0];
		m.A[1][2]=x-m.A[0][2]-m.A[2][2];
		if(m.A[2][2]<0) continue;
		if(m.A[2][1]<0) continue;
		if(m.A[2][0]<0) continue;
		if(m.A[1][0]<0) continue;
		if(m.A[1][2]<0) continue;
		if(m.A[1][0]+m.A[1][1]+m.A[1][2]!=x) continue;
		V[g].push_back(m);
	}
	
}

ll ret;

void dfs(int cur) {
	int i,j;
	int same=0;
	
	FOR(i,9) for(j=i+1;!same&&j<9;j++) if(T[i]==T[j]) same=1;
	if(!same) {
		ll r=1;
		for(i=cur;i<NN.size();i++) r*=V[NN[i]].size();
		ret+=r;
		return;
	}
	
	if(cur==NN.size()) return;
	
	FOR(i,V[NN[cur]].size()) {
		FOR(j,9) T[j].push_back(V[NN[cur]][i].A[j/3][j%3]);
		dfs(cur+1);
		FOR(j,9) T[j].pop_back();
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll N;
	cin>>N;
	map<ll,int> M=enumdiv(N);
	
	ITR(it,M) NN.push_back(it->second), enummag(it->second);
	dfs(0);
	cout<<ret/8<<endl;
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
