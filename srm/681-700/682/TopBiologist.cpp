#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int NG[7][4096];

class TopBiologist {
	public:
	string findShortestNewSequence(string sequence) {
		FORR(r,sequence) {
			if(r=='A') r=0;
			else if(r=='T') r=1;
			else if(r=='G') r=2;
			else if(r=='C') r=3;
			else r=4;
		}
		ZERO(NG);
		int i,j,k;
		for(i=1;i<=6;i++) {
			FOR(j,sequence.size()+1-i) {
				int id=0;
				FOR(k,i) {
					if(sequence[j+k]==4) break;
					id=id*4+sequence[j+k];
				}
				if(k==i) NG[i][id]=1;
			}
			FOR(j,1<<(2*i)) if(NG[i][j]==0) {
				string s;
				FOR(k,i) {
					s="ATGC"[j%4]+s;
					j/=4;
				}
				return s;
			}
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AGGTCTA"; string Arg1 = "AC"; verify_case(0, Arg1, findShortestNewSequence(Arg0)); }
	void test_case_1() { string Arg0 = "AGACGACGGAGAACGA"; string Arg1 = "T"; verify_case(1, Arg1, findShortestNewSequence(Arg0)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "C"; verify_case(2, Arg1, findShortestNewSequence(Arg0)); }
	void test_case_3() { string Arg0 = "AAGATACACCGGCTTCGTG"; string Arg1 = "CAT"; verify_case(3, Arg1, findShortestNewSequence(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TopBiologist ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
