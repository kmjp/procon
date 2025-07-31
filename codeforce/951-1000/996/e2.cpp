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

int T;
int N;
ll A[505050],B[505050];
int order[505050];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V m;
		m.first=l.first+r.first;
		m.second=max(l.second,l.first+r.second);
		return m;
	};
	
	SegTree_1(){val=vector<V>(NV*2,{0,-1LL<<60});};
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	};
};
SegTree_1<pair<ll,ll>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> X,Y,Z;
		ll SA=0,SB=0;
		FOR(i,N) {
			cin>>A[i]>>B[i];
			
			if(A[i]<B[i]) X.push_back({A[i],i});
			if(A[i]==B[i]) Y.push_back({i,i});
			if(A[i]>B[i]) Z.push_back({-B[i],i});
			SA+=A[i];
			SB+=B[i];
		}
		sort(ALL(X));
		sort(ALL(Y));
		sort(ALL(Z));
		FOR(i,X.size()) order[i]=X[i].second;
		FOR(i,Y.size()) order[i+X.size()]=Y[i].second;
		FOR(i,Z.size()) order[i+X.size()+Y.size()]=Z[i].second;
		A[N]=B[N]=0;
		
		FOR(i,N+1) {
			st.update(i,{A[order[i]]-B[order[i]],A[order[i]]});
		}
		ll ret=1LL<<60;
		FOR(i,N) {
			if(SA<=SB-B[order[i]]) {
				st.update(N,{A[order[i]]-B[order[i]],A[order[i]]});
				st.update(i,{0,0});
				ret=min(ret,st.val[1].second);
				st.update(i,{A[order[i]]-B[order[i]],A[order[i]]});
				st.update(N,{0,0});
			}
		}
		
		if(ret==1LL<<60) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret+SA<<endl;
		}
		
		FOR(i,N+1) {
			st.update(i,{0,-1LL<<60});
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
