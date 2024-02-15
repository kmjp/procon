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
int H,W;
ll V;
vector<int> X[202020];
vector<pair<int,int>> RE[202020];
vector<pair<int,int>> CE[202020];
const ll mo=1000000007;
set<int> Rs,Cs;
ll RT[202020],RB[202020];
ll CT[202020],CB[202020];;
ll ret;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
};
UF<404040> uf;

void dfsR(int y,ll T,int b) {
	T=(T+V)%V;
	if(RT[y]!=-1) {
		if(RT[y]!=T) ret=0;
		return;
	}
	RB[y]=b;
	RT[y]=T;
	FORR2(e,c,RE[y]) dfsR(e,T+c,b);

}
void dfsC(int y,ll T,int b) {
	T=(T+V)%V;
	if(CT[y]!=-1) {
		if(CT[y]!=T) ret=0;
		return;
	}
	CB[y]=b;
	CT[y]=T;
	FORR2(e,c,CE[y]) dfsC(e,T+c,b);

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>V;
		FOR(y,H) RE[y].clear(), RT[y]=-1;
		FOR(x,W) CE[x].clear(), CT[x]=-1;
		uf.reinit(H+W);
		int vis=0;
		FOR(y,H) {
			X[y].resize(W);
			int pre=-1;
			FOR(x,W) {
				cin>>X[y][x];
				if(X[y][x]!=-1) {
					vis=1;
					uf(y,H+x);
					if(pre>=0) {
						CE[pre].push_back({x,X[y][x]-X[y][pre]});
						CE[x].push_back({pre,X[y][pre]-X[y][x]});
						uf(H+pre,H+x);
					}
					pre=x;
				}
			}
		}
		FOR(x,W) {
			int pre=-1;
			FOR(y,H) if(X[y][x]!=-1) {
				if(pre>=0) {
					RE[pre].push_back({y,X[y][x]-X[pre][x]});
					RE[y].push_back({pre,X[pre][x]-X[y][x]});
					uf(pre,y);
				}
				pre=y;
			}
		}
		
		ret=1;
		if(vis==0) {
			FOR(i,H+W-1) ret=ret*V%mo;
		}
		else {
			
			FOR(y,H) FOR(x,W) if(X[y][x]!=-1) {
				if(RT[y]==-1) dfsR(y,0,y);
				if(CT[x]==-1) dfsC(x,0,x);
				ll d=(X[y][x]+V-RT[y]+V-CT[x])%V;
				if(X[RB[y]][CB[x]]==-1) X[RB[y]][CB[x]]=d;
				if(X[RB[y]][CB[x]]!=d) {
					//cout<<y<<x<<" "<<RB[y]<<" "<<CB[x]<<" "<<X[y][x]<<" "<<d<<" "<<X[RB[y]][CB[x]]<<" "<<RT[y]<<CT[x]<<endl;
					ret=0;
				}
			}
			int num=0;
			FOR(i,H+W) if(uf[i]==i) num++;
			FOR(i,num-1) ret=ret*V%mo;
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
