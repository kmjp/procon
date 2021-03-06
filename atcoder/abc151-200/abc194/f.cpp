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

string N;
int K;

ll pat[202020][18];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	int mask=0;
	
	FOR(i,N.size()) {
		char c=N[i];
		if(c>='A'&&c<='F') y=10+c-'A';
		else y=(c-'0');
		
		//first
		if(i) pat[i+1][1]+=15;
		//less
		FOR(j,y) {
			if(i==0&&j==0) continue;
			x=__builtin_popcount(mask|(1<<j));
			pat[i+1][x]++;
		}
		//any
		FOR(x,17) {
			(pat[i+1][x]+=pat[i][x]*x)%=mo;
			(pat[i+1][x+1]+=pat[i][x]*(16-x))%=mo;
		}
		
		mask|=(1<<y);
	}
	
	ll ret=pat[N.size()][K];
	if(__builtin_popcount(mask)==K) ret++;
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
