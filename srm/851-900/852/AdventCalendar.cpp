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

class AdventCalendar {
	public:
	vector <string> eat(vector <string> calendar) {
		vector<int> V;
		FORR(S,calendar) {
			int i,N=S.size();
			FOR(i,N) if(S[i]>='1'&&S[i]<='9') {
				if(i+1<N&&S[i+1]!=' ') {
					V.push_back((S[i]-'0')*10+S[i+1]-'0');
					i++;
				}
				else {
					V.push_back((S[i]-'0'));
				}
			}
		}
		sort(ALL(V));
		FORR(S,calendar) {
			int i,N=S.size();
			FOR(i,N) if(S[i]>='1'&&S[i]<='9') {
				if(i+1<N&&S[i+1]!=' ') {
					if((S[i]-'0')*10+S[i+1]-'0'==V[0]) {
						S[i]=S[i+1]='X';
					}
					i++;
				}
				else {
					if((S[i]-'0')==V[0]) {
						S[i]='X';
					}
				}
			}
		}
		return calendar;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"19     9        2   24  10 ",
 "  1       18     7 3       11",
 " 20   21 4    17       16    23",
 "  14         12      6    5      ",
 "      8    22     13        15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"19     9        2   24  10 ", "  X       18     7 3       11", " 20   21 4    17       16    23", "  14         12      6    5      ", "      8    22     13        15" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, eat(Arg0)); }
	void test_case_1() { string Arr0[] = {"19     9        X   24  10 ",
 "  X       18     7 3       11",
 " 20   21 4    17       16    23",
 "  14         12      6    5      ",
 "      8    22     13        15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"19     9        X   24  10 ", "  X       18     7 X       11", " 20   21 4    17       16    23", "  14         12      6    5      ", "      8    22     13        15" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, eat(Arg0)); }
	void test_case_2() { string Arr0[] = {"X X X X X X X X X XX XX XX XX XX",
 "XX XX 17 18 19 20 21 22 23 24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X X X X X X X X X XX XX XX XX XX", "XX XX XX 18 19 20 21 22 23 24" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, eat(Arg0)); }
	void test_case_3() { string Arr0[] = {"X X X X X X X X X XX XX XX XX XX",
 "17 XX XX 18 19 20 21 22 23 24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X X X X X X X X X XX XX XX XX XX", "XX XX XX 18 19 20 21 22 23 24" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, eat(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AdventCalendar ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

