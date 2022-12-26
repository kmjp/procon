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

int H,W;
int SR,SC,GR,GC;
string S[2020];

int D[3][2020][2020];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV]; V pot[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e); fill(pot, pot+NV, 0);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost+pot[cur]-pot[e.to]) {
						dist[e.to]=d+e.cost+pot[cur]-pot[e.to];
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			FOR(i,NV) pot[i]+=dist[i];
			flow -= lc;
			res += lc*pot[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<1333*1333,int> mcf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SR>>SC>>GR>>GC;
	SR--,SC--,GR--,GC--;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) D[0][y][x]=D[1][y][x]=D[2][y][x]=1<<25;
	D[0][SR][SC]=D[1][GR][GC]=0;
	queue<int> Q;
	Q.push(SR*10000+SC);
	Q.push(100000000+GR*10000+GC);
	int dd[4]={1,0,-1,0};
	while(Q.size()) {
		int id=Q.front()/100000000;
		int cy=Q.front()/10000%10000;
		int cx=Q.front()%10000;
		Q.pop();
		FOR(i,4) {
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(chmin(D[id][ty][tx],D[id][cy][cx]+1)) Q.push(id*100000000+ty*10000+tx);
		}
	}
	int d=D[0][GR][GC];
	int ma=1<<25;
	map<int,int> M;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		
		int num=0;
		FOR(i,4) {
			int ty=y+dd[i];
			int tx=x+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='.') num++;
		}
		if(D[0][y][x]+D[1][y][x]==d) {
			M[D[0][y][x]]++;
			if(M[D[0][y][x]]==2) ma=min(ma,d*2);
			if(num>=3&&D[0][y][x]&&D[1][y][x]) ma=min(ma,(D[0][y][x]+D[1][y][x]+1)*2);
		}
		if(num>=3) ma=min(ma,(D[0][y][x]+D[1][y][x]+2)*2);
	}
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if(x&&S[y][x-1]=='.') {
			mcf.add_edge((y*1333+x),(y*1333+x-1),1,1);
			mcf.add_edge((y*1333+x-1),(y*1333+x),1,1);
		}
		if(y&&S[y-1][x]=='.') {
			mcf.add_edge((y*1333+x),((y-1)*1333+x),1,1);
			mcf.add_edge(((y-1)*1333+x),(y*1333+x),1,1);
		}
	}
	x=mcf.mincost((SR*1333+SC),(GR*1333+GC),2);
	if(x>=0) ma=min(ma,x);
	
	
	if(ma>=1<<25) ma=-1;
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
