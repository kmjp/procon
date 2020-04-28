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

class EllysTickets {
	public:
	double getPrice(vector <int> ticketPrice, int fine) {
		int N=ticketPrice.size();
		int x,y;
		double mi=fine;
		
		FOR(x,N) {
			double f=1.0*fine*x/N+ticketPrice[x]*1.0*(N-x)/N;
			mi=min(mi,f);
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 5, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arg2 = 6.666666666666667; verify_case(0, Arg2, getPrice(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {50, 40, 30, 20, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; double Arg2 = 33.2; verify_case(1, Arg2, getPrice(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; double Arg2 = 13.0; verify_case(2, Arg2, getPrice(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {951, 924, 908, 907, 889, 880, 870, 810, 770, 731, 716, 713, 687, 677,
 650, 645, 608, 598, 556, 472, 470, 446, 446, 410, 401, 352, 337, 337,
 226, 191, 189, 183, 176, 173, 168, 148, 100, 92, 84, 57, 41, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 344; double Arg2 = 296.6428571428571; verify_case(3, Arg2, getPrice(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTickets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

