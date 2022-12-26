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

int memo[202020];
int N;
string S;

int F(int v) {
	if(memo[v]==-1) memo[v]=1+F(v%__builtin_popcount(v));
	return memo[v];
}

int p2[202020][3];
int Q[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	MINUS(memo);
	memo[0]=0;
	
	int num=0;
	FORR(c,S) num+=c=='1';
	
	FOR(j,3) {
		x=num-1+j;
		if(x>0) {
			p2[0][j]=1;
			FOR(i,N) {
				p2[i+1][j]=p2[i][j]*2%x;
				Q[j]=(Q[j]*2+(S[i]=='1'))%x;
			}
		}
	}
	
	
	FOR(i,N) {
		if(S[i]=='1') {
			if(num==1) {
				cout<<0<<endl;
			}
			else {
				x=num-1;
				y=((Q[0]-p2[N-1-i][0])%x+x)%x;
				cout<<1+F(y)<<endl;
			}
		}
		else {
			x=num+1;
			y=(Q[2]+p2[N-1-i][2])%x;
			cout<<1+F(y)<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
