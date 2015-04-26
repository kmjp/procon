#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
vector<int> E[2050];
ll val[2050][2050];
ll mo=1000000007;
int num[2050];

void dfs(int cur,int pre) {
	int i,j,x;
	vector<ll> nn[2];
	nn[0]=vector<ll>(2020,0);
	nn[1]=vector<ll>(2020,0);
	
	FOR(i,E[cur].size()) if(E[cur][i]==pre) break;
	if(i<E[cur].size()) E[cur].erase(E[cur].begin()+i);
	
	num[cur]=1;
	nn[0][0]=1;
	
	FOR(x,E[cur].size()) {
		int cu=x%2,ta=cu^1;
		int tar=E[cur][x];
		FOR(i,2020) nn[ta][i]=0;
		
		dfs(tar,cur);
		for(i=0;i<=num[tar];i++) if(val[tar][i]) {
			for(j=0;j<num[cur];j++) nn[ta][i+j] += nn[cu][j]*val[tar][i]%mo;
		}
		num[cur]+=num[tar];
		FOR(i,num[cur]+1) nn[ta][i] %= mo;
	}
	
	FOR(i,2010) val[cur][i]=nn[E[cur].size()%2][i];
	val[cur][num[cur]]=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(0,-1);
	cout<<val[0][K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
