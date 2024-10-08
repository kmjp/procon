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
int L[202020],R[202020];
vector<int> add[202020],del[202020];
int dp[11][202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1<<20);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st[11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		FOR(i,N+1) {
			add[i].clear(),del[i].clear();
			FOR(j,K+1) {
				dp[j][i]=-1<<20;
				st[j].update(i,-1<<20);
			}
		}
		FOR(i,K+1) {
			dp[i][0]=0;
			st[i].update(0,0);
		}
		
		FOR(i,M) {
			cin>>x>>y;
			add[x].push_back(x);
			del[y].push_back(x);
		}
		multiset<int> Ls;
		FOR(i,K+2) Ls.insert(0);
		for(i=1;i<=N;i++) {
			FORR(a,add[i]) Ls.insert(-a);
			vector<int> X;
			auto it=Ls.begin();
			FOR(j,K+1) X.push_back(-*it++);
			for(j=0;j<=K;j++) {
				int pre=i;
				dp[j][i]=-1LL<<20;
				for(x=0;x<=j;x++) {
					dp[j][i]=max(dp[j][i],st[j-x].getval(X[x],pre)+1);
					pre=X[x];
				}
				st[j].update(i,dp[j][i]);
			}
			FORR(a,del[i]) Ls.erase(Ls.find(-a));
		}
		
		int ma=0;
		FOR(i,K+1) ma=max(ma,st[i].getval(0,N+1));
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
