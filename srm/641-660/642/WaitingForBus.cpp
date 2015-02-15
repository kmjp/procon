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

double dp[100200];

class WaitingForBus {
	public:
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		int i,x;
		double ret=0;
		ZERO(dp);
		dp[0]=1;
		if(s==0) return 0;
		FOR(i,s+1) {
			FOR(x,time.size()) {
				if(i+time[x]>=s) ret += (i+time[x]-s)*dp[i]*prob[x]/100;
				else dp[i+time[x]] += dp[i]*prob[x]/100;
			}
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 9.5; verify_case(0, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 101; double Arg3 = 4.0; verify_case(1, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 88888; double Arg3 = 3.666666666666667; verify_case(2, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 1.166666666666667; verify_case(3, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,100,1000,10000,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100000; double Arg3 = 21148.147303578935; verify_case(4, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WaitingForBus ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
