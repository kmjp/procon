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

class CatsOnTheCircle {
	public:
	long double P;
	
	long double goR(int L,int R) {
		int T=L+R;
		
		if(abs(P-0.5)<1e-10) return L*1.0/T;
		
		long double k = P/(1-P);
		long double a = 1/(1-pow(k,T));
		long double b = 1-a;
		return a*pow(k,R)+b;
		
	}
	
	double getProb(int N, int K, int p) {
		if(p>1000000000-p) {
			p=1000000000-p;
			K=N-K;
		}
		
		P=p/1e9;
		int L=N-K-1,R=K-1;
		return goR(L,R)*(1-goR(N-2,1))+(1-goR(L,R))*goR(1,N-2);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 300000000; double Arg3 = 0.6999999999999985; verify_case(0, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 500000000; double Arg3 = 0.2; verify_case(1, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 500000000; double Arg3 = 0.2; verify_case(2, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 666666666; double Arg3 = 0.00391389439551009; verify_case(3, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 999999999; int Arg1 = 999999996; int Arg2 = 777777777; double Arg3 = 0.05830903870125612; verify_case(4, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000000000; int Arg1 = 4; int Arg2 = 300000000; double Arg3 = 0.044981259448371; verify_case(5, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 534428790; int Arg1 = 459947197; int Arg2 = 500000000; double Arg3 = 1.871156682766205E-9; verify_case(6, Arg3, getProb(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CatsOnTheCircle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
