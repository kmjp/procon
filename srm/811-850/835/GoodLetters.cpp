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

class GoodLetters {
	public:
	string construct(string good, int N, int G) {
		int C[26]={};
		FORR(c,good) C[c-'A']=1;
		int sum=0;
		int i;
		string S;
		int B=N-G;
		FOR(i,26) {
			if(B&&C[i]==0) {
				S+='A'+i;
				B--;
			}
			if(G&&C[i]==1) {
				S+='A'+i;
				G--;
			}
		}
		if(B||G) return "";
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AEIOU"; int Arg1 = 10; int Arg2 = 3; string Arg3 = "BLUEPRINTS"; verify_case(0, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "AAEEIOUIOUIOU"; int Arg1 = 10; int Arg2 = 3; string Arg3 = "BLUEPRINTS"; verify_case(1, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = ""; int Arg1 = 7; int Arg2 = 1; string Arg3 = ""; verify_case(2, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "EEEEE"; int Arg1 = 5; int Arg2 = 2; string Arg3 = ""; verify_case(3, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = ""; int Arg1 = 3; int Arg2 = 0; string Arg3 = "ABC"; verify_case(4, Arg3, construct(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoodLetters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

