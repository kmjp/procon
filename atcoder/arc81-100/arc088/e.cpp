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
string S,T[3];
int cnt[256];
int P[202020];
int cnt2[256];

int L[202020],R[202020];
vector<int> pos[256];
ll ret;

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
	
	cin>>S;
	N=S.size();
	FORR(c,S) cnt[c]++;
	
	int id=-1;
	FOR(i,256) if(cnt[i]%2==1) {
		if(id!=-1) return _P("-1\n");
		id=i;
	}
	
	FOR(i,N) {
		cnt2[S[i]]++;
		if(cnt2[S[i]]*2-1==cnt[S[i]]) P[i]=1;
		else if(cnt2[S[i]]<=cnt[S[i]]/2) P[i]=0;
		else P[i]=2;
		T[P[i]]+=S[i];
	}
	
	int toswap=0;
	for(i=N-1;i>=0;i--) {
		if(P[i]==2) ret+=toswap;
		if(P[i]<=1) toswap++;
	}
	toswap=0;
	FOR(i,N) {
		if(P[i]==1) toswap++;
		if(P[i]==0) ret+=toswap;
	}
	
	int A=0;
	FOR(i,N) if(P[i]==0) pos[S[i]].push_back(A++);
	FOR(i,256) reverse(ALL(pos[i]));
	vector<ll> V;
	
	for(i=N-1;i>=0;i--) if(P[i]==2) {
		V.push_back(pos[S[i]].back());
		pos[S[i]].pop_back();
	}
	
	ret+=array_inv(V);
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
