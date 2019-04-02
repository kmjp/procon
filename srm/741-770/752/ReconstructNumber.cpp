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
//-------------------------------------------------------

int nex[2020][10];

class ReconstructNumber {
	public:
	string smallest(string C) {
		MINUS(nex);
		int N=C.size();
		
		if(N==0) return "1";
		int i,j,k;
		FOR(i,10) nex[N][i]=1;
		for(i=N-1;i>=0;i--) {
			FOR(j,10) FOR(k,10) if(nex[i+1][k]>=0) {
				if(C[i]=='=' && j!=k) continue;
				if(C[i]=='!' && j==k) continue;
				if(C[i]=='<' && j>=k) continue;
				if(C[i]=='>' && j<=k) continue;
				nex[i][j]=k;
				break;
			}
		}
		
		string S;
		for(int cur=1;cur<=9;cur++) if(nex[0][cur]>=0) {
			S.push_back('0'+cur);
			FOR(j,N) {
				cur=nex[j][cur];
				S.push_back('0'+cur);
			}
			return S;
		}
		return "";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ">=!<"; string Arg1 = "10012"; verify_case(0, Arg1, smallest(Arg0)); }
	void test_case_1() { string Arg0 = "====!===="; string Arg1 = "1111100000"; verify_case(1, Arg1, smallest(Arg0)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = "1"; verify_case(2, Arg1, smallest(Arg0)); }
	void test_case_3() { string Arg0 = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>"; string Arg1 = ""; verify_case(3, Arg1, smallest(Arg0)); }
	void test_case_4() { string Arg0 = "><<>><=<=>=>"; string Arg1 = "1012101122110"; verify_case(4, Arg1, smallest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ReconstructNumber ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

