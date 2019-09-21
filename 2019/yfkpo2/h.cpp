#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<pair<int,int>> V;
int Y[11],X[11];
int C[11];

int memo[1<<10][12];

int win(int mask,int last) {
	if(memo[mask][last]>=0) return memo[mask][last];
	int nex=N-__builtin_popcount(mask);
	
	int i;
	FOR(i,N) if((mask&(1<<i))&&abs(Y[last]-Y[i])+abs(X[last]-X[i])==C[nex]) {
		if(win(mask^(1<<i),i)==0) return memo[mask][last]=1;
	}
	return memo[mask][last]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	i=0;
	FOR(y,5) {
		cin>>s;
		FOR(x,5) {
			if(s[x]=='G') Y[N]=y, X[N]=x;
			if(s[x]=='B') {
				Y[i]=y;
				X[i]=x;
				i++;
			}
		}
	}
	FOR(i,N) cin>>C[i];
	MINUS(memo);
	cout<<(win((1<<N)-1,N)?"gori":"uho")<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
