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

class KthStringAgain {
	public:
	
	ll dpdp(string a,string b) {
		int i,j;
		ll dp[52][52] = {};
		dp[0][0]=1;
		FOR(i,a.size()) {
			FOR(j,i+1) {
				//front
				if(j>=b.size() || (j<b.size() && a[i]==b[j])) dp[i+1][j+1] += dp[i][j];
				//end
				int r=(a.size()-1)-(i-j);
				if(r>=b.size() || (r<b.size() && a[i]==b[r])) dp[i+1][j] += dp[i][j];
			}
		}
		return accumulate(dp[a.size()],dp[a.size()]+a.size()+1,0LL);
	}
	
	string getKth(string s, long long K) {
		string ret;
		int i,j;
		FOR(i,s.size()) {
			FOR(j,26) {
				string tret=ret;
				tret+='a'+j;
				ll t=dpdp(s,tret);
				if(K>t) {
					K-=t;
				}
				else {
					ret=tret;
					break;
				}
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "xyz"; long long Arg1 = 5LL; string Arg2 = "yzx"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abc"; long long Arg1 = 1LL; string Arg2 = "abc"; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abc"; long long Arg1 = 8LL; string Arg2 = "cba"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoder"; long long Arg1 = 58LL; string Arg2 = "ooredcpt"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaabcdeeeghhhhhiijjjkllmmooooqqrrrrssttuuvvvvvwyy"; long long Arg1 = 38517901796974LL; string Arg2 = "aaaacdeehhhijklmmqqrsttvvvvwyyvuusrrrooooljjihhgeb"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KthStringAgain ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
