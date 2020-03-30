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

class TrivialWordSearch {
	public:
	vector <string> construct(string w) {
		if(w.size()==1) return {w};
		if(w.size()==2) return {};
		int i,j,x,y;
		for(i=1;i<w.size();i++) if(w[i]!=w[0]) {
			vector<string> V;
			FOR(j,w.size()) V.push_back(w);
			if(i>=2) {
				for(y=1;y<w.size();y++) FOR(x,w.size()) V[y][x]=w[i];
			}
			else {
				for(y=1;y<w.size();y++) FOR(x,w.size()) V[y][x]=w[0];
			}
			return V;
		}
		return {};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "DOG"; string Arr1[] = {"DGOODDO", "DODGOGG", "DGOODDD", "GOOGDGO", "GOGGOGD", "DOOGDOO", "OOGGOOD" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "ABBA"; string Arr1[] = {"BABA", "AABB", "ABAA", "ABAB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "TOPCODER"; string Arr1[] = {"TOPTOPTOPTOP", "TOPTORTOPTOP", "TOPTOETOPTOP", "TOPTODTOPTOP", "TOPTOOTOPTOP", "TOPTOCTOPTOP", "TOPTOPTOPTOP", "TOPTOOTOPTOP", "TOPTOTTOPTOP", "TOPTOPTOPTOP", "TOPTOPTOPOOP", "TOPTOPTOPTOP" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "XXXXX"; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "E"; string Arr1[] = {"E" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TrivialWordSearch ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

