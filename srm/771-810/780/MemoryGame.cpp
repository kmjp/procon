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

int L[2020202];
int vis[1010101];

class MemoryGame {
	public:
	long long countSteps(int N, int seed) {
		ll s=seed;
		int i;
		ZERO(vis);
		
		FOR(i,2*N) L[i]=i/2;
		
		for(i=2*N-1;i>=1;i--) {
			int j=s%(i+1);
			swap(L[i],L[j]);
			s=(s*1103515245+12345)%(1LL<<31);
		}
		
		int num=0;
		set<int> unk,kn;
		FOR(i,2*N) unk.insert(i);
		while(unk.size()) {
			num++;
			int x=*unk.begin();
			unk.erase(unk.begin());
			if(vis[L[x]]) {
				vis[L[x]]=0;
				continue;
			}
			vis[L[x]]=1;
			
			int y=*unk.begin();
			unk.erase(unk.begin());
			if(L[x]==L[y]) {
				vis[L[x]]=0;
				continue;
			}
			if(vis[L[y]]) {
				num++;
				vis[L[y]]--;
				continue;
			}
			vis[L[y]]=1;
			
		}
		return num;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 47; long long Arg2 = 1LL; verify_case(0, Arg2, countSteps(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 47474747; long long Arg2 = 2LL; verify_case(1, Arg2, countSteps(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 42; long long Arg2 = 3LL; verify_case(2, Arg2, countSteps(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 123456; long long Arg2 = 12LL; verify_case(3, Arg2, countSteps(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 100; long long Arg2 = 166LL; verify_case(4, Arg2, countSteps(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MemoryGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

