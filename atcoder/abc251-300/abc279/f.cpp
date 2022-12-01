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

int D[603030]; //箱内の代表ボール
int B[603030]; //代表ボールの位置
int nex;
UF<606060> uf;
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N+Q;i++) {
		D[i]=B[i]=i;
	}
	nex=N+1;
	while(Q--) {
		int X,Y;
		cin>>i;
		if(i==1) {
			cin>>X>>Y;
			if(D[Y]==-1) continue;
			if(D[X]==-1) {
				swap(D[X],D[Y]);
				B[D[X]]=X;
				D[Y]=-1;
			}
			else {
				uf(D[X],D[Y]);
				B[D[X]]=B[D[Y]]=X;
				D[X]=uf[D[X]];
				D[Y]=-1;
			}
		}
		else if(i==2) {
			cin>>X;
			if(D[X]==-1) {
				D[X]=nex;
				B[nex]=X;
			}
			else {
				uf(D[X],nex);
				B[D[X]]=B[nex]=X;
				D[X]=uf[nex];
			}
			nex++;
		}
		else {
			cin>>X;
			cout<<B[uf[X]]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
