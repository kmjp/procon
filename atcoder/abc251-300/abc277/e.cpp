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

int N,M,K;

vector<pair<int,int>> E[202020];
int S[202020];
int D[202020][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,K) {
		cin>>x;
		S[x-1]=1;
	}
	
	FOR(i,N) D[i][0]=D[i][1]=1<<30;
	D[0][1]=0;
	deque<int> Q;
	Q.push_back(1);
	while(Q.size()) {
		int cur=Q.front()/2;
		int id=Q.front()%2;
		Q.pop_front();
		if(cur==N-1) {
			cout<<D[cur][id]<<endl;
			return;
		}
		if(S[cur]&&D[cur][id^1]>D[cur][id]) {
			D[cur][id^1]=D[cur][id];
			Q.push_front(cur*2+(id^1));
		}
		
		FORR2(e,t,E[cur]) if(t==id&&D[e][id]>D[cur][id]+1) {
			D[e][id]=D[cur][id]+1;
			Q.push_back(e*2+id);
		}
	}
	cout<<-1<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
