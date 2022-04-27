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


class ShortShortSuperstring {
	public:
	vector <string> constructAll(string A, string B, string C) {
		vector<string> R={"...................."};
		int a=A.size(),b=B.size(),c=C.size();
		int x,y,z,i;
		
		FOR(x,11) FOR(y,11) FOR(z,11) {
			string S="...................";
			FOR(i,a) {
				if(S[i+x]=='.') S[i+x]=A[i];
				if(S[i+x]!=A[i]) break;
			}
			if(i<a) continue;
			FOR(i,b) {
				if(S[i+y]=='.') S[i+y]=B[i];
				if(S[i+y]!=B[i]) break;
			}
			if(i<b) continue;
			FOR(i,c) {
				if(S[i+z]=='.') S[i+z]=C[i];
				if(S[i+z]!=C[i]) break;
			}
			if(i<c) continue;
			while(S.back()=='.') S.pop_back();
			if(R[0].size()>S.size()) R={S};
			if(R[0].size()==S.size()) R.push_back(S);
		}
		
		sort(ALL(R));
		R.erase(unique(ALL(R)),R.end());
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "ef"; string Arg2 = "cd"; string Arr3[] = {"abcdef", "abefcd", "cdabef", "cdefab", "efabcd", "efcdab" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, constructAll(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "aaa"; string Arg2 = "aa"; string Arr3[] = {"aaa" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, constructAll(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaa"; string Arg1 = "aaa"; string Arg2 = "aaa"; string Arr3[] = {"aaa" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, constructAll(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aab"; string Arg1 = "aaaa"; string Arg2 = "caa"; string Arr3[] = {"caaaab" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, constructAll(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "hello"; string Arg1 = "oxbow"; string Arg2 = "watch"; string Arr3[] = {"helloxbowatch", "oxbowatchello", "watchelloxbow" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, constructAll(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShortShortSuperstring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

