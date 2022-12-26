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

int N,M;
int T[303030];
int A[303030],B[303030],C[303030];
vector<int> cand[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	queue<int> Q;
	FOR(i,N) {
		cin>>T[i];
		T[i]--;
		if(T[i]!=2) Q.push(i);
	}
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--,C[i]--;
		cand[A[i]].push_back(i);
		cand[B[i]].push_back(i);
		cand[C[i]].push_back(i);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,cand[x]) {
			if(T[A[e]]==0&&T[B[e]]==0) {
				if(T[C[e]]==1) return _P("-1\n");
				if(T[C[e]]==2) T[C[e]]=0, Q.push(C[e]);
			}
			if(T[A[e]]==0&&T[C[e]]==1) {
				if(T[B[e]]==0) return _P("-1\n");
				if(T[B[e]]==2) T[B[e]]=1, Q.push(B[e]);
			}
			if(T[B[e]]==0&&T[C[e]]==1) {
				if(T[A[e]]==0) return _P("-1\n");
				if(T[A[e]]==2) T[A[e]]=1, Q.push(A[e]);
			}
		}
	}
	FOR(i,N) {
		if(T[i]==2) T[i]=1;
		cout<<T[i]+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
