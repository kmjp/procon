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

class OpenAllHours {
	public:
	string verify(int N, vector <string> openingTime, vector <string> closingTime) {
		int ok[3600]={};
		int i;
		FOR(i,N) {
			int s=0,t=0;
			s+=(openingTime[i][0]-'0')*10*60;
			s+=(openingTime[i][1]-'0')*1*60;
			s+=(openingTime[i][3]-'0')*1*10;
			s+=(openingTime[i][4]-'0')*1*1;
			t+=(closingTime[i][0]-'0')*10*60;
			t+=(closingTime[i][1]-'0')*1*60;
			t+=(closingTime[i][3]-'0')*1*10;
			t+=(closingTime[i][4]-'0')*1*1;
			while(s!=t) {
				ok[s]=1;
				s++;
				if(s>=1440) s=0;
			}
		}
		if(count(ok,ok+1440,0)==0) {
			return "correct";
		}
		else {
			return "incorrect";
		}
		
			
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"04:47","16:47"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"16:47","04:47"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "correct"; verify_case(0, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"03:00", "18:30", "08:59"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"09:00", "04:15", "19:01"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "correct"; verify_case(1, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"03:47", "03:48", "03:49"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"03:44", "03:45", "03:46"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "incorrect"; verify_case(2, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; string Arr1[] = {"05:00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"04:59"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "incorrect"; verify_case(3, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; string Arr1[] = {"01:08", "12:46", "23:28", "20:30", "19:02", "06:41"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"05:56", "18:53", "02:29", "23:26", "23:57", "08:44"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "incorrect"; verify_case(4, Arg3, verify(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 7; string Arr1[] = {"01:12", "11:23", "12:23", "13:05", "18:26", "08:37", "22:08"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"03:21", "13:04", "22:16", "21:46", "08:19", "10:17", "13:01"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "correct"; verify_case(5, Arg3, verify(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OpenAllHours ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

