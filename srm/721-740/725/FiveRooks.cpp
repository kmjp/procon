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

class FiveRooks {
	public:
	int B[8][8];
	
	vector<int> dfs(int y,vector<int>& V,int mask) {
		if(V.size()==10) return V;
		if(y==8) {
			return vector<int>();
		}
		
		vector<int> R;
		R=dfs(y+1,V,mask);
		if(R.size()) return R;
		
		int x;
		FOR(x,8) if(B[y][x] && (mask&(1<<x))==0) {
			V.push_back(y);
			V.push_back(x);
			R=dfs(y+1,V,mask|(1<<x));
			V.pop_back();
			V.pop_back();
			if(R.size()) return R;
		}
		return R;
		
	}
	
	vector <int> find(vector <string> board) {
		int mask[8]={};
		int y,x;
		FOR(y,8) {
			FOR(x,8) B[y][x]=board[y][x]=='R';
		}
		vector<int> V;
		return dfs(0,V,0);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"R.......",
"........",
"........",
"........"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.RRR.R",
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.R.R.R"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRR....",
"RRR....."
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRRRRRR",
".RRRRRR."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { string Arr0[] = 
{
".RRRRRR.",
"RRRRRRRR",
".RRRR...",
"..RRRR..",
"...RRRR.",
"....RRRR",
"RRRRRRRR",
".RRRRRR."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, find(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FiveRooks ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

