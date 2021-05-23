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

int N,M,L;
int X[65],Y[65],R[65];
double D[65][65];

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

double hoge(int a,int b) {
	if(b<N) {
		return hypot(X[a]-X[b],Y[a]-Y[b]);
	}
	else if(a<N) {
		return abs(hypot(X[a]-X[b],Y[a]-Y[b])-R[b]);
	}
	else {
		double D=hypot(X[a]-X[b],Y[a]-Y[b]);
		if(D>=R[a]+R[b]) return D-R[a]-R[b];
		if(D<=abs(R[a]-R[b])) return max(R[a],R[b])-(D+min(R[a],R[b]));
		return 0;
	}
}

double hoge2(int mask) {
	UF<60> uf;
	vector<pair<double,int>> E;
	int x,y;
	FOR(y,N) FOR(x,y) E.push_back({D[x][y],x*100+y});
	FOR(x,N) FOR(y,M) if(mask&(1<<y)) E.push_back({D[x][N+y],x*100+N+y});
	FOR(y,M) FOR(x,y) if(mask&(1<<y)) if(mask&(1<<x)) E.push_back({D[N+x][N+y],(N+x)*100+N+y});
	
	sort(ALL(E));
	
	double sum=0;
	FORR2(e,c,E) {
		x=c/100;
		y=c%100;
		if(uf[x]!=uf[y]) {
			sum+=e;
			uf(x,y);
		}
	}
	return sum;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,M) cin>>X[N+i]>>Y[N+i]>>R[N+i];
	FOR(y,N+M) FOR(x,y) D[x][y]=D[y][x]=hoge(x,y);
	double ret=1e9;
	int mask;
	FOR(mask,1<<M) ret=min(ret,hoge2(mask));
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
