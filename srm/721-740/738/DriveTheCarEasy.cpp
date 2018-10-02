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

class DriveTheCarEasy {
	public:
	long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments) {
		ll ret=0;
		int i;
		FOR(i,N) {
			ret+=(ll)(S-moments[i]+1)*speed_changes[i];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 1; int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1000000LL; verify_case(0, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 35LL; verify_case(1, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 5; int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 100, 100, 100, 100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 15LL; verify_case(2, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 3; int Arr2[] = {1000, 1000, 1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 2999999997000LL; verify_case(3, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 10; int Arr2[] = {522,426,772,447,497,775,982,417,932,728}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {75,45,81,29,2,25,84,56,2,37}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 367474LL; verify_case(4, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000000; int Arg1 = 100; int Arr2[] = {857,918,679,340,868,940,593,991,355,431,757,934,676,221,
 922,511,467,691,835,965,221,501,325,302,896,489,607,432,
 968,475,84,694,354,409,643,951,420,607,167,438,986,483,
 806,858,553,554,325,279,327,832,200,658,992,467,958,600,
 473,775,770,718,807,898,530,569,384,913,315,334,392,8,
 962,850,61,588,980,890,747,740,469,516,7,299,163,571,455,
 590,427,342,239,875,258,377,428,455,653,768,307,878,368,882}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {189330739,802329211,303238506,492686568,125660016,839296263,
 492601449,191890310,782177068,818008580,160449218,840594328,
 797829355,501899080,545531545,350034067,470338674,533206504,
 31262034,677959980,846045895,346948152,506147731,816248153,
 37119022,215208399,189766466,137831502,47628333,409233792,
 888987010,87027328,421624712,871216480,509928121,14723492,
 569328197,807497925,537560717,889089200,846216104,76823620,
 242790881,792345559,632488502,70422962,26697435,992120464,
 499482549,736386595,940778720,306890639,1849130,672298989,
 331602581,206347466,149811929,316412581,927999455,441504628,
 673419335,198091552,599715811,441414148,80656954,110880114,
 233703686,209550382,214278326,936333553,989214957,989248231,
 954621185,909664305,887357564,988670052,922390943,901347593,
 528977370,817020443,81469525,101430412,801006699,99958976,
 458482217,770179343,91883220,87104584,8454496,269122601,
 483571449,667480040,926138238,897273517,774034433,359911957,
 94576456,741452977,171601999,723473541}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 29493629905568LL; verify_case(5, Arg4, calculateDistance(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DriveTheCarEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

