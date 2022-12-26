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
int A[202020];
vector<int> As;

const ll mo=998244353;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> lef,ri,lefn,rin;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		As.push_back(A[i]);
	}
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(As),A[i])-As.begin();
		ri.add(A[i],As[A[i]]);
		rin.add(A[i],1);
	}
	ll ret=0;
	FOR(i,N) {
		ll ln=lefn(N)-lefn(A[i]);
		ll rn=rin(A[i]-1);
		ll ls=lef(N)-lef(A[i]);
		ll rs=ri(A[i]-1);
		(ret+=ls*rn+rs*ln+As[A[i]]*ln%mo*rn)%=mo;
		ri.add(A[i],mo-As[A[i]]);
		lef.add(A[i],As[A[i]]);
		rin.add(A[i],mo-1);
		lefn.add(A[i],1);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
