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

class NextOlympics {
	public:
	int countDays(string today) {
		int Y=today[3]-'0';
		int M=(today[5]-'0')*10+(today[6]-'0');
		int D=(today[8]-'0')*10+(today[9]-'0');
		
		int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		
		int num=0;
		while(Y<1 || M<7 || D<23) {
			num++;
			D++;
			int tar=day[M];
			if(Y==0 && D==2) tar=29;
			if(D>tar) {
				M++;
				D=1;
				if(M==13) {
					Y++;
					M=1;
				}
			}
		}
		return num;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "2020.07.24"; int Arg1 = 364; verify_case(0, Arg1, countDays(Arg0)); }
	void test_case_1() { string Arg0 = "2020.11.09"; int Arg1 = 256; verify_case(1, Arg1, countDays(Arg0)); }
	void test_case_2() { string Arg0 = "2021.02.25"; int Arg1 = 148; verify_case(2, Arg1, countDays(Arg0)); }
	void test_case_3() { string Arg0 = "2021.07.23"; int Arg1 = 0; verify_case(3, Arg1, countDays(Arg0)); }
	void test_case_4() { string Arg0 = "2020.12.31"; int Arg1 = 204; verify_case(4, Arg1, countDays(Arg0)); }
	void test_case_5() { string Arg0 = "2021.01.01"; int Arg1 = 203; verify_case(5, Arg1, countDays(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NextOlympics ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

