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

class HorseRacing {
	public:
	int validateTicket(vector <string> races, string ticket) {
		string T;
		FORR(r,races) T+=r;
		int ret=0;
		vector<pair<int,int>> pos;
		FORR(c,ticket) {
			pair<int,int> p={-1,-1};
			pos.push_back({-1,-1});
			int x,y;
			FOR(x,races.size()) {
				FOR(y,races[x].size()) {
					if(races[x][y]==c) p={x,y};
				}
			}
			if(p.first==-1) return -1;
			if(p.second==0) ret++;
			
			FORR(v,pos) if(v.first==p.first) return -1;
			pos.push_back(p);
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AbX", "CdeF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AC"; int Arg2 = 2; verify_case(0, Arg2, validateTicket(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AbX", "CdeF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CA"; int Arg2 = 2; verify_case(1, Arg2, validateTicket(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AbX", "CdeF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Cb"; int Arg2 = 1; verify_case(2, Arg2, validateTicket(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AbX", "CdeF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "X"; int Arg2 = 0; verify_case(3, Arg2, validateTicket(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"AbX", "CdeF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "HelloTopcoder"; int Arg2 = -1; verify_case(4, Arg2, validateTicket(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"a", "b", "c", "d", "e", "f"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bead"; int Arg2 = 4; verify_case(5, Arg2, validateTicket(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HorseRacing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

