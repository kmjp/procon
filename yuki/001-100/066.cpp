#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int M;
int S[2000];
double D[11][2000];
double P[2000][2000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,1<<M) cin>>S[i], D[0][i]=1;
	FOR(x,1<<M) FOR(y,1<<M) P[x][y]=(S[x]*S[x]*1.0)/(S[x]*S[x]+S[y]*S[y]);
	
	int mask=0xFFFFFF;
	FOR(i,M) {
		mask -= 1<<i;
		FOR(x,1<<M) {
			FOR(y,1<<M) if((x&mask)==(y&mask) && ((x^y)&(1<<i))) D[i+1][x]+=D[i][y]*P[x][y];
			D[i+1][x]*=D[i][x];
		}
	}
	
	_P("%.12lf\n",D[M][0]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
