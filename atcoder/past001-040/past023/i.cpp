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
ll Y;
string S[18];
ll X[18];
int M[18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Y;
	FOR(i,N) {
		cin>>S[i]>>X[i];
		FORR(c,S[i]) M[i]|=1<<(c-'a');
	}
	int mask;
	int ma=0;
	FOR(mask,1<<N) {
		ll sum=0;
		int m=0;
		FOR(i,N) if(mask&(1<<i)) {
			sum+=X[i];
			m|=M[i];
		}
		if(sum<=Y) ma=max(ma,__builtin_popcount(m));
	}
	cout<<ma<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
