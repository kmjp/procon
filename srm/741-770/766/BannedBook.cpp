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

class BannedBook {
	public:
	vector<string> F;
	vector<int> R;
	int vis[51];
	
	void dfs(int cur,int d) {
		if(vis[cur]) return;
		vis[cur]=1;
		if(d==0) R.push_back(cur);
		int i;
		FOR(i,F.size()) if(F[cur][i]=='Y' && vis[i]==0) dfs(i,d^1);
		if(d) R.push_back(cur);
	}
	
	vector <int> passAround(vector <string> F) {
		this->F=F;
		ZERO(vis);
		R.clear();
		int i;
		FOR(i,F.size()) if(vis[i]==0) dfs(i,0);
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"YNN",
 "NYN",
 "NNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, passAround(Arg0)); }
	void test_case_1() { string Arr0[] = {"YYYYY",
 "YYNNN",
 "YNYNN",
 "YNNYN",
 "YNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, passAround(Arg0)); }
	void test_case_2() { string Arr0[] = {"YYNNN",
 "YYYNN",
 "NYYYN",
 "NNYYY",
 "NNNYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 4, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, passAround(Arg0)); }
	void test_case_3() { string Arr0[] = {"YYNNYNYNN", 
 "YYNNNYNNN", 
 "NNYNNNNNN", 
 "NNNYNNNNN", 
 "YNNNYNNNY", 
 "NYNNNYNYN", 
 "YNNNNNYNY", 
 "NNNNNYNYN", 
 "NNNNYNYNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 5, 7, 1, 8, 6, 4, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, passAround(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BannedBook ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

