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

class HungryCowsMedium {
	int N,M;
	vector<int> C,P;
	public:
	
	int ok(ll v) {
		vector<ll> T;
		FORR(p,P) if(v>p) T.push_back(v-p);
		
		FORR(c,C) {
			int ok=0;
			FORR(t,T) if(t>=c) ok=1;
			if(ok==0) return 0;
			
			ll a=c;
			FORR(t,T) {
				ll d=min(t,a);
				t-=d;
				a-=d;
			}
		}
		return 1;
	}
	
	
	long long getWellFedTime(vector <int> A, vector <int> B) {
		C=A;
		P=B;
		sort(ALL(C));
		reverse(ALL(C));
		sort(ALL(P));
		
		ll ret=(1LL<<50)-1;
		for(int i=49;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8LL; verify_case(0, Arg2, getWellFedTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5LL; verify_case(1, Arg2, getWellFedTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(2, Arg2, getWellFedTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(2, Arg2, getWellFedTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HungryCowsMedium ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

