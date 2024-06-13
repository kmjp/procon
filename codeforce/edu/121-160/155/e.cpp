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
int P[101],D[101];
vector<int> C[101];
int S[101];
set<int> cand;
int V[2];

void go1() {
	int i,x;
	cout<<1<<endl;
	for(i=1;i<N;i++) cout<<1<<" ";
	cout<<endl;
	cin>>i>>x;
	assert(i==0&&x==1);
	cout<<1<<endl;
	cin>>x;
	assert(x==1);
	exit(0);
	
}

void go2() {
	int i,x;
	cout<<2<<endl;
	for(i=1;i<N;i++) cout<<(((D[i]%2)^S[i])+1)<<" ";
	cout<<endl;
	while(1) {
		cin>>i;
		if(i==1) exit(0);
		int A,B;
		cin>>A>>B;
		if(A==1) cout<<1<<endl;
		else cout<<2<<endl;
	}
	exit(0);
}

void dfs(int cur) {
	cand.insert(cur);
	if(C[cur].size()==1) {
		V[D[cur]%2]++;
	}
	FORR(c,C[cur]) dfs(c);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
		D[i]=D[P[i]]+1;
		C[P[i]].push_back(i);
	}
	
	//1色で行けるか？
	for(i=1;i<N;i++) if(P[i]!=0) break;
	if(i==N) {
		go1();
	}
	//2色で行けるか？
	int ok=1;
	FORR(c,C[0]) {
		cand.clear();
		V[0]=V[1]=0;
		dfs(c);
		if(V[0]&&V[1]) ok=0;
		if(V[1]) FORR(a,cand) S[a]=1;
	}
	
	if(ok) {
		go2();
	}
	
	cout<<3<<endl;
	for(i=1;i<N;i++) cout<<(D[i]%3+1)<<" ";
	cout<<endl;
	while(1) {
		cin>>i;
		if(i==1) exit(0);
		int A,B,C;
		cin>>A>>B>>C;
		if(A==0&&B==1) cout<<2<<endl;
		else if(B==0&&C==1) cout<<3<<endl;
		else if(C==0&&A==1) cout<<1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
