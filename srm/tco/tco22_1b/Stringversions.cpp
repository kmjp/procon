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

class Stringversions {
	public:
	string create(int L, int N) {
		string S;
		int i,j;
		FOR(i,L) S+='a'+i%26;
		sort(ALL(S));
		
		FOR(i,L) {
			for(j=i-1;N&&j>=0;j--) {
				if(S[j]==S[j+1]) break;
				swap(S[j],S[j+1]);
				N--;
			}
		}
		if(N) return "";
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "hello"; verify_case(0, Arg2, create(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 0; string Arg2 = "xxxxxxx"; verify_case(1, Arg2, create(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 21; string Arg2 = "sponged"; verify_case(2, Arg2, create(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 27; int Arg1 = 351; string Arg2 = ""; verify_case(3, Arg2, create(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 25; int Arg1 = 152; string Arg2 = "topcoderroundonesubroundb"; verify_case(4, Arg2, create(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Stringversions ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

