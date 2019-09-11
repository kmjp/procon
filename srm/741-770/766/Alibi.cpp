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

class Alibi {
	public:
	string findMurderer(string murderRoom, int murderTime, vector <int> eventTime, vector <string> eventPerson, vector <string> eventRoom) {
		map<string,string> R;
		vector<string> C={ "White", "Green", "Peacock", "Plum", "Scarlett","Mustard"};
		FORR(c,C) R[c]="Hall";
		
		int i;
		FOR(i,eventTime.size()) {
			if(eventTime[i]>murderTime) break;
			R[eventPerson[i]]=eventRoom[i];
		}
		
		vector<string> V;
		FORR(c,C) if(R[c]==murderRoom) V.push_back(c);
		if(V.size()==1) return V[0];
		return "";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Library"; int Arg1 = 10; int Arr2[] = { 5, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "Plum", "Scarlett", "Plum" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "Library", "Library", "Cellar" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Scarlett"; verify_case(0, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arg0 = "Library"; int Arg1 = 10; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = ""; verify_case(1, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arg0 = "Library"; int Arg1 = 8; int Arr2[] = { 5, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "Plum", "Scarlett", "Plum" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "Library", "Library", "Cellar" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = ""; verify_case(2, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arg0 = "Hall"; int Arg1 = 11; int Arr2[] = { 2, 4, 6, 8, 10, 12 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "White", "Green", "Peacock", "Plum", "Scarlett", "Mustard" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "Kitchen", "Ballroom", "Conservatory", "Library", "Lounge", "Study" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Mustard"; verify_case(3, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arg0 = "Library"; int Arg1 = 10; int Arr2[] = {3, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"Plum", "Plum"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"Library", "Library"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Plum"; verify_case(4, Arg5, findMurderer(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Alibi ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

