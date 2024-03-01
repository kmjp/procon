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

int N,A[303030],S,T;

vector<int> E[603030],V[303030];
int D[603030];
int from[603030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		V[A[i]].push_back(i);
	}
	cin>>S>>T;
	S--,T--;
	
	for(i=2;i<=300000;i++) {
		for(j=i;j<=300000;j+=i) {
			FORR(v,V[j]) {
				E[v].push_back(300000+i);
				E[300000+i].push_back(v);
			}
		}
	}
	FOR(i,601010) D[i]=1<<30;
	D[S]=0;
	queue<int> Q;
	Q.push(S);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,E[x]) if(D[e]==1<<30) {
			D[e]=D[x]+1;
			from[e]=x;
			Q.push(e);
		}
	}
	if(D[T]==1<<30) {
		cout<<-1<<endl;
	}
	else {
		vector<int> cand={T};
		x=T;
		while(x!=S) {
			x=from[x];
			if(x<=300000) cand.push_back(x);
		}
		reverse(ALL(cand));
		cout<<cand.size()<<endl;
		FORR(c,cand) cout<<c+1<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
