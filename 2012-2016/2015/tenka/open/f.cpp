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

int N,Q,M,K;
vector<int> E[101010];
int P[21][101010],D[100005];
int L[101010],R[101010],idt[101010];
int id=1;

void dfs(int cur,int pre) {
	int i,p=-1;
	if(pre!=-1) D[cur]=D[pre]+1;
	
	P[0][cur]=pre;
	idt[id]=cur;
	L[cur]=id++;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) p=i;
		else dfs(tar,cur);
	}
	R[cur]=id;
	if(p>=0) E[cur].erase(E[cur].begin()+p);
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		cin>>M>>K;
		vector<int> v;
		while(M--) {
			cin>>x;
			v.push_back(L[x-1]);
		}
		sort(v.begin(),v.end());
		int mad=0;
		for(i=0;i+K-1<v.size();i++) {
			x=idt[v[i]];
			y=idt[v[i+K-1]];
			
			mad=max(mad,D[lca(x,y)]);
		}
		cout<<mad<<endl;
		
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
