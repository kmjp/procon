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
ll A[202020],B[202020];
int X[202020],Y[202020];
ll Z[202020];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		V m={l.first+r.first,max(l.second,l.first+r.second)};
		return m;
	};
	
	SegTree_ma(){val=vector<V>(NV*2);};
	void update(int entry, ll a,ll b) {
		entry += NV;
		val[entry]={a,a+b};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<pair<ll,ll>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	vector<ll> Bs;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		B[i]=(B[i]*1000000)+i;
		Bs.push_back(B[i]);
	}
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>Z[i];
		Y[i]--;
		if(X[i]==2) {
			Z[i]=(Z[i]*1000000)+500000+i;
			Bs.push_back(Z[i]);
		}
	}
	sort(ALL(Bs));
	FOR(i,N) {
		B[i]=(lower_bound(ALL(Bs),B[i])-Bs.begin());
		st.update(N+Q-B[i],A[i],Bs[B[i]]/1000000);
	}
	FOR(i,Q) {
		if(X[i]==1) {
			x=Y[i];
			A[x]=Z[i];
			st.update(N+Q-B[x],A[x],Bs[B[x]]/1000000);
		}
		else {
			x=Y[i];
			st.update(N+Q-B[x],0,0);
			B[x]=lower_bound(ALL(Bs),Z[i])-Bs.begin();
			st.update(N+Q-B[x],A[x],Bs[B[x]]/1000000);
		}
		cout<<st.val[1].second<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
