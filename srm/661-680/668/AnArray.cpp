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

int num[1010100];
class AnArray {
	public:
	int N;
	vector<ll> enumdiv(ll n) {
		vector<ll> S;
		for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
		sort(S.begin(),S.end());
		return S;
	}
	
	int solveProblem(vector <int> A, int K) {
		N=A.size();
		int i,x,y;
		ZERO(num);
		FORR(r,A) r=__gcd(r,K);
		
		ll ret=0;
		for(y=N-1;y>=0;y--) {
			FOR(x,y) {
				int a=(int)__gcd(1LL*A[x]*A[y],(ll)K);
				ret += num[K/a];
			}
			
			auto v=enumdiv(A[y]);
			FORR(r,v) num[r]++;
		}
		return (int)ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {31, 1, 3, 7, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 1; verify_case(0, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 5, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2; verify_case(1, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100000000, 100000000, 100000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arg2 = 1; verify_case(2, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {269, 154, 94, 221, 171, 154, 50, 210, 258, 358, 121, 159, 8, 47, 290, 125, 291, 293, 338, 248, 295, 160, 268, 227, 99, 4, 273}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 360; int Arg2 = 114; verify_case(3, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 220; verify_case(4, Arg2, solveProblem(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AnArray ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
