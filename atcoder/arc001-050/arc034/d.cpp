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

int A,B,C,T;
int VA[100],VB[100];
double bdp[52];
double memo[55][55];
const int CN=51;
ll Co[CN][CN];
double AA;

double dp(int TA,int TB) {
	if(memo[TA][TB]>=0) return memo[TA][TB];
	double pa=TA*1.0/(TA+TB+C);
	double pb=TB*1.0/(TA+TB+C);
	double ret=0;
	if(pa) ret += pa*(bdp[B-TB] + dp(TA-1,TB));
	if(pb) ret += pb*dp(TA,TB-1);
	return memo[TA][TB]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	FOR(i,A) cin>>VA[i], AA+=VA[i];
	FOR(i,CN) for(j=0;j<=i;j++) Co[i][j]=(j==0||j==i)?1:(Co[i-1][j-1]+Co[i-1][j]);
	FOR(i,51) FOR(j,51) memo[i][j]=-1;
	
	bdp[0]=1;
	FOR(i,B) {
		cin>>VB[i];
		for(j=50;j>=0;j--) bdp[j+1]+=bdp[j]*VB[i];
	}
	for(i=1;i<=B;i++) bdp[i]=bdp[i]/Co[B][i];
	
	_P("%.12lf\n",dp(A,B)*(AA/A));
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
