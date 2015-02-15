#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class BracketExpressions {
	public:
	int L;
	string S,S2;
	
	bool check() {
		stack<char> ST;
		ITR(it,S2) {
			char ch=ST.empty()?'*':ST.top();
			if((ch=='(' && *it==')') || (ch=='[' && *it==']') || (ch=='{' && *it=='}')) ST.pop();
			else ST.push(*it);
		}
		return ST.empty();
		
	}
	
	bool dfs(int cur) {
		if(cur==L) return check();
		if(S[cur]=='X') {
			bool ret=false;
			string s="()[]{}";
			ITR(it,s) S2[cur]=*it, ret |= dfs(cur+1);
			return ret;
		}
		else return dfs(cur+1);
	}
	
	string ifPossible(string expression) {
		S=S2=expression;
		L=S.size();
		return dfs(0)?"possible":"impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  BracketExpressions ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
