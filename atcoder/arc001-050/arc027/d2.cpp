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
int D,S,T;

ll mo=1000000007;
ll ret[300100],sum[300100];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) cin>>H[i];
	cin>>D;
	
	while(D--) {
		cin>>S>>T;
		S--,T--;
		
		FOR(x,11) ret[x+T]=sum[x+T]=0;
		ret[T]=sum[T]=1;
		for(x=T-1;x>=S;x--) {
			ret[x]=sum[x+1]-sum[x+H[x]+1];
			if(ret[x]<0) ret[x]+=mo;
			sum[x]=sum[x+1]+ret[x];
			if(sum[x]>=mo) sum[x]-=mo;
		}
		cout << ret[S] << endl;
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
