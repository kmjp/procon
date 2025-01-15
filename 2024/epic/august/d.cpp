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
int N,Q;
int P[301010],re[301010];
set<int> C[301010];
int S[301010];
int A[301010];

int ok(int v) {
	if(v==0) return 0;
	if(C[v].empty()) return 1;
	if(re[v]<*C[v].begin()&&*C[v].rbegin()+S[P[*C[v].rbegin()]]==re[v]+S[v]) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N+1) {
			C[i].clear();
			S[i]=1;
		}
		for(i=2;i<=N;i++) {
			cin>>A[i];
		}
		for(i=N;i>1;i--) S[A[i]]+=S[i];
		for(i=1;i<=N;i++) {
			cin>>P[i];
			re[P[i]]=i;
			C[A[P[i]]].insert(i);
		}
		
		int num=0;
		FOR(i,N+1) num+=ok(i);
		
		
		while(Q--) {
			cin>>i>>j;
			int a=P[i],b=P[j];
			set<int> cand={a,b,A[a],A[b]};
			
			FORR(c,cand) num-=ok(c);
			C[A[a]].erase(i);
			C[A[b]].erase(j);
			swap(P[i],P[j]);
			swap(re[a],re[b]);
			C[A[a]].insert(j);
			C[A[b]].insert(i);
			FORR(c,cand) num+=ok(c);
			if(num==N) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
