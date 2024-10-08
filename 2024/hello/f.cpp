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

int N,Q;
ll A[505050],B[505050],C[505050];


template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		ll x=min(l[2],r[1]);
		l[2]-=x;
		r[1]-=x;
		ll a=l[0]+r[0]+x;
		ll b=l[1]+min(r[1],l[3]);
		ll c=r[2]+min(l[2],r[3]);
		ll d=min(r[3]-min(l[2],r[3]),l[3]-min(r[1],l[3]));
		
		return {a,b,c,d};
	};
	
	SegTree_1(){val=vector<V>(NV*2,{0,0,0,0});};
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) {
			entry>>=1;
			val[entry]=comp(val[entry*2],val[entry*2+1]);
		}
	}
};
SegTree_1<array<ll,4>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ll S=0;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N) cin>>B[i];
	FOR(i,N-1) cin>>C[i];
	C[N-1]=1LL<<60;
	FOR(i,N) {
		if(A[i]<B[i]) st.update(i,{min(A[i],B[i]),B[i]-A[i],0LL,C[i]});
		else st.update(i,{min(A[i],B[i]),0LL,min(A[i]-B[i],C[i]),C[i]-min(A[i]-B[i],C[i])});
	}
	
	while(Q--) {
		int P,X,Y;
		ll Z;
		cin>>P>>X>>Y>>Z;
		P--;
		A[P]=X;
		B[P]=Y;
		C[P]=Z;
		if(P==N-1) C[P]=1LL<<60;
		i=P;
		if(A[i]<B[i]) st.update(i,{min(A[i],B[i]),B[i]-A[i],0LL,C[i]});
		else st.update(i,{min(A[i],B[i]),0LL,min(A[i]-B[i],C[i]),C[i]-min(A[i]-B[i],C[i])});
		cout<<st.val[1][0]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
