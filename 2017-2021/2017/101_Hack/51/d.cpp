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

ll XX,YY,ZZ;
ll P,Q;
ll a[101010],b[101010],A[101010],B[101010];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-202020;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_ma<int,1<<17> L,T,R,D;

int ok(int d) {
	
	for(int i=0;i+d<=XX;i++) {
		int LL=L.getval(i,i+d);
		int RR=-R.getval(i,i+d);
		int TT=T.getval(i,i+d);
		int DD=-D.getval(i,i+d);
		
		if(RR-LL<d) continue;
		if(DD-TT<d) continue;
		return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>XX>>YY>>ZZ;
	cin>>P>>Q;
	ll V=0;
	FOR(i,XX) {
		cin>>a[i]>>b[i]>>A[i]>>B[i];
		A[i]++,B[i]++;
		V+=(A[i]-a[i])*(B[i]-b[i]);
		
		L.update(i,a[i]);
		R.update(i,-A[i]);
		T.update(i,b[i]);
		D.update(i,-B[i]);
	}
	
	int mav=1;
	for(i=20;i>=0;i--) if(ok(mav+(1<<i))) mav+=1<<i;
	
	ll ret=0;
	for(i=1;i<=mav;i++) ret=max(ret,i*P+(V-(ll)i*i*i+1)*Q);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
