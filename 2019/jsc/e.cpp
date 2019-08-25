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

int N,H,W;

int R[101010],C[101010],A[101010];
int ok[201010];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H>>W;
	vector<vector<int>> V;
	FOR(i,N) {
		cin>>R[i]>>C[i]>>A[i];
		R[i]--;
		C[i]--;
		V.push_back({A[i],R[i],C[i]});
	}
	FOR(i,H) ok[i]=1;
	FOR(i,W) ok[H+i]=1;
	
	sort(ALL(V));
	reverse(ALL(V));
	ll ret=0;
	FORR(v,V) {
		int y=v[1];
		int x=v[2];
		
		if(ok[uf[y]]&&ok[uf[H+x]]) {
			if(uf[y]==uf[H+x]) {
				ok[uf[y]]=0;
			}
			else {
				uf(y,H+x);
			}
			ret+=v[0];
		}
		else if(ok[uf[y]]) {
			ok[uf[y]]=0;
			ret+=v[0];
		}
		else if(ok[uf[H+x]]) {
			ok[uf[H+x]]=0;
			ret+=v[0];
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
