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
ll A[2001];
ll mo=1000000007;

ll combi(ll N_, ll C_) {
	int i;
	const int num=5000;
	static ll rev[num+1],revt[num+1];
	
	if(rev[1]==0) {
		rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[mo%i]*(mo-mo/i)%mo;
		revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%mo;
	}
	ll ret=revt[C_];
	FOR(i,C_) ret = (ret * ((N_-i)%mo))%mo;
	return ret;
}

ll dodo(ll dif, ll cnt) {
	return combi(dif+cnt-1,cnt);
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll ret=1;
	x=0;
	for(i=1;i<N;i++) {
		if(A[i]>=0) {
			if(A[i]<A[x]) ret=0;
			else {
				ret = ret*dodo(A[i]-A[x]+1,i-x-1)%mo;
				x=i;
			}
		}
	}
	cout << ret << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


