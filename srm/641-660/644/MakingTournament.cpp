#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int MAT=128;
ll G[MAT][MAT],G2[MAT][MAT];
ll mo=1000000007;
void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=0;
	FOR(i,n) r[i][i]=1;
	while(p) {
		ll h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (r[x][z]*a2[z][y]) % mo;
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y]%mo;
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (a2[x][z]*a2[z][y]) % mo;
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y]%mo;
		p>>=1;
	}
}


class MakingTournament {
	public:
	int howManyWays(long long N, int K) {
		int i,j,x,y;
		ZERO(G);
		
		FOR(i,1<<K) {
			FOR(j,K+1) if((i&((1<<j)-1))==((1<<j)-1)) {
				x=(i | (1<<j)) ^ ((1<<j)-1);
				if(j==K) x=0;
				G[x][i]=1;
			}
		}
		powmat(N,1<<K,G,G2);
		return G2[0][0]%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { long long Arg0 = 6LL; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; int Arg1 = 3; int Arg2 = 1; verify_case(1, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 10LL; int Arg1 = 2; int Arg2 = 45; verify_case(2, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 63LL; int Arg1 = 6; int Arg2 = 0; verify_case(3, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1000000000000000LL; int Arg1 = 6; int Arg2 = 429388700; verify_case(4, Arg2, howManyWays(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MakingTournament ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
