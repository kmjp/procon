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
ll K;
vector<int> E[2020];
ll dp[2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S>>T;
	S--,T--;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	if(K%2) {
		cout<<"Yes"<<endl;
		return;
	}
	if(E[S].empty()&&E[T].empty()) {
		cout<<"No"<<endl;
		return;
	}
	
	if(E[S].size()==1&&E[T].size()==1&&E[S][0]==T) {
		queue<int> Q;
		FOR(j,N) {
			FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
			dp[j][0]=0;
			Q.push(j*2);
			while(Q.size()) {
				int cur=Q.front()/2;
				int p=Q.front()%2;
				Q.pop();
				FORR(e,E[cur]) if(chmin(dp[e][p^1],dp[cur][p]+1)) Q.push(e*2+(p^1));
			}
			if(dp[j][1]+3<=K) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
