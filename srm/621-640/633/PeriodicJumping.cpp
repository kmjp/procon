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

class PeriodicJumping {
	public:
	int minimalTime(int x, vector <int> jumpLengths) {
		int N=jumpLengths.size(),i;
		x=abs(x);
		ll tot=0,ma=x;
			
		if(x==0) return 0;
		FOR(i,2*N) {
			tot+=jumpLengths[i%N];
			ma=max(ma,(ll)jumpLengths[i%N]);
			if(ma*2<=tot+x) return i+1;
		}
		
		tot/=2;
		ll ret=x/tot*N;
		x%=tot;
		FOR(i,N) {
			if(x<=0) return ret;
			x-=jumpLengths[i];
			ret++;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -10; int Arr1[] = {2,3,4,500,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -1000000000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000000; verify_case(4, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {19911120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, minimalTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PeriodicJumping ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

