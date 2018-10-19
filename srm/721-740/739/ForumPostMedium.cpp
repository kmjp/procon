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

class ForumPostMedium {
	public:
	int conv(string s) {
		int h=(s[0]-'0')*10+(s[1]-'0');
		int m=(s[3]-'0')*10+(s[4]-'0');
		int e=(s[6]-'0')*10+(s[7]-'0');
		return h*3600+m*60+e;
	}
	string getShownPostTime(string currentTime, string exactPostTime) {
		int A=conv(currentTime);
		int B=conv(exactPostTime);
		if(A<B) A+=24*60*60;
		
		if(A-B<60) {
			return "few seconds ago";
		}
		else if(A-B<60*60) {
			char buf[50];
			sprintf(buf, "%d minutes ago", (A-B)/60);
			return string(buf);
		}
		else {
			char buf[50];
			sprintf(buf, "%d hours ago", (A-B)/3600);
			return string(buf);
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12:12:12"; string Arg1 = "12:11:13"; string Arg2 = "few seconds ago"; verify_case(0, Arg2, getShownPostTime(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "12:12:12"; string Arg1 = "11:12:12"; string Arg2 = "1 hours ago"; verify_case(1, Arg2, getShownPostTime(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12:12:12"; string Arg1 = "11:12:13"; string Arg2 = "59 minutes ago"; verify_case(2, Arg2, getShownPostTime(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "12:12:12"; string Arg1 = "12:12:13"; string Arg2 = "23 hours ago"; verify_case(3, Arg2, getShownPostTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ForumPostMedium ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

