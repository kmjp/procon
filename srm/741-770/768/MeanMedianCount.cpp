#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll from[26][500];
ll to[26][500];
ll mo=1000000007;

class MeanMedianCount {
	public:
	int getCount(int N, int needMean, int needMedian) {
		ZERO(from);
		from[0][0]=1;
		int i,x,y,z;
		FOR(i,N) {
			ZERO(to);
			FOR(x,min(25,i)+1) FOR(y,i*10+1) FOR(z,11) {
				(to[min(N/2+1,x+(z>=needMedian))][y+z]+=from[x][y])%=mo;
			}
			swap(from,to);
		}
		
		ll ret=0;
		for(x=needMean*N;x<=490;x++) ret+=from[N/2+1][x];
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 9; int Arg2 = 10; int Arg3 = 10; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 8; int Arg3 = 162; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 8; int Arg3 = 1; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 1; int Arg3 = 14874; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 49; int Arg1 = 0; int Arg2 = 0; int Arg3 = 21051900; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 8; int Arg3 = 3; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 5; int Arg3 = 2; verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MeanMedianCount ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

