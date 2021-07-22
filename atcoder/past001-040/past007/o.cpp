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

static ll const def=-1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
		val[k]=max(val[k],def);
		ma[k]=max(ma[k],def);
	}
};

int N;
int A[202020],B[202020];
vector<int> Bs;
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	Bs.push_back(0);
	FOR(i,N) {
		cin>>A[i]>>B[i];
		Bs.push_back(B[i]);
	}
	sort(ALL(Bs));
	Bs.erase(unique(ALL(Bs)),Bs.end());
	int cur=0;
	FOR(i,N) {
		B[i]=lower_bound(ALL(Bs),B[i])-Bs.begin();
		st.update(0,cur+1,A[i]);
		while(cur+1<Bs.size()) {
			ll a=st.getval(0,cur+1);
			if(a<Bs[cur+1]) break;
			st.update(cur+1,cur+2,a-Bs[cur+1]);
			cur++;
		}
		st.update(0,B[i],-1LL<<60);
	}
	
	ll a=st.getval(0,cur+1);
	if(a<0) a=-1;
	cout<<a<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
