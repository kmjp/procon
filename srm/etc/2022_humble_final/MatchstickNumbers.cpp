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

ll num[11][100];

int M[]={6,2,5,5,4,5,6,3,7,6};


class MatchstickNumbers {
	public:
	string index(int N) {
		ZERO(num);
		N++;
		num[0][0]=1;
		int i,d,c;
		FOR(i,10) {
			FOR(c,80) {
				FOR(d,10) num[i+1][c+M[d]]+=num[i][c];
			}
		}
		for(i=0;i<=90;i++) {
			if(N>num[9][i]) {
				N-=num[9][i];
				continue;
			}
			
			int lef=i;
			string R;
			FOR(i,9) {
				FOR(d,10) if(M[d]<=lef) {
					if(N>num[8-i][lef-M[d]]) {
						N-=num[8-i][lef-M[d]];
					}
					else {
						R+='0'+d;
						lef-=M[d];
						break;
					}
				}
			}
			return R;
		}
		return "";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; string Arg1 = "111111111"; verify_case(0, Arg1, index(Arg0)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "111117111"; verify_case(1, Arg1, index(Arg0)); }
	void test_case_2() { int Arg0 = 10; string Arg1 = "111111114"; verify_case(2, Arg1, index(Arg0)); }
	void test_case_3() { int Arg0 = 12; string Arg1 = "111111177"; verify_case(3, Arg1, index(Arg0)); }
	void test_case_4() { int Arg0 = 999999993; string Arg1 = "888889888"; verify_case(4, Arg1, index(Arg0)); }
	void test_case_5() { int Arg0 = 123456789; string Arg1 = "418035721"; verify_case(5, Arg1, index(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MatchstickNumbers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

