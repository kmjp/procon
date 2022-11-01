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

int N,Q;

typedef unsigned long long ull;
ull nim_prod(ull a,ull b,int len=64,bool usememo=true) {
	static ull memo[256][256];
	int i,j;
	if(usememo&&memo[1][1]==0) {
		FOR(i,256) FOR(j,256) memo[i][j]=nim_prod(i,j,8,0);
	}
	if(min(a,b)<=1) return a*b;
	if(usememo&&len<=8) return memo[a][b];
	len/=2;
	ull ah=a>>len,al=a&((1ULL<<len)-1);
	ull bh=b>>len,bl=b&((1ULL<<len)-1);
	ull h=nim_prod(ah,bh,len,usememo);
	ull l=nim_prod(al,bl,len,usememo);
	ull m=nim_prod(ah^al,bh^bl,len,usememo);
	return nim_prod(h,1ULL<<(len-1),len,usememo)^l^((l^m)<<len);
}

using VT = vector<ull>;
struct RollingHash_Nimber {
	vector<ull> p,h;
	ull b;VT s;int l;
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		srand(time(NULL));
		b = 1LL*rand()*rand()+rand();
		p={1};
		h={0};
		FOR(i,l) {
			p.push_back(nim_prod(p.back(),b));
			h.push_back(nim_prod(h.back(),b)^s[i]);
		}
	}
	ull hash(int l,int r) { // s[l..r]
		return nim_prod(h[l],p[r-l+1])^h[r+1];
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<ull> V(N);
	FOR(i,N) cin>>V[i];
	RollingHash_Nimber rh;
	rh.init(V);
	
	
	FOR(i,Q) {
		int A,B,C,D,E,F,L;
		cin>>A>>B>>C>>D>>E>>F;
		A--,C--,E--;
		L=min(B-A,F-E);
		ull a=rh.hash(A,A+L-1);
		ull b=rh.hash(C,C+L-1);
		ull c=rh.hash(E,E+L-1);
		if((a^b)==c) {
			if(B-A<F-E) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			continue;
		}
		else {
			int len=0;
			for(j=20;j>=0;j--) if(len+(1<<j)<L) {
				int tmp=len+(1<<j);
				ull a=rh.hash(A,A+tmp-1);
				ull b=rh.hash(C,C+tmp-1);
				ull c=rh.hash(E,E+tmp-1);
				if((a^b)==c) len=tmp;
			}
			if((V[A+len]^V[C+len])<V[E+len]) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
