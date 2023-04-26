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
vector<int> E[2020];
int D[2020][2020];
int W[2020];
int P[2020],Q[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		FOR(j,N) D[i][j]=1<<20;
		D[i][i]=0;
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(D[i][e]==1<<20) {
				D[i][e]=D[i][cur]+1;
				Q.push(e);
			}
		}
	}
	int K;
	cin>>K;
	FOR(i,K) {
		cin>>P[i]>>Q[i];
		P[i]--;
		FOR(j,N) if(D[P[i]][j]<Q[i]) W[j]=1;
	}
	
	FOR(i,K) {
		int ok=0;
		FOR(j,N) if(D[P[i]][j]==Q[i]&&W[j]==0) ok=1;
		if(ok==0) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<(1-W[i]);
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
