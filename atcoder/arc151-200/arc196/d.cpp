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

int N,M,Q;
int S[804040],T[804040];
int ok[404040];

int SS[2][804040],ST[2][804040];
ll hv[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
};
BIT<ll,20> bt[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>S[i]>>T[i];
		if(S[i]<T[i]) {
			S[i]=S[i]*2+1;
			T[i]=T[i]*2;
		}
		else {
			S[i]=S[i]*2;
			T[i]=T[i]*2+1;
		}
		
		hv[i]=((1LL*rand())<<30)+rand();
	}
	
	for(int L=0,R=0;L<M;L++) {
		while(R<M) {
			x=(S[R]<T[R]);
			if(SS[x][S[R]]) break;
			if(ST[x][T[R]]) break;
			if(ST[x^1][S[R]]) break;
			if(SS[x^1][T[R]]) break;
			if(bt[x](S[R])!=bt[x](T[R])) break;
			SS[x][S[R]]++;
			ST[x][T[R]]++;
			bt[x].add(S[R],hv[R]);
			bt[x].add(T[R],hv[R]);
			R++;
		}
		ok[L]=R;
		x=(S[L]<T[L]);
		
		SS[x][S[L]]--;
		ST[x][T[L]]--;
		bt[x].add(S[L],hv[L]);
		bt[x].add(T[L],hv[L]);
	}
	
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		if(ok[L-1]>=R) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
