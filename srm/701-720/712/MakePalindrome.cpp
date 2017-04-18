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

class MakePalindrome {
	public:
	vector <string> constructMinimal(string card) {
		int i;
		int cnt[256]={};
		FORR(c,card) cnt[c]++;
		
		vector<string> R;
		string T;
		FOR(i,256) if(cnt[i]%2==1) {
			T+=(char)i;
			cnt[i]--;
			break;
		}
		FOR(i,256) while(cnt[i]>=2) {
			T=(char)i+T+(char)i;
			cnt[i]-=2;
		}
		R.push_back(T);
		FOR(i,256) if(cnt[i]) R.push_back(string(1,i));
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "abbaa"; string Arr1[] = {"ababa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, constructMinimal(Arg0)); }
	void test_case_1() { string Arg0 = "abc"; string Arr1[] = {"a", "b", "c" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, constructMinimal(Arg0)); }
	void test_case_2() { string Arg0 = "aaabbbccc"; string Arr1[] = {"aba", "bcb", "cac" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, constructMinimal(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arr1[] = {"oco", "d", "e", "p", "r", "t" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, constructMinimal(Arg0)); }
	void test_case_4() { string Arg0 = "z"; string Arr1[] = {"z" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, constructMinimal(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MakePalindrome ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

