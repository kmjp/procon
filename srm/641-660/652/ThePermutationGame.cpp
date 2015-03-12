#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;

map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	if(n==1) V[1]=1;
	else {
		for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
		if(n>1) V[n]++;
	}
	return V;
}

class ThePermutationGame {
	public:
	int findMin(int N) {
		int i;
		map<ll,int> M;
		
		for(i=2;i<=N;i++) {
			map<ll,int> MM=enumdiv(i);
			ITR(it,MM) M[it->first]=max(M[it->first],it->second);
		}
		
		ll ret=1;
		ITR(it,M) {
			FOR(i,it->second) ret=ret*it->first%mo;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 6; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 504; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 102; int Arg1 = 841777601; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 9999; int Arg1 = 804862568; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThePermutationGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
