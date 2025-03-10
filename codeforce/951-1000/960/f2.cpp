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

int T;
int N,Q;
ll A[202020];


template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=-1;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<ll,1<<20> stlen,sttim;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bit;

map<int,int> memo[202020],tim[202020];

int dfs(int t,int L,int R) {
	if(R-L<3) return -1;
	if(memo[L].count(R)==0) tim[L][R]=-1;
	if(sttim.getval(L,R).first<tim[L][R]) return memo[L][R];
	tim[L][R]=t;
	int x=stlen.getval(L,R).second;
	int ret;
	if(2*A[x]<bit(R-1)-bit(L-1)) {
		ret=R-L;
	}
	else {
		ret=max(dfs(t,L,x),dfs(t,x+1,R));
	}
	return memo[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			bit.add(i,-bit(i));
			memo[i].clear();
			tim[i].clear();
		}
		FOR(i,N) {
			cin>>A[i];
			stlen.update(i,A[i]);
			sttim.update(i,-1);
			bit.add(i,A[i]);
			
		}
		FOR(j,Q) {
			cin>>i>>x;
			x--;
			if(i==1) {
				cin>>y;
				ll ret=dfs(j,x,y);
				cout<<ret<<endl;
			}
			else {
				ll v;
				cin>>v;
				stlen.update(x,v);
				bit.add(x,v-A[x]);
				A[x]=v;
				sttim.update(x,j);
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
