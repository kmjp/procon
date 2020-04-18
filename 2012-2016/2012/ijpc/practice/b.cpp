#include "grader.h"
#include "primehazard.h"

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


const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void taro(int N) {
	int i,j;
	cprime();
	FOR(i,4095) if(N%prime[i]==0 && N!=prime[i]) break;
	FOR(j,12) send((i>>j)%2);
}

int jiro(int S, int X[]) {
	cprime();
	int i,num=0;
	FOR(i,12) num|=X[i]<<i;
	if(num==4095) return -1;
	return prime[num];
}

