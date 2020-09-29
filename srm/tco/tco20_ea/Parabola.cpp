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

class Parabola {
	public:
	vector <int> estimate(vector <int> Y) {
		
		ll A=1;
		ll B=-50;
		ll C=1<<30;
		ll mi=1LL<<60;
		int x;
		
		for(int a=1;a<=50;a++) {
			for(int b=-50;b<=50;b++) {
				vector<ll> V;
				FOR(x,Y.size()) {
					V.push_back(Y[x]-(a*x*x+b*x));
				}
				sort(ALL(V));
				ll c=V[(V.size()-1)/2];
				ll sum=0;
				FORR(v,V) sum+=abs(v-c);
				if(sum<mi) {
					mi=sum;
					A=a;
					B=b;
					C=c;
				}
				
			}
		}
		
		return {(int)A,(int)B,(int)C};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 4, 9, 16, 25, 36, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, estimate(Arg0)); }
	void test_case_1() { int Arr0[] = {10000, 10030, 10120, 10269, 10482, 10750, 11077, 11471}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 0, 10000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, estimate(Arg0)); }
	void test_case_2() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -50, 47 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, estimate(Arg0)); }
	void test_case_3() { int Arr0[] = {-10000, -9990, -9960, -9910, -9838, -9748, -9638, -9508}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 0, -10000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, estimate(Arg0)); }
	void test_case_4() { int Arr0[] = {-123, 456, -78, 901234, -5678, 901, -234567}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -50, 18 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, estimate(Arg0)); }
	void test_case_5() { int Arr0[] = {530, 486, 449, 415, 389, 370, 357, 347, 346, 349, 359, 377, 398, 427, 459, 499, 545, 597, 655, 721, 790, 865, 947, 1035, 1129, 1231, 1335, 1448, 1566, 1689}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, -47, 529 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, estimate(Arg0)); }
	void test_case_6() { int Arr0[] = {10, 78, 190}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 46, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, estimate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Parabola ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

