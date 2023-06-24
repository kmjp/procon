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

class EraseThird {
	public:
	vector <string> erase(string S) {
		
		FORR(c,S) c-='a';
		vector<string> V;
		int i;
		FOR(i,26) {
			int cur=0;
			FOR(cur,S.size()) if(S[cur]==i) break;
			if(cur==S.size()) {
				V.push_back("NO");
				continue;
			}
			int L=0,R=S.size();
			string ret;
			while(L+1<R) {
				int a=(R-L+2)/3;
				if(cur<L+a) {
					ret+="3";
					R-=a;
				}
				else {
					ret+="1";
					L+=a;
				}
				
			}
			V.push_back(ret);
		}
		
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arr1[] = {"NO", "NO", "1233", "1321", "1113", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "1231", "3123", "NO", "1111", "NO", "3233", "NO", "NO", "NO", "NO", "NO", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, erase(Arg0)); }
	void test_case_1() { string Arg0 = "x"; string Arr1[] = {"NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "", "NO", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, erase(Arg0)); }
	void test_case_2() { string Arg0 = "qwertyuiopasdfghjkl"; string Arr1[] = {"131233", "NO", "NO", "113231", "232133", "113123", "111233", "111231", "133233", "111123", "111113", "111111", "NO", "NO", "133231", "133123", "232333", "231333", "113233", "231331", "212331", "NO", "232331", "NO", "212333", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, erase(Arg0)); }
	void test_case_3() { string Arg0 = "aaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa"; string Arr1[] = {"1111111", "1213333", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, erase(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EraseThird ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

