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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int from[26][2];
int to[26][2];

class EllysTwinLetters {
	public:
	int getMin(string S) {
		int i,j;
		FOR(i,26) {
			from[i][0]=abs((S[0]-'A')-i);;
			from[i][1]=1000000;
		}
		
		S.erase(S.begin());
		FORR(c,S) {
			FOR(i,26) to[i][0]=to[i][1]=1000000;
			FOR(i,26) {
				FOR(j,26) {
					if(i==j) {
						to[i][1]=min(to[i][1],from[j][0]+abs((c-'A')-i));
						to[i][1]=min(to[i][1],from[j][1]+abs((c-'A')-i));
					}
					else {
						to[i][0]=min(to[i][0],from[j][1]+abs((c-'A')-i));
					}
				}
			}
				
			
			swap(from,to);
		}
		
		int ret=10000000;
		FOR(i,26) ret=min(ret,from[i][1]);
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPCODER"; int Arg1 = 30; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg1 = 13; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "ESPRIT"; int Arg1 = 25; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "WITHOUTITIMJUSTESPR"; int Arg1 = 54; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "NOZAPHODJUSTVERYVERYIMPROBABLE"; int Arg1 = 93; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { string Arg0 = "FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST"; int Arg1 = 111; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTwinLetters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

