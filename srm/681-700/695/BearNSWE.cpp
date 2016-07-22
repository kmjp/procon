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

class BearNSWE {
	public:
	double totalDistance(vector <int> a, string dir) {
		double ret=0;
		int i,x=0,y=0;
		FOR(i,a.size()) {
			ret += a[i];
			if(dir[i]=='N') y-=a[i];
			if(dir[i]=='S') y+=a[i];
			if(dir[i]=='W') x-=a[i];
			if(dir[i]=='E') x+=a[i];
		}
		ret += sqrt(x*x+y*y);
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NES"; double Arg2 = 10.60555127546399; verify_case(0, Arg2, totalDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10,10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NWSE"; double Arg2 = 40.0; verify_case(1, Arg2, totalDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,10,10,15,8,20,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NEWEWWE"; double Arg2 = 90.8062484748657; verify_case(2, Arg2, totalDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "E"; double Arg2 = 84.0; verify_case(3, Arg2, totalDistance(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,40,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NSE"; double Arg2 = 140.0; verify_case(4, Arg2, totalDistance(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearNSWE ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
