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

class BalancedSubstrings {
	public:
	int countSubstrings(string s) {
		int N=s.size();
		int i,c,ret=0;
		
		FOR(i,N) s[i]-='0';
		
		FOR(c,N) {
			map<int,int> M[2];
			int ls=0,rs=0;
			
			for(i=c;i>=0;i--) ls += s[i]*(c-i), M[0][ls]++;
			for(i=c;i<N;i++) rs += s[i]*(i-c), M[1][rs]++;
			ITR(it,M[0]) if(it->first || s[c]==1) ret+=it->second*M[1][it->first];
		}
		int len=0;
		FOR(c,N) ret += (len = (s[c]?0:len+1));
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "011"; int Arg1 = 4; verify_case(0, Arg1, countSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "10111"; int Arg1 = 10; verify_case(1, Arg1, countSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = 15; verify_case(2, Arg1, countSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "0000001000000"; int Arg1 = 91; verify_case(3, Arg1, countSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "100110001001"; int Arg1 = 49; verify_case(4, Arg1, countSubstrings(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BalancedSubstrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
