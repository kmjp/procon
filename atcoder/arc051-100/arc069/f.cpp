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


class SCC {
public:
	static const int MV = 1<<17;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind;  rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			revdfs(NUM[i],c);  c++;
		}
	}
};

int N;
int X[101010],Y[101010];
int id[101010][2];
int mi;
vector<pair<int,int>> E;

SCC sc;
void add(int c,int x,int y,int l=0,int r=1<<16,int k=1) { // x<=i<y
	if(x>=y) return;
	if(r<=x || y<=l) return;
	if(x<=l && r<=y) {
		sc.add_edge(c,k);
	}
	else {
		add(c,x,y,l,(l+r)/2,k*2);
		add(c,x,y,(l+r)/2,r,k*2+1);
	}
}

int ok(int v) {
	int i,j;
	int A=1<<16, B=1<<15;
	sc.init(1<<17);
	v--;
	for(i=2;i<1<<16;i++) {
		sc.add_edge(i,i*2);
		sc.add_edge(i,i*2+1);
	}
	
	FOR(i,N) {
		sc.add_edge(A+id[i][0]+B,A+id[i][1]);
		sc.add_edge(A+id[i][1]+B,A+id[i][0]);
		
		int x=lower_bound(ALL(E),make_pair(X[i]-v,0))-E.begin();
		int y=lower_bound(ALL(E),make_pair(X[i]+v+1,0))-E.begin();
		add(A+id[i][0],x+B,id[i][0]+B);
		add(A+id[i][0],id[i][0]+1+B,y+B);
		x=lower_bound(ALL(E),make_pair(Y[i]-v,0))-E.begin();
		y=lower_bound(ALL(E),make_pair(Y[i]+v+1,0))-E.begin();
		add(A+id[i][1],x+B,id[i][1]+B);
		add(A+id[i][1],id[i][1]+1+B,y+B);
	}
	sc.scc();
	FOR(i,B) if(sc.GR[A+i]==sc.GR[A+i+B]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		E.push_back({X[i],i});
		E.push_back({Y[i],i+(1<<14)});
	}
	sort(ALL(E));
	FOR(i,N) {
		id[i][0]=lower_bound(ALL(E),make_pair(X[i],i))-E.begin();
		id[i][1]=lower_bound(ALL(E),make_pair(Y[i],i+(1<<14)))-E.begin();
	}
	
	
	int ret=0;
	for(i=29;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
