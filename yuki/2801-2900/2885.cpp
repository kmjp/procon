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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1LL<<60);;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
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
SegTree_1<ll,1<<20> Fmi[3],Fma[3];

int N,Q;
ll A[202020],B[202020],D[202020];
ll Cmi[3][202020],Cma[3][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>D[i];
		Cmi[0][i]=B[i]-D[i];
		Cma[0][i]=B[i];
		Cmi[1][i]=A[i]+B[i]-2*D[i];
		Cma[1][i]=A[i]+B[i];
		Cmi[2][i]=A[i]-B[i];
		Cma[2][i]=A[i]-B[i]+2*D[i];
		
		FOR(j,3) {
			Fmi[j].update(i,-Cma[j][i]);
			Fma[j].update(i,Cmi[j][i]);
		}
	}
	
	cin>>Q;
	while(Q--) {
		int S,L,R;
		cin>>S>>L>>R;
		S--,L--;
		int ok=1;
		FOR(j,3) {
			ll mi=Fma[j].getval(L,R);
			ll ma=-Fmi[j].getval(L,R);
			if(ma<=Cmi[j][S]||mi>=Cma[j][S]) ok=0;
		}
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
