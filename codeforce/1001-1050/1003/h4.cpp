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
string S;
int Q;
const ll mo=998244353;

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,20> L[2],R[2];
ll p2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) {
			FOR(j,2) {
				L[j].add(i,mo-L[j](i));
				R[j].add(i,mo-R[j](i));
			}
			S[i]-='0';
		}
		ll ret=p2[N]-1;
		FOR(i,N) {
			L[S[i]].add(i,p2[i]);
			R[S[i]].add(i,p2[N-1-i]);
			(ret+=L[S[i]^1](i-1)*p2[N-1-i])%=mo;
		}
		
		cin>>Q;
		while(Q--) {
			cin>>x;
			x--;
			y=S[x]^1;
			//ˆø‚­
			(ret-=L[y](x-1)*p2[N-1-x])%=mo;
			(ret-=p2[x]*(R[y](N-1)-R[y](x)))%=mo;
			L[S[x]].add(x,mo-p2[x]);
			R[S[x]].add(x,mo-p2[N-1-x]);
			S[x]^=1;
			L[S[x]].add(x,p2[x]);
			R[S[x]].add(x,p2[N-1-x]);
			y^=1;
			(ret+=L[y](x-1)*p2[N-1-x])%=mo;
			(ret+=p2[x]*(R[y](N-1)-R[y](x)))%=mo;
			ret=(ret%mo+mo)%mo;
			cout<<ret<<" ";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
