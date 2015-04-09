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

ll mo=1000000007;
ll p9[8];
int num[50];

ll dp[5050][10];
ll dp2[2][9*9*9*9*10];

class NineEasy {
	public:
	int count(int N, vector <int> d) {
		int x,y,i,z,ad;
		
		p9[0]=1;
		FOR(i,6) p9[i+1]=p9[i]*9;
		
		ZERO(num);
		FOR(i,d.size()) num[d[i]]++;
		
		ZERO(dp);
		dp[0][0]=1;
		FOR(i,5020) {
			FOR(x,9) FOR(y,10) dp[i+1][(x+y)%9] += dp[i][x];
			FOR(x,9) dp[i+1][x]%=mo;
		}
		
		ZERO(dp2);
		dp2[0][0]=1;
		FOR(i,1<<N) {
			int cur=i&1,tar=cur^1;
			ZERO(dp2[tar]);
			
			FOR(x,p9[N]) if(dp2[cur][x]) {
				dp2[cur][x] %= mo;
				FOR(ad,9) if(dp[num[i]][ad]) {
					int nex=x;
					FOR(y,5) if(i&(1<<y)) {
						int cu=nex/p9[y]%9;
						nex -= cu*p9[y];
						cu=(cu+ad)%9;
						nex += cu*p9[y];
					}
					dp2[tar][nex] += dp2[cur][x]*dp[num[i]][ad]%mo;
				}
			}
			
		}
		return dp2[0][0] % mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {1,2,4,8,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 893703876; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NineEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
