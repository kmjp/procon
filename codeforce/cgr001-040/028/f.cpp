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
int N;
ll A[202020],B[202020];
const int DI=61;
int id;
ll ret[502020][61];

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=1LL<<60;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
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
SegTree_Pair<ll,1<<20> st;

int dfs(int L,int R) {
	int cid=id++;
	int i;
	if(L==R) {
		FOR(i,DI) ret[cid][i]=1;
		return cid;
	}
	auto p=st.getval(L,R);
	int m=p.second;
	
	int a=dfs(L,m);
	int b=dfs(m+1,R);
	FOR(i,DI) {
		ret[a][i]=max(ret[a][i],A[m]);
		ret[b][i]=max(ret[b][i],A[m]);
	}
	int x=0,y=0;
	FOR(i,DI) {
		ret[cid][i]=max(ret[a][x],ret[b][y]);
		if(i==DI-1) break;
		if(max(ret[a][x+1],ret[b][y])<max(ret[a][x],ret[b][y+1])) x++;
		else y++;
	}
	FOR(i,DI-1) {
		ret[cid][i+1]=min(ret[cid][i+1],(ret[cid][i]+B[m]-1)/B[m]);
	}
	
	return cid;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			//A[i]=rand();
		}
		FOR(i,N) {
			cin>>B[i];
			//B[i]=2+i;
			st.update(i,B[i]);
		}
		id=0;
		auto V=dfs(0,N);
		FOR(x,DI) if(ret[V][x]==1) {
			cout<<x<<endl;
			break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
