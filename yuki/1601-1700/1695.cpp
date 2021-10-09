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

pair<vector<int>,pair<int,int> > manacher(string S) {
	int L=S.size(),i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k&&i+k<rad.size(); k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	i=max_element(rad.begin(),rad.end())-rad.begin();
	return make_pair(rad,make_pair((i-(rad[i]-1))/2,(i+(rad[i]-1))/2));
}

int N,M;
string S,T;
int dp[1505050];

vector<pair<int,int>> E[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	if(M%2) return _P("-1\n");
	FOR(i,M) if(T[i]!=T[M-1-i]) return _P("-1\n");
	M/=2;
	FOR(i,2*M+5) dp[i]=1<<30;
	for(i=2;i<=2*M;i++) E[i].push_back({i-1,0});
	deque<int> Q;
	
	FOR(i,min(M,N)) {
		if(S[i]!=T[i]) break;
		dp[i+1]=1;
		Q.push_back(i+1);
	}
	reverse(ALL(S));
	FOR(i,min(M,N)) {
		if(S[i]!=T[i]) break;
		dp[i+1]=1;
		Q.push_back(i+1);
	}
	
	auto P=manacher(T).first;
	
	for(i=1;i<M;i++) {
		x=P[i*2-1]/2;
		if(x) E[i].push_back({i+x,1});
	}
	
	while(Q.size()) {
		x=Q.front();
		Q.pop_front();
		FORR2(e,c,E[x]) {
			if(dp[e]>dp[x]+c) {
				dp[e]=dp[x]+c;
				if(c==0) Q.push_front(e);
				else Q.push_back(e);
			}
		}
	}
	if(dp[M]>1<<20) {
		cout<<-1<<endl;
	}
	else {
		cout<<dp[M]<<endl;
	}
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
