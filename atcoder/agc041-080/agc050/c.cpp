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
string S;
const ll mo=998244353;

ll C[1<<21][22];
int last=0;

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,22> bt[22];


void solve() {
	int i,j,k,l,r,x,y; string s;
	string T;
	
	cin>>S;
	ll pat=1;
	FORR(c,S) if(c=='?') pat=pat*2%mo;
	int NB=0;
	FORR(c,S) if(c=='B') NB++;
	if(NB>=21) {
		cout<<pat<<endl;
		return;
	}
	T="B"+string((1<<20)+1,'S')+S;
	N=T.size();
	
	FOR(i,22) {
		C[0][i]=1;
		bt[i].add(0,1);
	}
	for(i=1;i<N;i++) {
		if(T[i]=='B'||T[i]=='?') {
			for(j=1;j<=21;j++) {
				x=i-(1<<(j-1))-1;
				if(x>=last) {
					C[i][j-1]=(bt[j](x)-bt[j](last-1)+mo)%mo;
					bt[j-1].add(i,C[i][j-1]);
				}
			}
			if(T[i]=='B') last=i;
		}
	}
	ll ret=0;
	for(i=last;i<N;i++) (ret+=C[i][0])%=mo;
	
	cout<<(pat-ret+mo)%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
