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
const ll mo=998244353;

int num[1010];
ll pat[100][100][31];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	N--;
	for(i=1;i<=M;i++) num[M/i]++;
	vector<int> C;
	ll from[100]={};
	for(i=1;i<=M;i++) if(num[i]) {
		from[C.size()]=num[i];
		C.push_back(i);
	}
	
	FOR(x,C.size()) FOR(y,C.size()) if(abs(C[x]-C[y])<=K) pat[x][y][0]=num[C[y]];
	
	FOR(i,30) {
		if(N&(1<<i)) {
			ll to[100]={};
			FOR(x,C.size()) FOR(y,C.size()) (to[y]+=from[x]*pat[x][y][i])%=mo;
			swap(from,to);
			
		}
		FOR(x,C.size()) FOR(y,C.size()) FOR(k,C.size()) (pat[x][k][i+1]+=pat[x][y][i]*pat[y][k][i])%=mo;
	}
	ll ret=0;
	FOR(i,C.size()) ret+=from[i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
