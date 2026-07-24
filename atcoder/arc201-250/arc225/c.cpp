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

int T,N,M,K;
int A[202020],B[202020],C[202020];
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
UF<202020> uf1,uf2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		uf1.reinit(N);
		uf2.reinit(N);
		FOR(i,M) {
			cin>>A[i]>>B[i]>>C[i];
			A[i]--,B[i]--;
			if(C[i]==0) {
				uf1(A[i],B[i]);
			}
		}
		vector<int> cand;
		FOR(i,M) if(C[i]==1) {
			if(uf1[A[i]]!=uf1[B[i]]) {
				cand.push_back(i);
				uf1(A[i],B[i]);
				uf2(A[i],B[i]);
				K--;
			}
		}
		FOR(i,M) if(C[i]==1&&K>0) {
			if(uf2[A[i]]!=uf2[B[i]]) {
				cand.push_back(i);
				uf2(A[i],B[i]);
				K--;
			}
		}
		FOR(i,M) if(C[i]==0) {
			if(uf2[A[i]]!=uf2[B[i]]) {
				cand.push_back(i);
				uf2(A[i],B[i]);
			}
		}
		if(K||uf2.count(0)!=N) {
			cout<<"-1"<<endl;
		}
		else {
			sort(ALL(cand));
			FORR(a,cand) cout<<a+1<<" ";
			cout<<endl;
		}
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
