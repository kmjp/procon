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

template<class V,int NV> class SegTree_3 {
public:
	vector<pair<V,int> > val;
	vector<pair<V,int> > ma;
	static V const def=-1LL<<60;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]=make_pair(0,i);
		FOR(i,NV) val[i]=make_pair(0,0);
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,0);
		if(x<=l && r<=y) return ma[k];
		auto a=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first += val[k].first;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first += val[k].first;
		}
	}
};
SegTree_3<ll,1<<20> st;
ll P[2];
ll N,W,H;
ll A,B,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>H;
	
	FOR(i,N) {
		cin>>A>>B>>X;
		st.update(X,X+A,B);
		while(1) {
			auto p=st.getval(X,X+A);
			if(p.first<H) break;
			P[i%2]++;
			st.update(p.second,p.second+1,-1LL<<61);
		}
	}
	
	if(P[0]>P[1]) cout<<"A"<<endl;
	if(P[0]<P[1]) cout<<"B"<<endl;
	if(P[0]==P[1]) cout<<"DRAW"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
