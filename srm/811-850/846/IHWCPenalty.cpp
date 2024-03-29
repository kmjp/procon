#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class IHWCPenalty {
	public:
	string resolve(string events) {
		int A=0,B=0;
		string R;
		FORR(c,events) {
			if(c=='G') {
				if(A<B) R+="S";
				if(A==B) R+="=";
				if(A>B) R+="P",A--;
			}
			if(c=='g') {
				if(A>B) R+="S";
				if(A==B) R+="=";
				if(A<B) R+="P",B--;
			}
			if(c=='p') A++;
			if(c=='P') B++;
			if(c=='s') A--;
			if(c=='S') B--;
		}
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "gggGgGg"; string Arg1 = "======="; verify_case(0, Arg1, resolve(Arg0)); }
	void test_case_1() { string Arg0 = "PPggg"; string Arg1 = "PP="; verify_case(1, Arg1, resolve(Arg0)); }
	void test_case_2() { string Arg0 = "PPpPGGg"; string Arg1 = "SSP"; verify_case(2, Arg1, resolve(Arg0)); }
	void test_case_3() { string Arg0 = "gGpPgGgGsSgG"; string Arg1 = "========"; verify_case(3, Arg1, resolve(Arg0)); }
	void test_case_4() { string Arg0 = "GgpPPGgg"; string Arg1 = "==SP="; verify_case(4, Arg1, resolve(Arg0)); }
	void test_case_5() { string Arg0 = "ggPPgSg"; string Arg1 = "==P="; verify_case(5, Arg1, resolve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IHWCPenalty ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

