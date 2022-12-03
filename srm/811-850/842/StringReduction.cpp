#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class StringReduction {
	public:
	int hoge(int S,vector<int> D) {
		int dp[2525]={};
		dp[S]=1;
		
		int mi=S;
		int i;
		for(i=2520;i>=0;i--) if(dp[i]) {
			mi=min(mi,i);
			FORR(d,D) if(d<=i) dp[i-d]=1;
		}
		return mi;
	}
	int reduce(string start, vector <int> X, string Y) {
		int C[26]={};
		vector<int> D[26];
		int i;
		FOR(i,Y.size()) {
			D[Y[i]-'a'].push_back(X[i]-1);
		}
		FORR(c,start) C[c-'a']++;
		
		int ret=0;
		FOR(i,26) if(C[i]) ret+=1+hoge(C[i]-1,D[i]);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abba"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; int Arg3 = 3; verify_case(0, Arg3, reduce(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abba"; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ccdef"; int Arg3 = 4; verify_case(1, Arg3, reduce(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abcde"; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "c"; int Arg3 = 5; verify_case(2, Arg3, reduce(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaaaa"; int Arr1[] = {1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "aaaaa"; int Arg3 = 1; verify_case(3, Arg3, reduce(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "axbcxdefxgxh"; int Arr1[] = {2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abx"; int Arg3 = 10; verify_case(4, Arg3, reduce(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "bbbxbbbx"; int Arr1[] = {3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "bxx"; int Arg3 = 3; verify_case(5, Arg3, reduce(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StringReduction ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

