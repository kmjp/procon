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
string S;
vector<pair<int,int>> E[26*26+50505];
int D[26*26][26*26+50505];
int V[50505+26*26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) c-='a';
	
	
	FOR(i,N-1) {
		V[i]=N+26*S[i]+S[i+1];
		E[i].push_back({V[i],1});
		E[V[i]].push_back({i,0});
		E[i].push_back({i+1,1});
		E[i+1].push_back({i,1});
	}
	
	FOR(x,26*26) {
		FOR(y,26*26+N) D[x][y]=1<<20;
		deque<int> Q;
		D[x][N+x]=0;
		Q.push_back(N+x);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop_front();
			FORR2(e,c,E[cur]) if(chmin(D[x][e],D[x][cur]+c)) {
				if(c==0) Q.push_front(e);
				else Q.push_back(e);
			}
		}
	}
	
	cin>>M;
	while(M--) {
		int F,T;
		cin>>F>>T;
		F--,T--;
		int ret=abs(T-F);
		FOR(i,26*26) ret=min(ret,D[i][F]+D[i][T]+1);
		cout<<ret<<endl;
		
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
