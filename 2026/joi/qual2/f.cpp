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
int A[3553];
map<int,int> M;
int dp[3553][3553][12];

int hoge(vector<pair<int,int>> V) {
	queue<pair<int,int>> L,R;
	int Llen=0,Rlen=0;
	int lef=(N-3)/2;
	FORR2(a,b,V) {
		if(Llen<lef) {
			int len=min(lef-Llen,b);
			L.push({a,len});
			Llen+=len;
			a+=len;
			b-=len;
		}
		if(b) {
			R.push({a,b});
			Rlen+=b;
		}
	}
	assert(Llen==Rlen);
	int mi=1<<30;
	while(L.size()&&R.size()) {
		if(L.front().second==0) {
			L.pop();
			continue;
		}
		if(R.front().second==0) {
			R.pop();
			continue;
		}
		int d=0;
		while(1<<(d+1)<=min(L.front().second,R.front().second)) d++;
		mi=min(mi,dp[L.front().first][R.front().first][d]);
		L.front().first+=1<<d;
		R.front().first+=1<<d;
		L.front().second-=1<<d;
		R.front().second-=1<<d;
	}
	return mi;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		M[A[i]]=i;
	}
	
	if(N%2==0) {
		int mi=1<<30;
		FOR(i,N/2) mi=min(mi,A[i+N/2]-A[i]);
		cout<<mi<<endl;
		return;
	}
	
	FOR(y,N) FOR(x,y) dp[x][y][0]=A[y]-A[x];
	FOR(i,11) {
		FOR(y,N) FOR(x,y) {
			dp[x][y][i+1]=dp[x][y][i];
			if(y+(1<<i)<N) dp[x][y][i+1]=min(dp[x][y][i+1],dp[x+(1<<i)][y+(1<<i)][i]);
		}
	}
	
	int ret=-1;
	FOR(y,N) FOR(x,y) if(M.count(A[y]*2-A[x])) {
		int z=M[A[y]*2-A[x]];
		int tmp=A[y]-A[x];
		vector<pair<int,int>> V;
		V.push_back({0,x});
		V.push_back({x+1,y-x-1});
		V.push_back({y+1,z-y-1});
		V.push_back({z+1,N-(z+1)});
		ret=max(ret,min(tmp,hoge(V)));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
