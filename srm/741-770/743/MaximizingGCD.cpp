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

class MaximizingGCD {
	public:
	int maximumGCDPairing(vector <int> A) {
		int N=A.size();
		ll ma=0;
		int i,j;
		for(i=1;i<N;i++) {
			ll sum=A[0]+A[i];
			vector<ll> C;
			for(ll x=1;x*x<=sum;x++) if(sum%x==0) {
				C.push_back(x);
				C.push_back(sum/x);
			}
			
			FORR(c,C) {
				multiset<ll> M;
				for(j=1;j<N;j++) if(j!=i) {
					ll a=A[j]%c;
					if(M.count((c-a)%c)) M.erase(M.find((c-a)%c));
					else M.insert(a);
				}
				if(M.empty()) ma=max(ma,c);
			}
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 4, 13, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, maximumGCDPairing(Arg0)); }
	void test_case_1() { int Arr0[] = {26, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(1, Arg1, maximumGCDPairing(Arg0)); }
	void test_case_2() { int Arr0[] = {100, 200, 300, 500, 1100, 700}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, maximumGCDPairing(Arg0)); }
	void test_case_3() { int Arr0[] = {46, 78, 133, 92, 1, 23, 29, 67, 43, 111, 3908, 276, 13, 359, 20, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maximumGCDPairing(Arg0)); }
	void test_case_4() { int Arr0[] = {735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,735134400,}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16400; verify_case(4, Arg1, maximumGCDPairing(Arg0)); }	void test_case_5() { int Arr0[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16400; verify_case(4, Arg1, maximumGCDPairing(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaximizingGCD ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

