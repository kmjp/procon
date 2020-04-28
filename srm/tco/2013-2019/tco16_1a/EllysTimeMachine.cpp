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

class EllysTimeMachine {
	public:
	string getTime(string time) {
		int h=(time[0]-'0')*10+(time[1]-'0');
		int m=(time[3]-'0')*10+(time[4]-'0');
		h*=5;
		m/=5;
		if(h==60) h=0;
		if(m==0) m=12;
		time[0]=(m/10)+'0';
		time[1]=(m%10)+'0';
		time[3]=(h/10)+'0';
		time[4]=(h%10)+'0';
		return time;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "11:20"; string Arg1 = "04:55"; verify_case(0, Arg1, getTime(Arg0)); }
	void test_case_1() { string Arg0 = "02:25"; string Arg1 = "05:10"; verify_case(1, Arg1, getTime(Arg0)); }
	void test_case_2() { string Arg0 = "06:30"; string Arg1 = "06:30"; verify_case(2, Arg1, getTime(Arg0)); }
	void test_case_3() { string Arg0 = "05:55"; string Arg1 = "11:25"; verify_case(3, Arg1, getTime(Arg0)); }
	void test_case_4() { string Arg0 = "03:45"; string Arg1 = "09:15"; verify_case(4, Arg1, getTime(Arg0)); }
	void test_case_5() { string Arg0 = "01:00"; string Arg1 = "12:05"; verify_case(5, Arg1, getTime(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTimeMachine ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
