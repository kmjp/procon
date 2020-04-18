#include"grader.h"
#include"submission.h"

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

ll F[52][100200];
long long getT(int N, long long M) {
	int x,y;
	FOR(x,51) F[x][0]=1;
	FOR(x,100110) F[0][x]=1;
	for(x=1;x<=50;x++) for(y=1;y<=100010;y++) F[x][y]=min(1LL<<40,F[x-1][y-1]+F[x][y-1]);
	
	ll L=0,R=M,i;
	int num=lower_bound(F[N],F[N]+100005,M+1)-F[N];
	while(num&&L<R) {
		int range=R-L+1;
		num--;
		ll add=F[N-1][num];
		ll X=min(R,L+add-1);
		//cout<<"ask"<<X<<endl;
		int ret=compare(X);
		//cout<<"ask"<<X<<" "<<ret<<endl;
		if(ret==1) {
			N--;
			R=X;
		}
		else {
			L=X+1;
		}
	}
	
	//cout<<N<<" "<<L<<" "<<R<<endl;
	return L;
}
