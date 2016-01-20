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

class ListeningSongs {
	public:
	int listen(vector <int> D1, vector <int> D2, int minutes, int T) {
		sort(D1.begin(),D1.end());
		sort(D2.begin(),D2.end());
		partial_sum(D1.begin(),D1.end(),D1.begin());
		partial_sum(D2.begin(),D2.end(),D2.begin());
		int ma=-1,x,y;
		for(x=T;x<=D1.size();x++) 
			for(y=T;y<=D2.size();y++) if(D1[x-1]+D2[y-1]<=minutes*60) ma=max(ma,x+y);
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {300,200,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {400,500,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; int Arg3 = 1; int Arg4 = 4; verify_case(0, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {300,200,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {400,500,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,60,60}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 2; int Arg4 = 5; verify_case(2, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {120,120,120,120,120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,60,60,60,60,60}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 3; int Arg4 = 7; verify_case(3, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {196,147,201,106,239,332,165,130,205,221,248,108,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {280,164,206,95,81,383,96,255,260,244,60,313,101}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; int Arg3 = 3; int Arg4 = 22; verify_case(4, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {100,200,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; int Arg4 = -1; verify_case(5, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {100,200,300,400,500,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 3; int Arg4 = -1; verify_case(6, Arg4, listen(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ListeningSongs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
