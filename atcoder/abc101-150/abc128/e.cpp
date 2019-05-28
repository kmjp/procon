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

int N,Q;

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	SegTree_2(){val.resize(NV*2,1LL<<60);};
	
	V getval(int entry) {
		entry += NV;
		ll ret=val[entry];
		while(entry>1) entry>>=1, ret=min(ret,val[entry]);
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=min(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};

SegTree_2<ll,1<<20> st;
vector<ll> C;
ll S[202020],T[202020],X[202020],D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	C.push_back(-1LL<<60);
	C.push_back(1LL<<60);
	FOR(i,N) {
		cin>>S[i]>>T[i]>>X[i];
		C.push_back(S[i]-X[i]);
		C.push_back(T[i]-X[i]);
	}
	FOR(i,Q) {
		cin>>D[i];
		C.push_back(D[i]);
	}
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	FOR(i,N) {
		x=lower_bound(ALL(C),S[i]-X[i])-C.begin();
		y=lower_bound(ALL(C),T[i]-X[i])-C.begin();
		st.update(x,y,X[i]);
	}
	
	
	FOR(i,Q) {
		x=lower_bound(ALL(C),D[i])-C.begin();
		ll ret=st.getval(x);
		if(ret>=1LL<<50) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
