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

int N,M[2];
int X[301010],Y[3010101];
vector<pair<int,pair<int,int>>> E[2];

int H[2][101010];

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
UF<303030> uf;

int L[301010],R[301010];
int ret[101010];
int Q;
vector<pair<int,int>> qs;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M[0]>>M[1]>>Q;
	FOR(i,M[0]) {
		cin>>X[N+i]>>Y[N+i];
	}
	FOR(i,N+M[0]-1) {
		cin>>j>>x>>y;
		if(j==1) {
			x--;
			y=y-1+N;
		}
		else {
			x=x-1+N;
			y=y-1+N;
		}
		
		E[0].push_back({max(Y[x],Y[y]),{x,y}});
	}
	FOR(i,M[1]) {
		cin>>X[N+M[0]+i]>>Y[N+M[0]+i];
		Y[N+M[0]+i]=-Y[N+M[0]+i];
	}
	FOR(i,N+M[1]-1) {
		cin>>j>>x>>y;
		if(j==1) {
			x--;
			y=y-1+N+M[0];
		}
		else {
			x=x-1+N+M[0];
			y=y-1+N+M[0];
		}
		E[1].push_back({max(Y[x],Y[y]),{x,y}});
	}
	FOR(i,2) {
		uf.reinit();
		FOR(j,N+M[0]+M[1]) L[j]=303030,R[j]=-1;
		FOR(j,N) L[j]=R[j]=j;
		sort(ALL(E[i]));
		FORR(e,E[i]) {
			x=uf[e.second.first];
			y=uf[e.second.second];
			if(R[x]<N&&R[y]<N) {
				H[i][min(R[x],R[y])]=e.first;
			}
			L[x]=L[y]=min(L[x],L[y]);
			R[x]=R[y]=max(R[x],R[y]);
			uf(x,y);
		}
	}
	multiset<int> S;
	multiset<pair<int,int>> T;
	S.insert(0);
	FOR(i,N-1) {
		S.insert(H[1][i]);
		T.insert({H[0][i],H[1][i]});
	}
	
	FOR(i,Q) {
		cin>>x;
		qs.push_back({x,i});
	}
	sort(ALL(qs));
	FORR(q,qs) {
		while(T.size()&&T.begin()->first<=q.first) {
			S.erase(S.find(T.begin()->second));
			T.erase(T.begin());
		}
		ret[q.second]=-*S.rbegin();
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
