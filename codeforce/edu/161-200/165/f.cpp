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

int N,K;
int A[1010];

int dp[1010];

ll H[1010];
ll HS[1010];

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<int> dist(0, 1<<20);
int num[1010][1010];

map<int,set<int>> nex;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1000) {
		H[i]=dist(mt);
		H[i]=(H[i]<<20)|dist(mt);
		H[i]=(H[i]<<20)|dist(mt);
	}
	
	cin>>N>>K;
	int ret=0;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		if(i%2==1&&A[i]==A[i-1]) {
			ret++;
			i-=2;
			N-=2;
		}
	}
	
	
	set<int> S;
	int cur=0;
	while(S.size()<K&&cur<N) {
		if(S.count(A[cur])) {
			S.erase(A[cur]);
			ret++;
		}
		else {
			S.insert(A[cur]);
		}
		cur++;
		if(S.count(A[cur])) {
			S.erase(A[cur]);
			ret++;
		}
		else {
			S.insert(A[cur]);
		}
		cur++;
	}
	
	FOR(i,N) FOR(j,K) num[j][i+1]=num[j][i]+(A[i]==j);
	MINUS(dp);
	dp[cur]=ret;

	FOR(i,N) {
		HS[i+1]=HS[i]^H[A[i]];
		if(i+1>=cur&&(i+1)%2==0) nex[HS[i+1]].insert(i+1);
	}

	for(i=cur;i<N;i+=2) {
		nex[HS[i]].erase(i);
		int px=-1,py=-1;
		int sum=0;
		FOR(j,K) sum+=(num[j][N]+1-num[j][i])/2;
		
		FOR(y,K) FOR(x,y) {
			if(nex.count(HS[i]^H[x]^H[y])==0 || nex[HS[i]^H[x]^H[y]].empty()) {
				int tsum=sum-(num[x][N]+1-num[x][i])/2-(num[y][N]+1-num[y][i])/2;
				tsum+=(num[x][N]-num[x][i])/2+(num[y][N]-num[y][i])/2;
				dp[N]=max(dp[N],dp[i]+tsum);
			}
			else {
				j=*nex[HS[i]^H[x]^H[y]].begin();
				dp[j]=max(dp[j],dp[i]+(j-i)/2-1);
			}
		}
		if(K>=100) break;
		
	}
	
	
	int ma=0;
	FOR(i,N+1) ma=max(ma,dp[i]);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
