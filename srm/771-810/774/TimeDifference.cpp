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

class TimeDifference {
	public:
	string calculate(string startTime, string endTime) {
		ll v=0;
		FORR(c,endTime) {
			if(c==':') break;
			else v=v*10+c-'0';
		}
		ll w=0;
		FORR(c,startTime) {
			if(c==':') break;
			else w=w*10+c-'0';
		}
		v=v*60+(endTime[endTime.size()-2]-'0')*10+(endTime[endTime.size()-1]-'0');
		w=w*60+(startTime[startTime.size()-2]-'0')*10+(startTime[startTime.size()-1]-'0');
		cout<<v<<" "<<w<<endl;
		v-=w;
		char buf[101];
		string si;
		if(v<0) {
			si="-";
			v=-v;
		}
		sprintf(buf, "%d:%02d",v/60,v%60);
		return si+buf;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:00"; string Arg1 = "13:23"; string Arg2 = "13:23"; verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "100:15"; string Arg1 = "13:23"; string Arg2 = "-86:52"; verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "001:00"; string Arg1 = "8:15"; string Arg2 = "7:15"; verify_case(2, Arg2, calculate(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "123:45"; string Arg1 = "543:21"; string Arg2 = "419:36"; verify_case(3, Arg2, calculate(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "111:11"; string Arg1 = "222:12"; string Arg2 = "111:01"; verify_case(4, Arg2, calculate(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "10:42"; string Arg1 = "10:47"; string Arg2 = "0:05"; verify_case(5, Arg2, calculate(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "10:47"; string Arg1 = "010:47"; string Arg2 = "0:00"; verify_case(6, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TimeDifference ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

