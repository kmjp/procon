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

int N;
double memo[101];
static const int N_=1020;
static double C_[N_][N_];

double dodo(int n) {
	
	if(n==1) return 0;
	double& ret=memo[n];
	if(ret>=0) return ret;
	int i,x,y;
	double tot=0,cnt=0,ng=0;
	
	for(x=0;x<=n-1;x++) for(y=0;x+y<=n-1;y++) {
		double np=C_[n-1][x]*C_[n-1-x][y];
		int V[3]={x+1,y,n-1-x-y};
		
		sort(V,V+3);
		if(V[1]==0 || V[2]==V[0]) ng+=np;
		else {
			cnt+=np;
			tot+=np*dodo(V[0]?V[0]:V[1]);
		}
	}
	
	return ret = (cnt+ng+tot)/cnt;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	
	cin>>N;
	FOR(i,N+1) memo[i]=-1;
	_P("%.12lf\n",dodo(N));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
