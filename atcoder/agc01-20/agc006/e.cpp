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

int N;
map<ll,int> M[2];
ll A[3][101010];
vector<ll> V[2];
int RP[2];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

ll array_inv(vector<ll> V) {
	static BIT<int,18> bt;
	ZERO(bt.bit);
	int x=0,i;
	map<ll,int> M;
	vector<int> V2;
	
	M[-1LL<<60]=0;
	FORR(r,V) M[r]=0;
	FORR(r,M) r.second=x++;
	ll ret=0;
	for(i=V.size()-1;i>=0;i--) {
		ret += bt(M[V[i]]);
		bt.add(M[V[i]],1);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[0][i];
	FOR(i,N) cin>>A[1][i];
	FOR(i,N) cin>>A[2][i];
	
	FOR(i,N) {
		ll P=1+i*3, Q=P+1, R=Q+1;
		if(i%4>=2) swap(P,R);
		M[i%2][(P<<40)+(Q<<20)+R]=i/2;
	}
	FOR(i,N) {
		if(i%4>=2) swap(A[0][i],A[2][i]);
		ll k1=(A[0][i]<<40)+(A[1][i]<<20)+A[2][i];
		ll k2=(A[2][i]<<40)+(A[1][i]<<20)+A[0][i];
		if(M[i%2].count(k1)) V[i%2].push_back(M[i%2][k1]);
		else if(M[i%2].count(k2)) V[i%2].push_back(M[i%2][k2]), RP[i%2]^=1;
		else return _P("No\n");
	}
	
	if(array_inv(V[0])%2!=RP[1] || array_inv(V[1])%2!=RP[0]) return _P("No\n");
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
