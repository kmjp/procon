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

int N,M;
int V[101010];
int P[101010];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> L,R,emp;
const ll mo=998244353;
ll fact[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=100000;i++) fact[i]=fact[i-1]*i%mo;
	
	MINUS(V);
	MINUS(P);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		V[y-1]=x-1;
		P[x-1]=y-1;
	}
	ll ret=0;
	ll add=0;
	FOR(i,N) {
		if(V[i]>=0) {
			ret+=R(N)-R(V[i]);
			R.add(V[i],1);
		}
		else {
			emp.add(i,1);
		}
	}
	ret+=1LL*(N-M)*(N-M-1)/2%mo*(mo+1)/2%mo;
	ret=ret*fact[N-M]%mo;
	x=0;
	FOR(i,N) {
		if(V[i]==-1) add+=x;
		else x++;
	}
	FOR(i,N) {
		if(P[i]==-1) {
			(ret+=add*fact[N-M-1])%=mo;
		}
		else {
			add=(add+emp(P[i])-(emp(N)-emp(P[i])))%mo;
		}
	}
	cout<<ret<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
