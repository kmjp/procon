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

int N;
int P[202020],rev[202020];
int F[202020];

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
BIT<int,20> bit,S,T,U;
int ret[202020];
vector<int> ev[202020],query[202020];
int Q;
int X[202020],Y[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		rev[P[i]]=i;
		F[i]=bit(P[i]);
		bit.add(P[i],1);
		S.add(P[i],1);
		ev[F[i]].push_back(i);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		query[X[i]].push_back(i);
	}
	
	for(int k=1;k<=N;k++) {
		FORR(e,ev[k-1]) {
			S.add(P[e],-1);
			T.add(P[e],1);
			U.add(e,1);
		}
		FORR(i,query[k]) {
			if(S(Y[i])-S(Y[i]-1)) {
				ret[i]=rev[Y[i]]+1;
			}
			else {
				int n=T(N)-T(Y[i]-1);
				ret[i]=U.lower_bound(n+k)+1;
			}
		}
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
