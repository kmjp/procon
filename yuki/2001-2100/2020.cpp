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

int nex;
int E[454545][26];
int N;
string S[202020],T[202020];
int pos[202020];
int Q;
int A[202020],B[202020];
char C[202020];

int id;
int L[454545],R[454545];

void dfs(int cur,int pos,string& S) {
	if(pos==S.size()) return;
	int x=S[pos]-'a';
	if(E[cur][x]==-1) {
		E[cur][x]=nex++;
	}
	dfs(E[cur][x],pos+1,S);
}

void dfs2(int cur) {
	L[cur]=id++;
	int i;
	FOR(i,26) if(E[cur][i]!=-1) dfs2(E[cur][i]);
	R[cur]=id++;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		T[i]=S[i];
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		B[i]--;
		if(A[i]==1) {
			cin>>C[i];
			T[B[i]]+=C[i];
		}
	}
	MINUS(E);
	nex=1;
	FOR(i,N) dfs(0,0,T[i]);
	dfs2(0);
	FOR(i,N) {
		FORR(c,S[i]) {
			x=c-'a';
			pos[i]=E[pos[i]][x];
			bt.add(L[pos[i]],1);
			bt.add(R[pos[i]],-1);
		}
	}
	FOR(i,Q) {
		y=B[i];
		if(A[i]==1) {
			x=C[i]-'a';
			S[y]+=C[y];
			pos[y]=E[pos[y]][x];
			bt.add(L[pos[y]],1);
			bt.add(R[pos[y]],-1);
		}
		else {
			cout<<bt(L[pos[y]])<<endl;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
