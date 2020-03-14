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
	}
};


int N;
ll H[101010],P[101010],C[101010];
ll SP[101010];
pair<int,int> L[101010],R[101010];
SegTree_3<ll,1<<19> stl,lc,str,rc;
ll LC[101010],RC[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	stl.update(1,N+1,-1LL<<60);
	str.update(1,N+1,-1LL<<60);
	FOR(i,N) {
		cin>>H[i+1]>>P[i+1]>>C[i+1];
		SP[i+1]=SP[i]+P[i];
		L[i]={H[i+1],i+1};
		R[i]={H[i+1],-(i+1)};
		stl.update(0,i+2,-C[i+1]);
		lc.update(0,i+2,-C[i+1]);
		str.update(i+1,N+2,-C[i+1]);
		rc.update(i+1,N+2,-C[i+1]);
	}
	sort(L,L+N);
	sort(R,R+N);
	
	FOR(i,N) {
		x=L[i].second;
		LC[x]=stl.getval(0,x)-lc.getval(x,x+1)+P[x];
		stl.update(0,x+1,C[x]);
		lc.update(0,x+1,C[x]);
		stl.update(x,x+1,LC[x]-stl.getval(x,x+1));
	}
	FOR(i,N) {
		x=-R[i].second;
		RC[x]=str.getval(x+1,N+2)-rc.getval(x,x+1)+P[x];
		str.update(x,N+2,C[x]);
		rc.update(x,N+2,C[x]);
		str.update(x,x+1,RC[x]-str.getval(x,x+1));
	}
	ll ret=-1LL<<60;
	FOR(i,N) ret=max(ret,LC[i+1]+RC[i+1]-P[i+1]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
