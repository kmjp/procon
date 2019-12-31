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

template<class V,int NV> class RMQ {
public:
	vector<V> val, mi;
	RMQ(){ val.resize(NV*2,0); mi.resize(NV*2,0); };
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 1LL<<60;
		if(x<=l && r<=y) return mi[k];
		return min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)) + val[k];
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			mi[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mi[k]=min(mi[k*2],mi[k*2+1]) + val[k];
		}
	}
};

int N,A,B;
int a[101010];
int L[101010],R[101010],X[101010];
int S[101010],T[101010],K[101010];
ll ret[101010];

vector<int> ev_add[101010];
vector<int> ev_del[101010];
vector<int> ev_query[101010];

RMQ<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>a[i+1];
	cin>>A;
	FOR(i,A) {
		cin>>L[i]>>R[i]>>X[i];
		ev_add[L[i]].push_back(i);
		ev_del[R[i]].push_back(i);
	}
	cin>>B;
	FOR(i,B) {
		cin>>S[i]>>T[i]>>K[i];
		ev_query[K[i]].push_back(i);
	}
	
	for(i=1;i<=100000;i++) {
		FORR(r,ev_add[i]) {
			st.update(r+1,A+1,X[r]);
		}
		FORR(r,ev_query[i]) {
			ret[r]=a[K[r]] + st.getval(S[r]-1,T[r]+1);
		}
		FORR(r,ev_del[i]) st.update(r+1,A+1,-X[r]);
	}
	FOR(i,B) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
