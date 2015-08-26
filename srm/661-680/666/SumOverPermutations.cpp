#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
ll hc[4040];
ll fc[4040];
const int CN=4001;
ll C[CN][CN];

class SumOverPermutations {
	public:
	int findSum(int n) {
		ZERO(hc);
		ZERO(fc);
		int i,j;
		
		FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		hc[0]=fc[0]=1;
		hc[1]=n-1;
		fc[1]=n-2;
		
		for(i=2;i<n;i++) {
			FOR(j,i) {
				// half close
				if(j==0) hc[i] += (n-1)*hc[i-1]%mo;
				else hc[i] += n*fc[j]%mo*hc[i-1-j]%mo*C[i-1][j]%mo;
				//full close
				if(j==0||j==i-1) fc[i] += (n-1)*fc[i-1]%mo;
				else fc[i] += n*fc[j]%mo*fc[i-1-j]%mo*C[i-1][j]%mo;
			}
			hc[i]%=mo;
			fc[i]%=mo;
		}
		
		ll ret=0;
		FOR(i,n) {
			if(i==0 || i==n-1) ret += n*hc[n-1]%mo;
			else ret += n*hc[i]%mo*hc[n-1-i]%mo*C[n-1][i]%mo;
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 66; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 58310114; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { int Arg0 = 3900; int Arg1 = 940560814; verify_case(3, Arg1, findSum(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SumOverPermutations ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
