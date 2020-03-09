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

double from[6000];
double to[6000];


class BeatTheStar {
	public:
	double doesItMatter(int N, int G) {
		
		ZERO(from);
		from[0]=1;
		int i,x,sum=0;
		for(i=1;i<=N;i++) if(i!=G) {
			sum+=i;
			ZERO(to);
			FOR(x,5600) if(from[x]) {
				to[x]+=from[x]/2.0;
				to[x+i]+=from[x]/2.0;
			}
			swap(from,to);
		}
		
		double ret=0;
		FOR(i,sum+1) {
			int a=sum-i;
			if(abs(a-i)<=G) ret+=from[i];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 0.0; verify_case(0, Arg2, doesItMatter(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; double Arg2 = 0.625; verify_case(1, Arg2, doesItMatter(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; double Arg2 = 0.125; verify_case(2, Arg2, doesItMatter(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; double Arg2 = 0.125; verify_case(3, Arg2, doesItMatter(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 7; double Arg2 = 0.328125; verify_case(4, Arg2, doesItMatter(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BeatTheStar ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

