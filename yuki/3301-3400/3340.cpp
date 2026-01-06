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
vector<int> E[202020],RE[202020];
int V0[202020],V1[202020],V2[202020];
int win[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(win);
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		RE[y-1].push_back(x-1);
		V2[x-1]++;
	}
	queue<int> Q;
	FOR(i,N) if(E[i].empty()) {
		win[i]=0;
		Q.push(i);
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,RE[cur]) if(win[e]==-1) {
			if(win[cur]==0) {
				win[e]=1;
				Q.push(e);
			}
			else {
				V1[e]++;
				V2[e]--;
				if(V2[e]==0&&V0[e]==0) {
					win[e]=0;
					Q.push(e);
				}
			}
		}
	}
	if(win[0]==1) cout<<"Alice"<<endl;
	if(win[0]==0) cout<<"Bob"<<endl;
	if(win[0]==-1) cout<<"Draw"<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
