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

int N,K,Q;
int L[202020],R[202020],C[202020];
ll H[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,20> bit;

vector<int> add[202020];
vector<int> del[202020];
vector<int> ev[202020];

int I[202020];
ll X[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,K) {
		cin>>L[i]>>R[i]>>C[i]>>H[i];
		add[L[i]].push_back(i);
		del[R[i]].push_back(i);
	}
	FOR(i,Q) {
		cin>>I[i]>>X[i];
		ev[I[i]].push_back(i);
	}
	FOR(i,201000) {
		FORR(a,add[i]) bit.add(a,H[a]);
		FORR(e,ev[i]) {
			if(bit(1<<19)<X[e]) {
				ret[e]=-1;
			}
			else {
				x=bit.lower_bound(X[e]);
				ret[e]=C[x];
			}
		}
		
		FORR(a,del[i]) bit.add(a,-H[a]);
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
