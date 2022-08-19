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


int N;
ll P1[26];
ll P2[26][26];
ll P3[26][26][26];
ll dp[26][26];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s>>x;
		FORR(c,s) c-='a';
		if(s.size()==1) {
			P1[s[0]]=x;
		}
		if(s.size()==2) {
			P2[s[0]][s[1]]=x;
		}
		if(s.size()==3) {
			P3[s[0]][s[1]][s[2]]=x;
		}
	}
	ll ma=-1LL<<60;
	//1•¶Žš
	FOR(i,26) ma=max(ma,P1[i]);
	//2•¶Žš
	priority_queue<pair<ll,int>> Q;
	FOR(y,26) FOR(x,26) {
		ma=max(ma,P2[y][x]+P1[y]+P1[x]);
		dp[y][x]=P2[y][x]+P1[y]+P1[x];
		Q.push({-dp[y][x],y*26+x});
	}
	//2•¶Žš
	FOR(i,26) ma=max(ma,P1[i]);
	
	int loop=1000000;
	while(Q.size()) {
		loop--;
		if(loop==0) {
			cout<<"Infinity"<<endl;
			return;
		}
		ll co=-Q.top().first;
		int c1=Q.top().second/26;
		int c2=Q.top().second%26;
		Q.pop();
		if(dp[c1][c2]!=co) continue;
		ma=max(ma,co);
		FOR(i,26) {
			ll sc=co+P3[c1][c2][i]+P2[c2][i]+P1[i];
			if(sc>dp[c2][i]) {
				dp[c2][i]=sc;
				Q.push({-sc,c2*26+i});
			}
		}
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
