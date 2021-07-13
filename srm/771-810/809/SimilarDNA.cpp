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

class SimilarDNA {
	public:
	
	vector<string> edit(string S) {
		vector<string> ret={S};
		int i,j;
		FOR(i,S.size()) {
			//del
			string T=S;
			T.erase(T.begin()+i);
			ret.push_back(T);
			//edit
			T=S;
			FOR(j,26) {
				T[i]='A'+j;
				ret.push_back(T);
			}
		}
		FOR(i,S.size()+1) {
			FOR(j,26) {
				char c='A'+j;
				string T=S.substr(0,i)+c+S.substr(i);
				ret.push_back(T);
			}
		}
		return ret;
	}
	
	string areSimilar(string A, string B) {
		vector<string> a=edit(A);
		FORR(s,a) {
			vector<string> t=edit(s);
			if(count(ALL(t),B)) return "similar";
		}
		return "distinct";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAA"; string Arg1 = "AACAACA"; string Arg2 = "similar"; verify_case(0, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AACAACA"; string Arg1 = "AAAAA"; string Arg2 = "similar"; verify_case(1, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AACAACA"; string Arg1 = "AAGAATA"; string Arg2 = "similar"; verify_case(2, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CGATCGAT"; string Arg1 = "CATCGAG"; string Arg2 = "similar"; verify_case(3, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CGATCGAT"; string Arg1 = "CGATCGAT"; string Arg2 = "similar"; verify_case(4, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CGATATATAGGA"; string Arg1 = "GGATATACCATA"; string Arg2 = "distinct"; verify_case(5, Arg2, areSimilar(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "AAAAA"; string Arg1 = "AA"; string Arg2 = "distinct"; verify_case(6, Arg2, areSimilar(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimilarDNA ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

