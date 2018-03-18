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

double comb(int P_,int Q_) {
	static const int N_=1020;
	static double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

class DancingClass {
	public:
	string checkOdds(int n, int k) {
		if(n==2 && k==1) return "Equal";
		double ret=0;
		
		for(int a=0;a<=n;a++) {
			int b=n-a,c;
			if(a*b<k) continue;
			ret+=comb(n,a);
			
		}
		ret /= pow(2,n);
		if(ret>0.5) return "High";
		else return "Low";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "Equal"; verify_case(0, Arg2, checkOdds(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "High"; verify_case(1, Arg2, checkOdds(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arg2 = "Low"; verify_case(2, Arg2, checkOdds(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 500; int Arg1 = 500; string Arg2 = "High"; verify_case(3, Arg2, checkOdds(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; int Arg1 = 397; string Arg2 = "Low"; verify_case(4, Arg2, checkOdds(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Low"; verify_case(5, Arg2, checkOdds(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DancingClass ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

