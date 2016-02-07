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

double S[305];
vector<vector<double>> memo[305];

class CoinFlips {
	public:
	double P;
	
	double pat(int L,int R,int N) {
		if(L+1==R) return 1;
		if(memo[N][L][R]>=0) return memo[N][L][R];
		double ret=0;
		
		double LP=S[L];
		double JL=(1-S[L])*P;
		double MP=(1-S[L+1])*S[R-L-1];
		double JR=(1-S[R])*P;
		double RP=(1-S[R+1])*S[N-R-1];
		double non=1-LP-JL-MP-JR-RP;
		if(L==0) JL+=non;
		else LP+=non;
		
		
		if(L) ret += LP*pat(L-1,R-1,N-1);
		ret += MP*pat(L,R-1,N-1);
		if(R<N-1) ret += RP*pat(L,R,N-1);
		
		return memo[N][L][R]=ret;
	}
	
	double getExpectation(vector <int> vals, int prob) {
		int x,y,z;
		if(prob==0 || prob==1000000000) return 0;
		P=prob/1e9;
		
		S[0]=0;
		FOR(z,303) {
			S[z+1]=S[z]+(1-S[z])*P;
			memo[z].clear();
			FOR(x,z+1) memo[z].push_back(vector<double>(z+1,-1));
		}
		
		double ret=0;
		FOR(y,vals.size()) FOR(x,y-1) ret+=pat(x,y,vals.size())*vals[x]*vals[y];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 500000000; double Arg2 = 2.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,1,4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000000; double Arg2 = 4.985392200480001; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 0.0; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; double Arg2 = 0.0; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 250000000; double Arg2 = 130.25145424313288; verify_case(4, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,5,6,2,6,4,3,3,8,3,2,7,9,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456789; double Arg2 = 481.6707820920715; verify_case(5, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CoinFlips ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
