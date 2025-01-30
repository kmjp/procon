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

int N,M,S,T;
set<int> E[202020];
int D[202020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	S--,T--;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	FOR(i,N) D[i][0]=D[i][1]=D[i][2]=1<<20;
	queue<int> Q;
	D[S][0]=D[T][1]=0;
	Q.push(S*2);
	Q.push(T*2+1);
	while(Q.size()) {
		int id=Q.front()%2;
		int cur=Q.front()/2;
		Q.pop();
		FORR(e,E[cur]) if(chmin(D[e][id],D[cur][id]+1)) Q.push(e*2+id);
	}
	int ret=1<<20;
	map<int,int> mp;
	int d=D[T][0];
	FOR(i,N) {
		if(D[i][0]+D[i][1]==d) {
			//ï°êîç≈íZåoòHÇ™Ç†ÇÈ
			mp[D[i][0]]++;
			if(mp[D[i][0]]>=2) ret=2*d;
			if(D[i][0]&&D[i][1]&&E[i].size()>2) ret=min(ret,2*d+2);
		}
		//Ç∑ÇÍà·Ç¢Ç™Ç≈Ç´ÇÈ
		if(E[i].size()>=3) ret=min(ret,(D[i][0]+D[i][1])*2+4);
		//ç≈íZ+1ÇÃåoòHÇ≈Ç∑ÇÍà·Ç¶ÇÈ
		if(D[i][0]+D[i][1]==d+1) ret=min(ret,d*2+1);
	}
	
	// ç≈íZåoòHà»äOÇ…SÅ®TÇÃåoòHÇ™Ç†ÇÈ
	D[S][2]=0;
	Q.push(S);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,E[cur]) {
			if(D[e][0]+D[e][1]==d&&D[cur][0]+D[cur][1]==d) continue;
			if(chmin(D[e][2],D[cur][2]+1)) Q.push(e);
		}
	}
	ret=min(ret,d+D[T][2]);
	
	if(ret==1<<20) ret=-1;
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
