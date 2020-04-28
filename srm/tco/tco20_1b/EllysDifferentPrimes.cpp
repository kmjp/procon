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


bool ng[60000001];

class EllysDifferentPrimes {
	public:
	int getClosest(int N) {
		ZERO(ng);
		int i;
		vector<int> P;
		int ret=-1<<28;
		for(i=2;i<=51000000;i++) if(ng[i]==0) {
			for(int j=min(51000000LL,1LL*i*i);j<=51000000;j+=i) ng[j]=1;
			int mask=0;
			int j=i;
			while(j) {
				if(mask&(1<<(j%10))) break;
				mask |= (1<<(j%10));
				j/=10;
			}
			if(j==0 && abs(N-i)<abs(N-ret)) ret=i;
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 97; verify_case(0, Arg1, getClosest(Arg0)); }
	void test_case_1() { int Arg0 = 123457; int Arg1 = 123457; verify_case(1, Arg1, getClosest(Arg0)); }
	void test_case_2() { int Arg0 = 6661337; int Arg1 = 6701459; verify_case(2, Arg1, getClosest(Arg0)); }
	void test_case_3() { int Arg0 = 42424242; int Arg1 = 42398701; verify_case(3, Arg1, getClosest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysDifferentPrimes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

