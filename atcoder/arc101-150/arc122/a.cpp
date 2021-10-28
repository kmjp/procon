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
ll A[202020];

ll pat[101010][2][2];

const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	pat[1][0][0]=1;
	pat[1][1][1]=1;
	for(i=2;i<=100001;i++) {
		FOR(x,2) {
			(pat[i][x][0]+=pat[i-1][x][0])%=mo;
			(pat[i][x][0]+=pat[i-1][x][1])%=mo;
			(pat[i][x][1]+=pat[i-1][x][0])%=mo;
		}
	}
	
	cin>>N;
	ll ret=0;
	
	if(N==1) {
		cin>>x;
		cout<<x<<endl;
		return;
	}
	
	FOR(i,N) {
		cin>>x;
		if(i==0) {
			ll a=pat[N-1][0][0]+pat[N-1][1][0]+pat[N-1][1][0]+pat[N-1][1][1];
			(ret+=a*x)%=mo;
		}
		else if(i==N-1) {
			ll p=pat[N-1][0][0]+pat[N-1][0][1];
			ll m=pat[N-1][1][0]+pat[N-1][1][1];
			(ret+=p*x)%=mo;
			(ret-=m*x)%=mo;
		}
		else {
			ll p=(pat[i][0][0]+pat[i][0][1])*(pat[N-1-i][0][0]+pat[N-1-i][0][1]+pat[N-1-i][1][0]+pat[N-1-i][1][1])%mo;
			ll m=(pat[i][1][0]+pat[i][1][1])*(pat[N-1-i][0][0]+pat[N-1-i][0][1])%mo;
			(ret+=p*x)%=mo;
			(ret-=m*x)%=mo;
		}
	}
	ret=(ret%mo+mo)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
