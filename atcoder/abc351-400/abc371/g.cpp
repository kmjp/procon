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
int P[202020];
int A[202020];
int B[202020];
int vis[202020];
int G[202020];

vector<int> D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=200000;i++) {
		for(j=i;j<=200000;j+=i) D[j].push_back(i);
	}
	
	MINUS(G);
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	FOR(i,N) cin>>A[i];
	set<int> S;
	FOR(i,N) if(vis[i]==0) {
		vector<int> V={i};
		vis[i]=1;
		while(P[V.back()]!=i) {
			V.push_back(P[V.back()]);
			vis[V.back()]=1;
		}
		
		set<int> cand;
		FOR(j,V.size()) cand.insert(j);
		
		int b=V.size();
		FORR(s,D[b]) if(G[s]!=-1) {
			set<int> cand2;
			FORR(a,cand) if(a%s==G[s]) cand2.insert(a);
			cand=cand2;
		}
		x=-1;
		FORR(c,cand) if(x==-1||A[V[c]]<A[V[x]]) x=c;
		FOR(j,V.size()) B[V[j]]=A[V[(j+x)%V.size()]];
		
		FORR(s,D[b]) G[s]=x%s;
	}
	
	FOR(i,N) cout<<B[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
