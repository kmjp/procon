#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define ZERO(a) memset(a,0,sizeof(a))

//-------------------------------------------------------

class SuffixArrayDiv2 {
	public:
	string smallerOne(string s) {
		int N=s.size();
		int i,x,y;
		vector<int> SA;
		FOR(i,N) SA.push_back(i);
		FOR(x,N) FOR(y,N-1) if(s.substr(SA[y])>s.substr(SA[y+1])) swap(SA[y],SA[y+1]);
		
		string S=string(N,127);
		
		S[SA[0]]='a';
		for(i=1;i<N;i++) {
			S[SA[i]]=S[SA[i-1]];
			for(int j=i+1;j<N;j++) S[SA[j]]=S[SA[j-1]]+1;
			int ng=0;
			for(x=0;x<i;x++) for(y=x+1;y<=i;y++) if(S.substr(SA[x])>S.substr(SA[y])) ng=1;
			S[SA[i]]+=ng;
		}
		
		if(S<s) return "Exists";
		return "Does not exist";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abca"; string Arg1 = "Exists"; verify_case(0, Arg1, smallerOne(Arg0)); }
	void test_case_1() { string Arg0 = "bbbb"; string Arg1 = "Exists"; verify_case(1, Arg1, smallerOne(Arg0)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "Does not exist"; verify_case(2, Arg1, smallerOne(Arg0)); }
	void test_case_3() { string Arg0 = "examplesareveryweakthinktwicebeforesubmit"; string Arg1 = "Exists"; verify_case(3, Arg1, smallerOne(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SuffixArrayDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

