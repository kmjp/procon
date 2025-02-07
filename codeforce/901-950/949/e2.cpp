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

int T,N;
int L[505050],R[505050],A[505050];
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
UF<505050> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		uf.reinit(N);
		map<int,vector<int>> ev;
		FOR(i,N) {
			cin>>L[i]>>R[i]>>A[i];
			L[i]=L[i]*2;
			R[i]=R[i]*2+1;
			ev[L[i]].push_back(i);
			ev[R[i]].push_back(i);
		}
		vector<pair<ll,pair<int,int>>> Es;
		set<pair<ll,int>> S;
		FORR2(a,b,ev) {
			if(a%2==0) {
				FORR(v,b) S.insert({A[v],v});
				FORR(v,b) {
					auto it=S.lower_bound({A[v],v});
					if(it!=S.begin()) {
						auto p=*prev(it);
						Es.push_back({A[v]-p.first,{v,p.second}});
					}
					it++;
					if(it!=S.end()) {
						auto p=*it;
						Es.push_back({p.first-A[v],{v,p.second}});
					}
				}
			}
			else {
				FORR(v,b) {
					auto it=S.lower_bound({A[v],v});
					if(it!=S.begin()) {
						auto p=*prev(it);
						Es.push_back({A[v]-p.first,{v,p.second}});
					}
					it++;
					if(it!=S.end()) {
						auto p=*it;
						Es.push_back({p.first-A[v],{v,p.second}});
					}
				}
				FORR(v,b) S.erase({A[v],v});
			}
		}
		ll ret=0;
		sort(ALL(Es));
		FORR2(a,v,Es) {
			if(uf[v.first]!=uf[v.second]) {
				uf(v.first,v.second);
				ret+=a;
			}
		}
		if(uf.count(0)!=N) ret=-1;
		cout<<ret<<endl;
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
