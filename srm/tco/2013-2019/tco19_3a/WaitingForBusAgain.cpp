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

double prob[1020][1020];
double val[1020][1020];

class WaitingForBusAgain {
	public:
	double expectedBus(vector <int> f) {
		int N=f.size();
		int mi=*min_element(ALL(f));
		
		int i,j;
		ZERO(prob);
		ZERO(val);
		prob[0][0]=1;
		FOR(i,N) {
			double p=mi*1.0/f[i];
			FOR(j,N) {
				// take
				prob[i+1][j+1]+=p*prob[i][j];
				val[i+1][j+1]+=p*(val[i][j]*j+prob[i][j]*i)/(j+1);
				// not
				prob[i+1][j]+=(1-p)*prob[i][j];
				val[i+1][j]+=(1-p)*(val[i][j]);
			}
		}
		
		double ret=0;
		for(i=1;i<=N;i++) ret+=val[N][i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,8,8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, expectedBus(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5; verify_case(1, Arg1, expectedBus(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5000000000000002; verify_case(2, Arg1, expectedBus(Arg0)); }
	void test_case_3() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.7044469870664325; verify_case(3, Arg1, expectedBus(Arg0)); }
	void test_case_4() { int Arr0[] = {26, 19548, 19299, 19431, 39568, 19476, 19726, 19530, 19613,
19529, 19679, 19552, 19706, 19505, 19666, 19349, 19755, 19424,
19486, 19596, 19439, 19500, 19639, 19520, 19472, 19675, 19602,
19552, 19933, 19424, 19316, 19497, 19582, 19531, 19679, 19742,
19896, 19365, 20083, 19542, 19827, 19583, 19592, 19593, 19661,
19340, 19403, 19664, 19690, 19655, 19727, 19661, 19528, 19836,
19819, 19414, 19770, 19500, 19653, 19613, 19579, 19794, 19668,
19729, 19428, 19477, 19733, 19641, 19680, 19594, 19667, 19878,
19571, 19627, 19576, 19422, 19521, 19512, 19481, 19620, 19364,
19487, 19740, 19627, 19795, 19353, 19251, 19865, 19710, 19597,
19610, 19710, 19491, 19598, 19650, 19828, 19726, 19810, 19766,
19692}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.1415926535671885; verify_case(4, Arg1, expectedBus(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WaitingForBusAgain ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

