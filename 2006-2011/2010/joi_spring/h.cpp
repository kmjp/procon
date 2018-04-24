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

int N,M;
static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=0, ma[i+NV]={0,-i};
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {-1,0};
		if(x<=l && r<=y) return ma[k];
		auto a = max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first+=val[k];
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};
SegTree_3<int,1<<20> st;
map<int,vector<pair<int,int>>> W;
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y>>k;
		W[y].push_back({x,x+k});
	}
	
	FOR(i,N+2) X[i]=Y[i]=-1;
	
	int nex=2;
	FORR(w,W) {
		sort(ALL(w.second));
		FORR(v,w.second) {
			st.update(v.first,v.second,1);
			auto r=st.getval(v.first,v.second);
			if(r.first==nex) {
				X[nex]=-r.second;
				Y[nex]=w.first;
				nex++;
			}
		}
	}
	
	FOR(i,M) {
		cin>>j;
		cout<<X[j+1]<<" "<<Y[j+1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
