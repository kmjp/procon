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

int N,M;
int X[202020],Y[202020],Z[202020];
int ret[202020];

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
};
UF<402020> uf[31],uf2;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		FOR(j,30) {
			if(k&(1<<j)) {
				uf[j](x*2,y*2+1);
				uf[j](x*2+1,y*2);
			}
			else {
				uf[j](x*2,y*2);
				uf[j](x*2+1,y*2+1);
			}
			uf2(x,y);
		}
	}
	FOR(j,30) {
		int C[202020][2]={};
		FOR(i,N) {
			if(uf[j][i*2]==uf[j][i*2+1]) {
				cout<<-1<<endl;
				return;
			}
			x=uf2[i];
			if(uf[j][i*2]==uf[j][x*2]) C[x][0]++;
			else C[x][1]++;
		}
		FOR(i,N) {
			x=uf2[i];
			if((uf[j][i*2]==uf[j][x*2])==(C[x][0]<C[x][1])) ret[i]|=1<<j;
		}
	}
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
