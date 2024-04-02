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

template<class V,int MV> class Bellman_Ford {
public:
	int NV;
	V cost[MV];
	vector<pair<int,V> > E[MV];
	
	void add_edge(int from,int to,V cost){ E[from].push_back(make_pair(to,cost));}
	bool calc(int start,int NV) { // true:ok false:cycle
		int i,j,k;
		FOR(i,NV) cost[i]=(1LL<<60);
		cost[start]=0;
		FOR(i,NV) {
			bool up=false;
			FOR(j,NV) FOR(k,E[j].size()) {
				if(cost[E[j][k].first]>cost[j]+E[j][k].second) cost[E[j][k].first]=cost[j]+E[j][k].second, up=true;
			}
			if(!up) return true; //•Â˜H‚È‚µ
		}
		return false; //•Â˜H‚ ‚è
	}
};



Bellman_Ford<ll,2502> bf;
int N,M;
int A[2525];
vector<int> RE[2525];
int U[5050],V[5050],C[5050];
int ok[2525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	bf.add_edge(N,0,-A[0]);
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i];
		U[i]--,V[i]--;
		RE[V[i]].push_back(U[i]);
	}
	
	ok[N-1]=1;
	queue<int> Q;
	Q.push(N-1);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,RE[cur]) if(ok[e]==0) {
			ok[e]=1;
			Q.push(e);
		}
	}
	FOR(i,M) if(ok[U[i]]&&ok[V[i]]) bf.add_edge(U[i],V[i],C[i]-A[V[i]]);
	
	if(bf.calc(N,N+1)) {
		cout<<-bf.cost[N-1]<<endl;
	}
	else {
		cout<<"inf"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
