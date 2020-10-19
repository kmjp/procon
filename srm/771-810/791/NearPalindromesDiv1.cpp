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

class NearPalindromesDiv1 {
	public:
	int solve(string S) {
		int num[26]={};
		FORR(c,S) {
			c-='a';
			num[c]^=1;
		}
		vector<int> V;
		int i,x,y;
		FOR(i,26) if(num[i]) V.push_back(i);
		int ret=55555;
		if(V.size()<=1) {
			ret=0;
		}
		else {
			FOR(x,V.size()) {
				int sum=0;
				for(i=0;i+2<=V.size();i+=2) {
					int a=V[(x+i)%V.size()];
					int b=V[(x+i+1)%V.size()];
					sum+=min(abs(a-b),26-abs(a-b));
				}
				ret=min(ret,sum);
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cocoa"; int Arg1 = 0; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "daddy"; int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefgh"; int Arg1 = 4; verify_case(2, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NearPalindromesDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

