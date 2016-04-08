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

class Quacking {
	public:
	int quack(string s) {
		int ret=0,i,j;
		
		FOR(i,600) {
			int is=0,status=0;
			vector<int> p;
			FOR(j,s.size()) {
				if(status==0 && s[j]=='q') status++, p.push_back(j);
				if(status==1 && s[j]=='u') status++, p.push_back(j);
				if(status==2 && s[j]=='a') status++, p.push_back(j);
				if(status==3 && s[j]=='c') status++, p.push_back(j);
				if(status==4 && s[j]=='k') {
					status=0;
					s[j]='*';
					FORR(rr,p) s[rr]='*';
					p.clear();
					is=1;
				}
			}
			ret+=is;
		}
		FORR(r,s) if(r!='*') return -1;
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "quqacukqauackck"; int Arg1 = 2; verify_case(0, Arg1, quack(Arg0)); }
	void test_case_1() { string Arg0 = "kcauq"; int Arg1 = -1; verify_case(1, Arg1, quack(Arg0)); }
	void test_case_2() { string Arg0 = "quackquackquackquackquackquackquackquackquackquack"; int Arg1 = 1; verify_case(2, Arg1, quack(Arg0)); }
	void test_case_3() { string Arg0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"; int Arg1 = 10; verify_case(3, Arg1, quack(Arg0)); }
	void test_case_4() { string Arg0 = "quqaquuacakcqckkuaquckqauckack"; int Arg1 = 3; verify_case(4, Arg1, quack(Arg0)); }
	void test_case_5() { string Arg0 = "quackqauckquack"; int Arg1 = -1; verify_case(5, Arg1, quack(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Quacking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
