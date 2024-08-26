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

int T,N,A,B;
set<int> E[202020];
int D[2][202020];
int loop[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		A--,B--;
		FOR(i,N) {
			E[i].clear();
			D[0][i]=D[1][i]=1<<20;
			loop[i]=1;
		}
		FOR(i,N) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		D[0][A]=D[1][B]=0;
		queue<int> Q;
		Q.push(A);
		Q.push(N+B);
		while(Q.size()) {
			int id=Q.front()/N;
			int cur=Q.front()%N;
			Q.pop();
			FORR(e,E[cur]) if(D[id][e]>N) {
				D[id][e]=D[id][cur]+1;
				Q.push(id*N+e);
			}
		}
		FOR(i,N) if(E[i].size()==1) Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			loop[x]=0;
			FORR(e,E[x]) {
				E[e].erase(x);
				if(E[e].size()==1) Q.push(e);
			}
			E[x].clear();
		}
		int ok=0;
		FOR(i,N) if(E[i].size()&&D[0][i]>D[1][i]) {
			ok=1;
		}
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
