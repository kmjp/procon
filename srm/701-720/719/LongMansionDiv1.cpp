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

class LongMansionDiv1 {
	public:
	long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
		int N=t.size();
		int dy=abs(eY-sY);
		
		ll ret=1LL<<60;
		for(int tx=0;tx<N;tx++) {
			ll tot=(ll)t[tx]*(dy-1);
			
			for(int x=min(sX,tx);x<=max(sX,tx);x++) tot+=t[x];
			for(int x=min(eX,tx);x<=max(eX,tx);x++) tot+=t[x];
			ret=min(ret,tot);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; int Arg3 = 2; int Arg4 = 2; long long Arg5 = 29LL; verify_case(0, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {5, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 15LL; verify_case(1, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {137, 200, 184, 243, 252, 113, 162}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 4; int Arg4 = 2; long long Arg5 = 1016LL; verify_case(2, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; int Arg2 = 433156521; int Arg3 = 28; int Arg4 = 138238863; long long Arg5 = 293443080673LL; verify_case(3, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1LL; verify_case(4, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LongMansionDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

