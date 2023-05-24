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

int N,Q;
ll X;
vector<pair<int,int>> E[200005];
int P[21][200005],D[200005];
ll LD[202020];
int V[202020];
pair<int,int> DM[202020];

void dfs(int cur,int pre,int d,ll ld) {
	P[0][cur]=pre;
	D[cur]=d;
	LD[cur]=ld;
	int i;
	FOR(i,20) P[i+1][cur]=P[i][P[i][cur]];
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur,d+1,ld+c);
	
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

int getroot(int x) {
	return P[20][x];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Q;
	FOR(i,N) {
		V[i]=1;
		DM[i]={i,i};
		FOR(j,21) P[j][i]=i;
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			i=X;
			j=x;
			if(V[getroot(i)]<V[getroot(j)]) {
				swap(i,j);
			}
			V[getroot(i)]+=V[getroot(j)];
			int oj=getroot(j);
			dfs(j,i,D[i]+1,LD[i]+y);
			E[i].push_back({j,y});
			E[j].push_back({i,y});
			i=getroot(i);
			j=oj;
			vector<int> V={DM[i].first,DM[i].second,DM[j].first,DM[j].second};
			ll md=-1;
			FORR(v,V) FORR(w,V) if(v<w) {
				ll lc=lca(v,w);
				ll ret=LD[v]+LD[w]-2*LD[lc];
				if(ret>md) {
					md=ret;
					DM[i]={v,w};
				}
			}
			
			
		}
		else if(i==2) {
			cin>>x>>y;
			
			if(getroot(x)!=getroot(y)) {
				cout<<-1<<endl;
			}
			else {
				ll lc=lca(x,y);
				ll ret=LD[x]+LD[y]-2*LD[lc];
				cout<<ret<<endl;
				X=(X+ret)%N;
			}
			
			
			
		}
		else if(i==3) {
			cin>>x;
			i=getroot(x);
			x=DM[i].first;
			y=DM[i].second;
			ll lc=lca(x,y);
			ll ret=LD[x]+LD[y]-2*LD[lc];
			cout<<ret<<endl;
		}
		else {
			cin>>x;
			X=(X+x)%N;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
