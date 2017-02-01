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

class MazeConstruct {
	public:
	vector <string> construct(int k) {
		vector<string> R;
		if(k<49) {
			R.push_back(string(k+1,'.'));
		}
		else if(k<=98) {
			R.push_back(string(50,'.'));
			k-=49;
			while(k) R.push_back(string(49,'#')+"."),k--;
		}
		else {
			R.push_back(string(50,'.'));
			R.push_back(string(49,'#')+".");
			k-=50;
			while(k>=102) {
				R.push_back(string(50,'.'));
				R.push_back("."+string(49,'#'));
				R.push_back(string(50,'.'));
				R.push_back(string(49,'#')+".");
				k-=102;
			}
			if(k>=4) {
				int w=(k-1)/2;
				R.push_back(string(50-w,'#')+string(w,'.'));
				R.push_back(string(50-w,'#')+"."+string(w-1,'#'));
				R.push_back(string(50-w,'#')+string(w,'.'));
				k-=w*2+1;
			}
			while(k--) R.push_back(string(49,'#')+".");
		}
		int tot=-1;
		FORR(r,R) FORR(c,r) tot+=c=='.';
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {"...", "...", "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 567; string Arr1[] = {"..#..", "#.#..", "..#..", ".#...", "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MazeConstruct ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

