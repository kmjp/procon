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

ll mo=1000000007;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,12> bt[1515];

int N,K;
int A[2020];
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<int> Xs={0,1<<30};
	FOR(i,N) {
		cin>>A[i];
		Xs.push_back(A[i]);
	}
	sort(ALL(Xs));
	cin>>S;
	FOR(i,N) {
		x=lower_bound(ALL(Xs),A[i])-Xs.begin();
		bt[1].add(x,1);
		for(j=2;j<=K+1;j++) {
			if(S[j-2]=='<') {
				bt[j].add(x,bt[j-1](x-1));
			}
			else {
				bt[j].add(x,(mo+bt[j-1](N+2)-bt[j-1](x))%mo);
			}
		}
	}
	cout<<bt[K+1](N+2)<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
