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

int N,Q;
string S;
int dp[1<<21];

int id(string S) {
	int ret=0;
	FORR(c,S) ret=ret*3+c-'A';
	return ret;
}
string st(int id) {
	string S;
	int i;
	FOR(i,N) {
		S+=(char)('A'+id%3);
		id/=3;
	}
	reverse(ALL(S));
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>Q;
	FOR(i,1<<21) dp[i]=101010;
	queue<int> PQ;
	FOR(x,N+1) FOR(y,N+1) FOR(r,N+1) if(x+y+r==N) {
		S=string(x,'A')+string(y,'B')+string(r,'C');
		i=id(S);
		dp[i]=0;
		PQ.push(i);
	}
	while(PQ.size()) {
		int cur=PQ.front();
		S=st(cur);
		PQ.pop();
		for(i=2;i<=N;i++) {
			reverse(S.begin(),S.begin()+i);
			x=id(S);
			if(dp[x]>dp[cur]+1) {
				dp[x]=dp[cur]+1;
				PQ.push(x);
			}
			reverse(S.begin(),S.begin()+i);
		}
	}
	
	
	while(Q--) {
		cin>>S;
		cout<<dp[id(S)]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
