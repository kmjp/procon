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

int N,K;
vector<pair<int,int>> V;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
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
SegTree_Pair<int,1<<20> st;

int nex[20][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		V.push_back({x,y});
	}
	sort(ALL(V));
	FOR(i,N) {
		st.update(i,V[i].second);
	}
	FOR(i,N) {
		auto x=lower_bound(ALL(V),make_pair(V[i].second,0))-V.begin();
		if(x==N) nex[0][i]=N;
		else nex[0][i]=min(N,st.getval(x,N).second);
	}
	FOR(i,20) nex[i][N]=N;
	FOR(i,19) {
		FOR(j,N) nex[i+1][j]=nex[i][nex[i][j]];
	}
	int mi=1<<30;
	FOR(i,N) {
		int cur=i;
		int step=K-1;
		FOR(j,19) {
			if(step&(1<<j)) cur=nex[j][cur];
		}
		
		if(cur!=N) {
			mi=min(mi,V[cur].second-V[i].first);
		}
	}
	
	if(mi==(1<<30)) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
