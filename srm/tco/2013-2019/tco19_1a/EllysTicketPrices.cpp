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

class EllysTicketPrices {
	public:
	double proc(ll cur,vector <int> C) {
		int i,j;
		ll sum=cur;
		FOR(j,C.size()) {
			ll c=cur*(100+C[j]);
			cur=c/100+(c%100>=50);
			sum+=cur;
			if(sum>1LL<<30) return 1LL<<30;
			
		}
		int N=C.size()+1;
		sum=sum/N+(sum%N*2>=N);
		return sum;
	}
	
	double getPrice(int N, vector <int> C, int target) {
		double L=0,R=1<<30;
		int i,j;
		target*=100;
		while(R-L>1) {
			ll M=(L+R)/2;
			if(proc(M,C)<target) L=M;
			else R=M;
		}
		
		return R/100.0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-10, 15, 5, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 180; double Arg3 = 184.01; verify_case(0, Arg3, getPrice(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 11; int Arr1[] = {5, 16, 17, -3, -10, 20, 20, 14, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1337; double Arg3 = 874.77; verify_case(1, Arg3, getPrice(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 42; double Arg3 = 42.0; verify_case(2, Arg3, getPrice(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arr1[] = {30, -26, 87, 47, -39, 25, -67, 62, -38, 68, -84, 5, 28, -20, 50, -61, 10, 63, -71}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 392; double Arg3 = 476.28; verify_case(3, Arg3, getPrice(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 50; int Arr1[] = {-60, 61, 17, 86, 56, 27, 9, 41, -27, -36, 57, -16, 1, 50, -55, -36, 14, 13, -93, 14, 18, 25, 62, -18, 40,
 79, 56, 19, 10, -55, -43, 45, -43, -84, 61, -64, 41, -55, 38, 18, 36, -43, 79, 33, 87, 19, -47, 38, -56}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8887; double Arg3 = 9451.93; verify_case(4, Arg3, getPrice(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTicketPrices ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

