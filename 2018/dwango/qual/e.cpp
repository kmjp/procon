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
vector<int> E[2020];
int P[21][200005],D[200005];
int L[2020],R[2020],eid;
int O[2020];
int S[2020];
int ddist[2020][2020];

void dfs2(int cur,int pre,int d,int id) {
	ddist[id][cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,d+1,id);
}

int ask(int u,int v) {
	int ret;
	cout<<"? "<<u<<" "<<v<<endl;
	cin>>ret;
	return ret;
}


void dfs(int cur) {
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
	R[cur]=eid;
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
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	P[0][1]=1;
	dfs(1);
	for(i=1;i<=N;i++) dfs2(i,i,0,i), O[x]=1;
	FOR(i,19) for(x=1;x<=N;x++) P[i+1][x]=P[i][P[i][x]];
	
	while(1) {
		Q--;
		assert(Q>=0);
		
		vector<int> C;
		ZERO(S);
		for(i=1;i<=N;i++) if(O[i]) {
			C.push_back(i);
			S[L[i]+1]++;
		}
		for(i=1;i<=N;i++) S[i]+=S[i-1];
		if(C.size()==1) {
			cout<<"! "<<C[0]<<endl;
			return;
		}
		
		int mi=101010;
		int LL,RR;
		FORR(x,C) FORR(y,C) if(D[x]>=D[y] && x!=y) {
			int lc=lca(x,y);
			int a,b,c;
			
			if(D[x]==D[y]) {
				int x2=getpar(x,D[x]-D[lc]-1);
				int y2=getpar(y,D[y]-D[lc]-1);
				a=S[R[x2]]-S[L[x2]];
				b=S[R[y2]]-S[L[y2]];
			}
			else if((D[x]+D[y])%2==0) {
				int z=D[lc]+(D[x]-D[y])/2;
				int x2=getpar(x,D[x]-z);
				int y2=getpar(x,D[x]-z-1);
				a=S[R[x2]]-S[L[x2]];
				b=S[R[y2]]-S[L[y2]];
				a-=b;
			}
			else {
				int z=D[lc]+(D[x]-D[y])/2;
				int x2=getpar(x,D[x]-z-1);
				a=S[R[x2]]-S[L[x2]];
				b=0;
			}
			c=C.size()-a-b;
			
			
			if(max({a,b,c})<mi) {
				mi=max({a,b,c});
				LL=x;
				RR=y;
			}
			
		}
		
		j=ask(LL,RR);
		for(i=1;i<=N;i++) {
			if(j==LL) {
				if(ddist[LL][i]>=ddist[RR][i]) O[i]=0;
			}
			else if(j==RR) {
				if(ddist[LL][i]<=ddist[RR][i]) O[i]=0;
			}
			else {
				if(ddist[LL][i]!=ddist[RR][i]) O[i]=0;
			}
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
