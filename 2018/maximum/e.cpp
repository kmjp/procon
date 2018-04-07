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
string S[202020];
int X[202020],Y[202020];
int V=0;

vector<int> E[200005];
int P[21][200005],D[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V=1;
	FOR(i,N) {
		cin>>S[i]>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		if(S[i]=="A") {
			E[X[i]].push_back(Y[i]);
			V++;
		}
	}
	
	dfs(0);
	FOR(i,19) FOR(x,V) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N) if(S[i]=="B") {
		cout<<dist(X[i],Y[i])-1<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
