#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
ll CC[101];
int num[101];


const int CN=1001;
double C[CN][CN];
double K[CN];

void solve() {
	int f,i,j,k,l,x,y;
	
	K[0]=1;
	FOR(x,CN) C[x][0]=C[x][x]=1, K[x+1]=K[x]*(x+1);
	for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j]);
	
	cin>>N;
	FOR(i,N) cin>>CC[i];
	sort(CC,CC+N);
	FOR(x,N) FOR(y,N) {
		if(x!=y) num[y]+=(CC[y]%CC[x]==0);
	}
	
	double ret=0;
	FOR(i,N) {
		x=num[i];
		for(j=0;j<=x;j+=2) {
			ret += C[x][j]*K[j]*K[x-j]/K[x+1];
		}
	}
	_P("%.8lf\n",ret);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


