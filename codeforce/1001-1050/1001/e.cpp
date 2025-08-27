#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N;
int W[404040];
vector<int> E[404040];

int P[21][400005],D[400005];
int L[402020],R[402020],re[402020];
int id;
vector<int> Vs[404040];


void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
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
int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			Vs[i].clear();
			bt.add(i,-bt(i));
			E[i].clear();
		}
		FOR(i,N) {
			cin>>W[i];
			W[i]--;
			Vs[W[i]].push_back(i);
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=0;
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		
		vector<int> ret;
		set<int> did;
		int num=0;
		for(int w=N-1;w>=0;w--) {
			if(did.size()) {
				FORR(v,Vs[w]) if(bt(R[v]-1)-bt(L[v]-1)==num) {
					//‚Ù‚©‚É‘I‘ğ‰Â”\‚ÈêŠ‚ğ1ŒÂˆÈãc‚·
					
					if(*did.begin()<L[v]||R[v]<=*did.rbegin()) ret.push_back(v);
				}
				FORR(v,Vs[w]) if(*did.begin()<L[v]||R[v]<=*did.rbegin()) {
					num++;
					int TL=*did.begin(),TR=*did.rbegin();
					if(TL>=L[v]&&TL<R[v]) TL=*did.lower_bound(R[v]);
					if(TR>=L[v]&&TR<R[v]) TR=*prev(did.lower_bound(L[v]));
					int lc=lca(re[TL],re[TR]);
					bt.add(L[v],1);
					bt.add(L[lc],1);
					bt.add(L[lca(v,lc)],-1);
				}
			}
			FORR(v,Vs[w]) did.insert(L[v]);
		}
		
		sort(ALL(ret));
		cout<<ret.size();
		FORR(r,ret) cout<<" "<<r+1;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
