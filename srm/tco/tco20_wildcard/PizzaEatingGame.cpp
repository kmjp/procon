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

int N;
int memo[1010][1010];
int S[1010];

class PizzaEatingGame {
	public:
	int hoge(int L,int R) {
		if(L>=R) return 0;
		if(memo[L][R]>=0) return memo[L][R];
		int ma=0;
		int sum=S[R]-S[L];
		for(int i=L;i<R;i++) ma=max(ma,sum-hoge(L,i)-hoge(i+1,R));
		
		return memo[L][R]=ma;
		
	}
	
	int eat(vector <int> olives) {
		int N=olives.size();
		MINUS(memo);
		int i;
		FOR(i,N) olives.push_back(olives[i]);
		FOR(i,2*N) S[i+1]=S[i]+olives[i];
		int ma=0;
		FOR(i,N) ma=max(ma,S[N]-hoge(i,i+N-1));
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 1, 100, 1, 2, 1, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 104; verify_case(0, Arg1, eat(Arg0)); }
	void test_case_1() { int Arr0[] = {99, 5, 6, 5, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 110; verify_case(1, Arg1, eat(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, eat(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PizzaEatingGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

