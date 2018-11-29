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

int N,L;
double dp[1<<15][55];
int table[16][55];
int num[16][55];
string S;

class RandomConcat {
	public:
	void create_table(int id,string T) {
		
		for(int cur=0;cur<=S.size();cur++) {
			string U=S.substr(0,cur);
			FORR(t,T) {
				U+=t;
				while(U.size()>S.size()) U.erase(U.begin());
				while(U!=S.substr(0,U.size())) U.erase(U.begin());
				if(U.size()==S.size()) num[id][cur]++;
			}
			table[id][cur]=U.size();
		}
		
	}
	
	double expectation(vector <string> pieces, string needle) {
		N=pieces.size();
		S=needle;
		int i,j;
		ZERO(table);
		ZERO(num);
		FOR(i,N) create_table(i,pieces[i]);
		
		double ret=0;
		ZERO(dp);
		dp[(1<<N)-1][0]=1;
		for(int mask=(1<<N)-1;mask>0;mask--) {
			FOR(i,S.size()+1) if(dp[mask][i]>0) {
				double cand=dp[mask][i]/__builtin_popcount(mask);
				FOR(j,N) if(mask&(1<<j)) {
					ret+=cand*num[j][i];
					dp[mask^(1<<j)][table[j][i]]+=cand;
				}
			}
		}
		
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hahaha"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aha"; double Arg2 = 2.0; verify_case(0, Arg2, expectation(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"hah","ah"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aha"; double Arg2 = 0.5; verify_case(1, Arg2, expectation(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"t","o","p","c","o","d","e","r"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "topcoder"; double Arg2 = 4.9603174603174596E-5; verify_case(2, Arg2, expectation(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"hellotopc","oderhellotop","coderbye"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "topcoder"; double Arg2 = 0.6666666666666666; verify_case(3, Arg2, expectation(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"aabaa","aabaaaaa","aba","goodluck","havefun"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaa"; double Arg2 = 2.8000000000000016; verify_case(4, Arg2, expectation(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"a","a","aa","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aba"; double Arg2 = 0.5; verify_case(5, Arg2, expectation(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomConcat ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

