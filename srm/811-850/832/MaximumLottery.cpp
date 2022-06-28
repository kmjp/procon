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

class MaximumLottery {
	public:
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
	double ticketPrice(vector <int> balls, int K) {
		
		sort(ALL(balls));
		double ret=0;
		int N=balls.size();
		int i;
		for(i=K-1;i<N;i++) {
			ret+=balls[i]*comb(i,K-1);
		}
		return ret/comb(N,K);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 10, 10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 10.0; verify_case(0, Arg2, ticketPrice(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 50, 40, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 50.0; verify_case(1, Arg2, ticketPrice(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11, 12, 13, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 13.75; verify_case(2, Arg2, ticketPrice(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {11, 12, 13, 14, 15, 16, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 14.142857142857142; verify_case(3, Arg2, ticketPrice(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 1, 2, 3, 5, 8, 13, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 15.685714285714285; verify_case(4, Arg2, ticketPrice(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaximumLottery ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

