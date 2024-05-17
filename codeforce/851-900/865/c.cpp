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

int T,N,M;
vector<int> E[1515],RE[1515];
int D[1515];
int need[1515];
int O[1515],re[1515];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		int ok=0;
		FOR(i,N+1) {
			E[i].clear();
			RE[i].clear();
			D[i]=0;
			need[i]=0;
		}
		
		FOR(i,M) {
			cin>>x>>y;
			if(x==1) {
				i--;
				M--;
				continue;
			}
			E[x-1].push_back(y-1);
			RE[y-1].push_back(x-1);
			need[x-1]++;
		}
		D[0]=1;
		queue<int> Q;
		Q.push(0);
		int step=0;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			O[x]=step;
			re[step]=x;
			step++;
			FORR(e,RE[x]) if(D[e]==0) {
				D[e]=1;
				Q.push(e);
			}
		}
		FOR(i,N) if(D[i]==0) break;
		ZERO(need);
		if(i<N) {
			cout<<"INFINITE"<<endl;
			continue;
		}
		priority_queue<int> PQ;
		vector<int> V;
		FOR(i,N) PQ.push(i);
		while(PQ.size()) {
			x=PQ.top();
			PQ.pop();
			y=re[x];
			V.push_back(y+1);
			FORR(e,RE[y]) {
				need[e]--;
				if(need[e]==0) PQ.push(O[e]);
			}
			if(y) {
				need[y]=E[y].size();
			}
		}
		cout<<"FINITE"<<endl;
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
