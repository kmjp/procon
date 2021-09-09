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
string S;
int nex[26][202020];
ll ret[202020];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(i,26) nex[i][N]=nex[i][N+1]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,26) nex[j][i]=nex[j][i+1];
		nex[S[i]-'a'][i]=i;
	}
	
	for(i=N-1;i>=0;i--) {
		ret[i]=1;
		FOR(j,26) if(nex[j][i+2]!=N) ret[i]+=ret[nex[j][i+2]];
		ret[i]%=mo;
	}
	
	ll r=0;
	FOR(i,26) {
		if(nex[i][0]!=N) {
			r+=ret[nex[i][0]];
		}
	}
	cout<<r%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
