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

class Pancakes {
	public:
	vector <string> makePancakes(int N, int P) {
		vector <string> R;
		int i;
		if(N<P) {
			string S(P,'-');
			FOR(i,N) S[i]='A'+i;
			R.push_back(S);
			FOR(i,N) S[i]='a'+i;
			R.push_back(S);
		}
		else {
			string S;
			FOR(i,N) S+='A'+i;
			FOR(i,N) S+='a'+i;
			int cur=0;
			while(cur<2*N) {
				string T;
				FOR(i,P) {
					if(cur+i<2*N) T+=S[cur+i];
					else T+='-';
				}
				cur+=P;
				R.push_back(T);
			}
		}
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arr2[] = {"A--", "-a-" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, makePancakes(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; string Arr2[] = {"A", "c", "B", "C", "a", "b" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, makePancakes(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; string Arr2[] = {"bA-e", "ECad", "-BcD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, makePancakes(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Pancakes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

