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

static ll const def=1LL<<40;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma,key;
	SegTree_3(){
		int i;
		val.resize(NV*2,0);
		ma.resize(NV*2,0);
		key.resize(NV*2,0);
		FOR(i,NV) key[NV+i]=i;
	};
	
	pair<V,V> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {def,-1};
		if(x<=l && r<=y) return {ma[k],key[k]};
		auto a=min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first+=val[k];
		return a;
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
			if(ma[k*2]<ma[k*2+1]) {
				ma[k]=val[k]+ma[k*2];
				key[k]=key[k*2];
			}
			else {
				ma[k]=val[k]+ma[k*2+1];
				key[k]=key[k*2+1];
			}
		}
	}
};

SegTree_3<ll,1<<20> st;
vector<int> C;
int N;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		C.push_back(A[i]);
	}
	sort(ALL(C));
	FOR(i,N) st.update(i,i+1,C[i]);
	
	ll ret=0;
	FOR(i,N) {
		x=lower_bound(ALL(C),A[i])-C.begin();
		auto p=st.getval(x,N);
		ret+=p.first-A[i];
		st.update(0,p.second,1);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
