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
	V val[NV*2];
	V comp(V x,V y){
		V a={1LL<<60,1LL<<60,1LL<<60,1LL<<60};
		
		int L0,L1,R0,R1;
		FOR(L0,2) FOR(R0,2) FOR(L1,2) FOR(R1,2) {
			if(R0==0&&L1==0) continue;
			a[L0+R1*2]=min(a[L0+R1*2],x[L0+R0*2]+y[L1+R1*2]);
		}
		return a;
	};
	
	void update(int entry, ll v) {
		entry += NV;
		val[entry][0]=0;
		val[entry][1]=v;
		val[entry][2]=v;
		val[entry][3]=v;
		
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,4>,1<<20> st;
int N,Q;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i];
		if(i!=0&&i!=N-2) st.update(i,A[i]);
	}
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--;
		A[x]=y;
		if(x!=0&&x!=N-2) st.update(x,A[x]);
		ll a=min({st.val[1][0],st.val[1][1],st.val[1][2],st.val[1][3]});
		if(N==2) {
			a=A[0];
		}
		else {
			a+=A[0]+A[N-2];
		}
		cout<<a*2<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
