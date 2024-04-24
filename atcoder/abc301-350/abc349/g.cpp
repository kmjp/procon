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

int N;
int A[202020];

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
UF<202020> uf;
int did[202020];
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	for(i=j=0;i<N;i+=k,j-=k) {
		for(;j<=A[i];j++) uf(i-j,i+j);
		for(k=1;i-k>=0&&k+A[i-k]+1<j;) {
			if(A[i-k]!=A[i+k]) {
				cout<<"No"<<endl;
				return;
			}
			k++;
		}
	}
	
	
	FOR(i,N) {
		x=i-A[i]-1;
		y=i+A[i]+1;
		if(x>=0&&y<N) {
			x=uf[x];
			y=uf[y];
			if(x==y) {
				cout<<"No"<<endl;
				return;
			}
			E[x].push_back(y);
			E[y].push_back(x);
		}
	}
	
	cout<<"Yes"<<endl;
	FOR(i,N) {
		x=uf[i];
		if(did[x]==0) {
			set<int> D;
			FORR(e,E[x]) D.insert(did[e]);
			did[x]=1;
			while(D.count(did[x])) did[x]++;
		}
		cout<<did[x]<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
