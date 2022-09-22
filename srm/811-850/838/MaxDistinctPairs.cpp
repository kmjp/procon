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

class MaxDistinctPairs {
	public:
	string maximize(int N, string P) {
		int L=P.size();
		int i,j;
		if(N>=3) {
			FOR(i,L) if(P[i]=='.') {
				P[i]='A';
				while(1) {
					if(i&&P[i-1]==P[i]) {
						P[i]++;
						continue;
					}
					if(i<L-1&&P[i+1]==P[i]) {
						P[i]++;
						continue;
					}
					break;
				}
			}
		}
		else if(N==1) {
			P=string(L,'A');
		}
		else {
			FOR(i,L) if(P[i]!='.') break;
			if(i==L) {
				FOR(i,L) P[i]='A'+(i%2);
			}
			else {
				for(j=i-1;j>=0;j--) P[j]='A'+'B'-P[j+1];
				for(j=i+1;j<L;j++) if(P[j]=='.') P[j]='A'+'B'-P[j-1];
			}
		}
		return P;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; string Arg1 = "........"; string Arg2 = "ABABABAB"; verify_case(0, Arg2, maximize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; string Arg1 = "..A.A..A"; string Arg2 = "AAAAAAAA"; verify_case(1, Arg2, maximize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "A....FA....F"; string Arg2 = "ABCDEFABCDEF"; verify_case(2, Arg2, maximize(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; string Arg1 = "B.A"; string Arg2 = "BAA"; verify_case(3, Arg2, maximize(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; string Arg1 = ""; string Arg2 = ""; verify_case(4, Arg2, maximize(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaxDistinctPairs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

