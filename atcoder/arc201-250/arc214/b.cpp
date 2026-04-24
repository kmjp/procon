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

int T,N,M;

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
UF<402020> uf;
int A[202020],B[202020],C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,M) {
			cin>>A[i]>>B[i]>>C[i];
			A[i]--,B[i]--;
		}
		int D[20][2]={};
		FOR(i,N+1) {
			FOR(j,20) D[j][(i>>j)%2]++;
		}
		int ret=0;
		int cand[20]={};
		FOR(i,20) {
			uf.reinit(2*N);
			FOR(j,M) {
				x=(C[j]>>i)%2;
				if(x==0) {
					uf(A[j]*2,B[j]*2);
					uf(A[j]*2+1,B[j]*2+1);
				}
				else {
					uf(A[j]*2,B[j]*2+1);
					uf(A[j]*2+1,B[j]*2);
				}
			}
			int a=0,b=0;
			FOR(j,N) {
				if(uf[0]==uf[j*2]) a++;
				else b++;
			}
			if(a+1==D[i][0]&&b==D[i][1]) cand[i]|=1;
			if(a==D[i][0]&&b+1==D[i][1]) cand[i]|=2;
			if(b+1==D[i][0]&&a==D[i][1]) cand[i]|=1;
			if(b==D[i][0]&&a+1==D[i][1]) cand[i]|=2;
		}
		vector<int> V;
		FOR(i,N+1) {
			int ok=1;
			FOR(j,20) if((cand[j]&(1<<((i>>j)%2)))==0) ok=0;
			if(ok) V.push_back(i);
		}
		if(V.size()>1) {
			cout<<-1<<endl;
		}
		else {
			cout<<V[0]<<endl;
		}
		
	}
			
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
