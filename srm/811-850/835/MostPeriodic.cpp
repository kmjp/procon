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

class MostPeriodic {
	public:
	string construct(string bank) {
		int N=bank.size();
		int C[26]={};
		FORR(c,bank) C[c-'A']++;
		int step,i,rep;
		for(rep=N;rep>=1;rep--) {
			int X[26],Y[26];
			int num=0;
			int ok=1;
			FOR(i,26) {
				X[i]=0;
				Y[i]=C[i];
				while(1) {
					if(X[i]>=Y[i]) break;
					if(Y[i]>=rep) {
						X[i]++;
						Y[i]-=rep;
					}
					else {
						break;
					}
				}
				if(X[i]<Y[i]) break;
			}
			if(i!=26) continue;
			string S;
			int j,x;
			FOR(x,rep) {
				FOR(i,26) {
					FOR(j,Y[i]) S+='A'+i;
				}
				FOR(i,26) {
					FOR(j,X[i]-Y[i]) S+='A'+i;
				}
			}
			FOR(i,26) {
				FOR(j,Y[i]) S+='A'+i;
			}
			return S;
			
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAA"; string Arg1 = "AAAAA"; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDE"; string Arg1 = "EDCBA"; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "TOPCODER"; string Arg1 = "OTRPEDCO"; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "AAAABBAAAA"; string Arg1 = "AABAAABAAA"; verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MostPeriodic ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

