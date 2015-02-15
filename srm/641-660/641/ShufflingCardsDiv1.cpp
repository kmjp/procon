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

int memo[2001];
class ShufflingCardsDiv1 {
	public:
	int N,zm;
	
	void dfs(int zen,int d) {
		memo[zen]=d;
		int zen2=N/2-zm;
		int mi=max(0,zen-(N/2-zm))+max(0,zen2-zm);
		int ma=min(zen,zm)+min(zen2,N/2-zm);
		for(int i=mi;i<=ma;i++) if(memo[i]>d+1) dfs(i,d+1);
	}
	
	
	int shuffle(vector <int> P) {
		int i,ret;
		N=P.size();
		
		int ok=1,ok2=1;
		FOR(i,N) if(P[i]!=i+1) ok=0;
		if(ok==1) return 0;
		FOR(i,N) if((P[i]<=N/2) ^ (i%2==0)) ok2=0;
		if(ok2==1) return 1;
		
		FOR(i,2000) memo[i]=2000;
		
		zm=((N/2)+1)/2;
		dfs(zm,1);
		
		int zen=0;
		FOR(i,N/2) if(P[i*2]<=N/2) zen++;
		return memo[zen]+1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {6,3,5,2,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {8,5,4,9,1,7,6,10,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {9,1,7,2,10,3,6,4,8,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, shuffle(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShufflingCardsDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
