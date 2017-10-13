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

class TCPhoneHome {
	public:
	long long validNumbers(int digits, vector <string> S) {
		int N=S.size();
		int invalid[100]={};
		ll p10[20];
		int i,j;
		p10[0]=1;
		FOR(i,18) p10[i+1]=p10[i]*10;
		
		ll ret=p10[digits];
		FOR(i,N) {
			FOR(j,N) if(i!=j) {
				if(S[j].size()<S[i].size() && S[i].substr(0,S[j].size())==S[j]) invalid[i]=1;
			}
			if(invalid[i]==0) {
				ret-=p10[digits-S[i].size()];
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; string Arr1[] = {"0", "1", "911"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7990000LL; verify_case(0, Arg2, validNumbers(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; string Arr1[] = {"0", "1", "911"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7990000000LL; verify_case(1, Arg2, validNumbers(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8; string Arr1[] = {"1", "12", "123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 90000000LL; verify_case(2, Arg2, validNumbers(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; string Arr1[] = {"12", "13", "14"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 970000000LL; verify_case(3, Arg2, validNumbers(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; string Arr1[] = {"411"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 999LL; verify_case(4, Arg2, validNumbers(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TCPhoneHome ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

