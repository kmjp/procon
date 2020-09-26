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

ll p1[2202020];
ll p10[2202020];
const ll mo=998244353;

template<class V,int NV> class SegTree_2 {
public:
	vector<V> sum,val;
	SegTree_2(){sum.resize(NV*2,0);val.resize(NV*2,0);};
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			sum[k]=v*p1[r-l]%mo;
			val[k]=v;
		}
		else if(l < y && x < r) {
			if(val[k]>=0) {
				val[2*k]=val[2*k+1]=val[k];
				sum[2*k]=sum[2*k+1]=val[k]*p1[(r-l)/2]%mo;
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[2*k]+sum[2*k+1]*p10[(r-l)/2])%mo;
		}
	}
};
SegTree_2<ll,1<<20> st;
int N,Q,L,R,D;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,2201010) {
		p1[i+1]=(p1[i]*10+1)%mo;
		p10[i+1]=(p10[i]*10)%mo;
	}
	
	cin>>N>>Q;
	st.update(0,N,1);
	FOR(i,Q) {
		cin>>L>>R>>D;
		R=N-R;
		L=N-L;
		st.update(R,L+1,D);
		cout<<st.sum[1]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
