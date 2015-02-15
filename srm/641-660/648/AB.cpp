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

class AB {
	public:
	string createString(int N, int K) {
		int i,j,k;
		for(int na=0;na<=N;na++) {
			int nb=N-na;
			if(na*nb<K) continue;
			k=K;
			vector<int> V;
			FOR(i,na) {
				int x=min(nb,K);
				V.push_back(x);
				K-=x;
			}
			string S;
			for(int x=nb;x>=0;x--) {
				FOR(j,V.size()) if(V[j]==x) S+="A";
				if(x) S+="B";
			}
			return S;
			
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "ABB"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 0; string Arg2 = "BA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 8; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 12; string Arg2 = "BAABBABAAB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AB ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
