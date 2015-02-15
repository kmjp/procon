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
int H[300101];
int D;
ll dpdp[350][1200][10];
ll mo=1000000007;
ll dp2[305520];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>H[i];
	FOR(i,300) FOR(x,10) {
		dpdp[i][x][x]=1;
		FOR(y,1000) FOR(j,H[i*1000+y]) dpdp[i][y+j+1][x]=(dpdp[i][y+j+1][x]+dpdp[i][y][x])%mo;
	}
	
	cin>>D;
	while(D--) {
		int S,T;
		cin>>S>>T;
		S--,T--;
		
		for(x=S;x<S+3000;x++) dp2[x]=0;
		dp2[S]=1;
		
		if(T-S>3000) {
			int S2=(S+999)/1000*1000;
			for(x=S;x<S2;x++) FOR(y,H[x]) dp2[x+y+1]=(dp2[x+y+1]+dp2[x])%mo;
			for(S=S2;S+2000<T;S+=1000) {
				FOR(x,10) dp2[S+1000+x]=0;
				FOR(x,10) FOR(y,10) dp2[S+1000+y]+=dp2[S+x]*dpdp[S/1000][1000+y][x]%mo;
				FOR(x,10) dp2[S+1000+x]%=mo;
			}
			for(x=S+10;x<S+4000;x++) dp2[x]=0;
		}
		for(x=S;x<T;x++) FOR(y,H[x]) dp2[x+y+1]=(dp2[x+y+1]+dp2[x])%mo;
		cout << dp2[T] << endl;
	}
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


