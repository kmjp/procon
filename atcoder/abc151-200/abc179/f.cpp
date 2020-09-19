#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;

template<class V,int NV> class SegTree_2 {
public:
	V nolink;
	vector<V> val;
	SegTree_2(){val.resize(NV*2); clear(); nolink=1<<30;};
	void clear() { for(int i=0;i<NV*2;i++) val[i]=1<<20; }
	
	V getval(int k) {
		int e=k+NV;
		V ret=nolink;
		while(e>=1) ret=min(ret,val[e]), e/=2;
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

SegTree_2<int,1<<20> Xs,Ys;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	Xs.update(1,N,N);
	Ys.update(1,N,N);
	ll ret=1LL*(N-2)*(N-2);
	
	while(Q--) {
		cin>>i>>x;
		
		if(i==1) {
			y=Ys.getval(x);
			ret-=y-2;
			Xs.update(1,y,x);
		}
		else {
			y=x;
			x=Xs.getval(y);
			ret-=x-2;
			Ys.update(1,x,y);
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
