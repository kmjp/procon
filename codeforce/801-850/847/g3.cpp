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
int N,M;
int P,B;
int IT[202020],IB[202020][3];
vector<int> E[202020];
int D[202020];
int one[202020],two[202020],reach[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			IT[i]=0;
			E[i].clear();
			FOR(j,3) IB[i][j]=0;
			D[i]=1<<20;
		}
		cin>>P>>B;
		FOR(i,P) {
			cin>>x;
			IT[x-1]=1;
		}
		FOR(i,B) {
			cin>>x;
			IB[x-1][0]=1;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		FOR(i,2) {
			FOR(j,N) if(IB[j][i]) {
				FORR(e,E[j]) IB[e][i+1]=1;
			}
		}
		D[0]=0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(IB[e][0]==1&&D[e]>D[cur]+1) {
				D[e]=D[cur]+1;
				Q.push(e);
			}
		}
		
		int C[3]={};
		int ok=IT[0]==1;
		FOR(i,N) if(IT[i]) {
			one[i]=two[i]=0;
			reach[i]=1<<20;
			FORR(e,E[i]) {
				if(e==0) ok=1;
				if(IB[e][0]) {
					one[i]=1;
					if(IB[e][1]) two[i]=1;
					reach[i]=min(reach[i],D[e]);
				}
			}
			if(one[i]) C[0]++;
			if(two[i]) C[1]++;
		}
		FOR(i,N) if(IT[i]) {
			if(one[i]) C[0]--;
			if(two[i]) C[1]--;
			
			if(C[0]>=reach[i]) ok=1;
			if(reach[i]<=N&&C[1]) ok=1;
			
			if(one[i]) C[0]++;
			if(two[i]) C[1]++;
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
