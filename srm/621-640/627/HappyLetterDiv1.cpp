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

class HappyLetterDiv1 {
	public:
	int num[26];
	
	int okok() {
		int i,sum=0,ma=0;
		FOR(i,26) sum+=num[i],ma=max(ma,num[i]);
		if(sum%2) return 0;
		if(ma*2>sum) return 0;
		return 1;
	}
	
	string getHappyLetters(string letters) {
		int L=letters.size();
		string res="";
		int i,j;
		
		ZERO(num);
		FOR(i,L) num[letters[i]-'a']++;
		FOR(i,26) if(num[i]) {
			int ok=0;
			for(j=1;j<=num[i];j++) {
				num[i]-=j;
				ok|=okok();
				num[i]+=j;
			}
			if(ok) res+='a'+i;
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  HappyLetterDiv1 ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
