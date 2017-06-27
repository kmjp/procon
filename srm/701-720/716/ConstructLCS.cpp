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

class ConstructLCS {
	public:
	string construct(int ab, int bc, int ca) {
		int P[3]={ab,bc,ca};
		sort(P,P+3);
		string X=string(P[0],'0');
		string Y=string(P[1]-P[0],'1');
		string Z=string(P[2]-P[0],'0');
		
		if(ab<=bc&&bc<=ca) return (X+Z)+" "+(X+Y)+" "+(X+Y+Z);
		if(ab<=ca&&ca<=bc) return (X+Y)+" "+(X+Z)+" "+(X+Y+Z);
		if(bc<=ab&&ab<=ca) return (X+Y+Z)+" "+(X+Y)+" "+(X+Z);
		if(bc<=ca&&ca<=ab) return (X+Y+Z)+" "+(X+Z)+" "+(X+Y);
		if(ca<=ab&&ab<=bc) return (X+Y)+" "+(X+Y+Z)+" "+(X+Z);
		return (X+Z)+" "+(X+Y+Z)+" "+(X+Y);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; string Arg3 = "101 1010101 1111"; verify_case(0, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 4; string Arg3 = "10101010 1010101 1011"; verify_case(1, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 7; int Arg2 = 8; string Arg3 = "110101001011 010101101 10101010"; verify_case(2, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 6; int Arg2 = 7; string Arg3 = "110101010 10101010 1111010"; verify_case(3, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 17; int Arg2 = 19; string Arg3 = "000100101101111011000 11110111010011101010 100100001010101001010101000011111"; verify_case(4, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 50; string Arg3 = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111"; verify_case(5, Arg3, construct(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConstructLCS ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

