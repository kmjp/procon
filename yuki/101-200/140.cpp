#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll mo=1000000007;
ll C[1005][1005], P[1005][1005], Q[1005][1005];

int main(int argc,char** argv){
	int x,y,z;
	
	cin>>N;
	for(x = 0; x < 1002; x++) {
		C[x][0]=1;
		for(y = 1; y <= x; y++) C[x][y] = (C[x-1][y] + C[x-1][y-1]) % mo;
	}
	
	for(x = 1; x < 1002; x++) {
		P[x][1]=1;
		for(y = 2; y <= x; y++) P[x][y] = (P[x-1][y-1] + y * P[x-1][y]) % mo;
	}
	for(y = 0; y < 1002; y++) {
		Q[y][0] = 1;
		for(z = 0; z <= 1002; z++) Q[y][z+1] = Q[y][z] * y * (y-1) % mo;
	}
	
	ll ret = 0;
	for(x = 1; x <= N; x++)
		for(y = 1; y <= x; y++)
			ret = (ret + C[N][x] * P[x][y] % mo * Q[y][N-x]) % mo;
	
	cout << ret << endl;
}
