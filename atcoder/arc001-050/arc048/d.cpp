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
 
int N,Q;
vector<int> E[101010];
string S;
int MI[101010];
 
int P[21][200005],D[200005];
int upf[21][200005];
int upl[21][200005];
 
void dfs(int cur) {
	MI[cur]=(S[cur]==0)?10101010:0;
	
	ITR(it,E[cur]) if(*it!=P[0][cur]) {
		D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
		MI[cur]=min(MI[cur],MI[*it]+1);
	}
}
 
void dfs2(int cur,int p) {
	MI[cur]=min(MI[cur],p+1);
	ITR(it,E[cur]) if(*it!=P[0][cur]) dfs2(*it,MI[cur]);
	
	upf[0][cur]=upl[0][cur]=5000000;
	if(cur!=0) {
		upf[0][cur]=min(MI[cur]*3+1,2+MI[P[0][cur]]*3);
		upl[0][cur]=min(MI[cur]*3+2,1+MI[P[0][cur]]*3);
	}
}
 
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}
 
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}
 
void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>S;
	FORR(r,S) r-='0';
	
	dfs(0);
	dfs2(0,505050);
	
	FOR(i,19) {
		FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			upf[i+1][x]=min(upf[i][x]+(1<<i),(2<<i)+upf[i][P[i][x]]);
			upl[i+1][x]=min(upl[i][x]+(2<<i),(1<<i)+upl[i][P[i][x]]);
		}
	}
	while(Q--) {
		int s,t;
		cin>>s>>t;
		s--,t--;
		int lc=lca(s,t);
		int ret=((D[t]-D[lc])+(D[s]-D[lc]))*2;
		if(s!=lc) {
			x=s;
			y=D[t]-D[lc];
			for(i=19;i>=0;i--) if(D[x]-D[lc]>=(1<<i)) {
				int p=getpar(x,1<<i);
				ret=min(ret,y+upf[i][x]+(D[p]-D[lc]));
				x=p;
				y+=2<<i;
			}
		}
		if(t!=lc) {
			x=t;
			y=2*(D[s]-D[lc]);
			for(i=19;i>=0;i--) if(D[x]-D[lc]>=(1<<i)) {
				int p=getpar(x,1<<i);
				ret=min(ret,y+upl[i][x]+2*(D[p]-D[lc]));
				x=p;
				y+=1<<i;
			}
		}
		cout<<ret<<endl;
	}
	
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}