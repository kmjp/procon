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
ll A[202020],B[202020],C[202020];
vector<ll> D[2][2];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,21> numA,numB,sumA,sumB;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		cin>>C[i];
		D[A[i]][B[i]].push_back(C[i]);
	}
	ll S[2][2]={};
	FOR(x,2) FOR(y,2) {
		sort(ALL(D[x][y]));
		FORR(d,D[x][y]) S[x][y]+=d;
	}
	
	ll SA=0,SB=0;
	FORR(a,D[1][0]) {
		SA+=sumA(1<<20);
		sumA.add(a,a);
		numA.add(a,1);
	}
	FORR(b,D[0][1]) {
		sumB.add(b,b);
		numB.add(b,1);
		SB+=sumB(1<<20);
	}
	ll ret=SA+SB+(numA(1<<20)+numB(1<<20))*S[1][1];
	reverse(ALL(D[1][1]));
	FORR(d,D[1][1]) {
		S[1][1]-=d;
		SA+=d*(numA(1<<20)-numA(d-1));
		SA+=sumA(d-1);
		numA.add(d,1);
		sumA.add(d,d);
		numB.add(d,1);
		sumB.add(d,d);
		SB+=d*(numB(1<<20)-numB(d-1));
		SB+=sumB(d-1);
		ret=min(ret,SA+SB+(numA(1<<20)+numB(1<<20))*S[1][1]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
