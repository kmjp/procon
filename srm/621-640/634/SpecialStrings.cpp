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

class SpecialStrings {
	public:
	string S,goal;
	string next(string s) {
		int i;
		for(i=s.size()-1;i>=0;i--) {
			s[i]++;
			if(s[i]<='1') break;
			s[i]='0';
		}
		return s;
	}
	bool issp(string s) {
		int i,L=s.size();
		for(i=1;i<L;i++) if(s.substr(0,i)>=s.substr(i)) return false;
		return true;
	}
	void dfs(string cur) {
		if(cur.size()==S.size()) {
			if(goal>cur && issp(cur)) goal=cur;
			return;
		}
		
		string n=cur+"01111111111111111111111111111111111111111111111111111111";
		n=n.substr(0,S.size());
		if(n.substr(0,cur.size()+1)>=S.substr(0,cur.size()+1)) {
			if(issp(n)) {
				dfs(cur+"0");
				return;
			}
		}
		dfs(cur+"1");
	}
	
	string findNext(string s) {
		if(s=="1") return "";
		S=next(s);
		goal="11111111111111111111111111111111111111111111111111111";
		dfs("");
		if(goal.size()>50) return "";
		return goal;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
	void test_case_4() { string Arg0 = "01101111011110111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SpecialStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
