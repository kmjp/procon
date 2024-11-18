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

int H,W,Q;
vector<int> D[303030];
string S[303030];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};
UF<606060> uf;
vector<int> L[303030],R[303030];
vector<pair<int,int>> Ds[1303030];
vector<pair<int,int>> target[1303030];
vector<pair<int,int>> ev[1303030];
int ty,tx;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	queue<int> PQ;
	FOR(y,H) {
		D[y].resize(W,1<<20);
		L[y].resize(W,-1);
		R[y].resize(W,-1+(1<<19));
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='v') {
				D[y][x]=0;
				PQ.push(y*W+x);
			}
			if(S[y][x]=='#') {
				R[y][x]=-1;
			}

			if(S[y][x]=='#'&&ty==0) {
				ty=y,tx=x;
			}
		}
	}
	
	while(PQ.size()) {
		y=PQ.front()/W;
		x=PQ.front()%W;
		PQ.pop();
		int d[4]={0,1,0,-1};
		FOR(i,4) {
			int ty=y+d[i];
			int tx=x+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(D[ty][tx]==1<<20) {
				D[ty][tx]=D[y][x]+1;
				PQ.push(ty*W+tx);
			}
		}
	}
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='#') D[y][x]=-1;
		else Ds[D[y][x]].push_back({y,x});
	}
	
	FOR(i,19) {
		FOR(j,(1<<19)+1) ev[j].clear();
		FOR(y,H) FOR(x,W) if(S[y][x]!='#') ev[(L[y][x]+R[y][x])/2].push_back({y,x});
		
		uf.reinit(2*H*W);
		for(j=(1<<19);j>=0;j--) {
			FORR2(cy,cx,Ds[j]) {
				int d[4]={0,1,0,-1};
				FOR(k,4) {
					int sx=cx+d[k];
					int sy=cy+d[k^1];
					if(sx<0||sx>=W||sy<0||sy>=H) continue;
					if(D[sy][sx]<j) continue;
					int cross=(sx!=cx&&min(sx,cx)<tx&&max(sx,cx)==tx&&sy<ty);
					uf((cy*W+cx)*2+0,(sy*W+sx)*2+(0^cross));
					uf((cy*W+cx)*2+1,(sy*W+sx)*2+(1^cross));
				}
			}
			FORR2(cy,cx,ev[j]) {
				assert(2*j==(L[cy][cx]+R[cy][cx]));
				if(uf[(cy*W+cx)*2+0]==uf[(cy*W+cx)*2+1]) L[cy][cx]=j;
				else R[cy][cx]=j;
			}
		}
	}
	
	
	while(Q--) {
		int sy,sx;
		cin>>sy>>sx;
		cout<<L[sy-1][sx-1]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
