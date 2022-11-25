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

int N,L,R;
int dp[2020];
pair<int,int> P[2020][5020];
int mask[5050];
int S[2020];

void go(int L,int R) {
	if(L==0&&R==0) {
		exit(0);
	}
	if(L==-1&&R==-1) {
		assert(0);
	}
	int i;
	for(i=L;i<=L+R-1;i++) S[i]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(P);
	cin>>N>>L>>R;
	
	for(i=1;i<=N;i++) {
		ZERO(mask);
		FOR(x,i) {
			for(y=L;y<=R&&x+y<=i;y++) {
				j=dp[x]^dp[i-(x+y)];
				P[i][j]={x,y};
				mask[j]=1;
			}
		}
		while(mask[dp[i]]) dp[i]++;
	}
	
	for(i=1;i<=N;i++) S[i]=1;
	if(dp[N]==0) {
		cout<<"Second"<<endl;
		cin>>x>>y;
		go(x,y);
	}
	else {
		cout<<"First"<<endl;
	}
	
	while(1) {
		int nim=0;
		int cur=0;
		int L=-1;
		int R=-1;
		FOR(i,N+2) {
			if(S[i]==0) {
				nim^=dp[cur];
				cur=0;
			}
			else {
				cur++;
			}
		}
		FOR(i,N+2) {
			if(S[i]==0) {
				if((nim^dp[cur])<dp[cur]) {
					auto p=P[cur][nim^dp[cur]];
					L=i-cur+p.first;
					R=p.second;
				}
				cur=0;
			}
			else {
				cur++;
			}
		}
		
		go(L,R);
		cout<<L<<" "<<R<<endl;
		cin>>x>>y;
		go(x,y);
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
