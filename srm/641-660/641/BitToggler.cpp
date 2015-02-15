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

class BitToggler {
	public:
	vector <double> expectation(int n, vector <string> bits, vector <int> pos) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = {"0","1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.0, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.5 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"1000","0010","0011","1010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {8.9375, 8.5625, 9.75, 10.25 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; string Arr1[] = {"01101111001001001111","01011100001001010111","00000000000000010000","10111111101111111011"
,"11101111111011010100","11111010110000000001","11000000100001100110","11111001010011101100"
,"11111111111111110111","01000011100010001000","01101111110111011111","11110111111111111110"
,"11111111111010110111","00100010000010000010","01000000000010000000","01110011111011000010"
,"11111101110001110111","11010010000000100000","10010101100000101000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,6,1,1,7,9,0,8,16,16,14,4,9,8,11,3,12,15,11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {3695311.183337145, 3695341.038888902, 3486510.5078947134, 3690384.721723784, 3695146.5166465323, 3695333.788886834, 3695264.399989025, 3695310.983335239, 3486508.9763158862, 3695148.3166833473, 3693970.9054913437, 3670001.842105858, 3690381.122961273, 3693970.005510611, 3670000.4482457424, 3695335.888887129, 3694859.0889757653, 3694860.2888290025, 3695260.0000010678 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, expectation(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BitToggler ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
