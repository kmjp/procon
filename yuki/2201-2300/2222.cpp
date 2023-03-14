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
double dp[202020];
double E[202020],GA[202020],GB[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	S+="#";
	GA[N]=1;
	
	for(i=N-2;i>=0;i--) {
		if(S[i]=='#') {
			GA[i]=1;
		}
		else {
			double a=1-(GA[i+1]+GA[i+2]+1)/3.0;
			double b=(GB[i+1]+GB[i+2])/3.0+1;
			E[i]=b/a;
			GA[i]=(GA[i+1]+GA[i+2])/3;
			GB[i]=(GB[i+1]+GB[i+2]+E[i])/3+1;
		}
	}
	_P("%.12lf\n",E[0]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
