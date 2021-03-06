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

class EpicPartition {
	public:
	string createPartition(int N) {
		int sum=0;
		int i;
		if(N%4) return "";
		string S;
		int A=0,C=0;
		int cur=1;
		FOR(i,N) {
			S+="abba";
			A+=cur+cur+3;
			cur+=4;
		}
		FOR(i,N) {
			S+="cc";
			C+=cur+cur+1;
			cur+=2;
		}
		int x,y;
		for(x=0;x<S.size();x++) if(S[x]=='c') {
			y=x;
			while(A*2<C) {
				if(y==0 || S[y-1]=='c') break;
				swap(S[y],S[y-1]);
				swap(S[y-1],S[y-2]);
				A++;
				C-=2;
				y-=2;
			}
			
		}
		
		
		cout<<A<<" "<<C<<" "<<S<<endl;
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = ""; verify_case(0, Arg1, createPartition(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = ""; verify_case(1, Arg1, createPartition(Arg0)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "aaabababbbbabbcccccccaac"; verify_case(2, Arg1, createPartition(Arg0)); }
	void test_case_3() { int Arg0 = 8; string Arg1 = "abaaaaaabaabbaabbbbbbbbbbbbccccccccaaccccccacaac"; verify_case(3, Arg1, createPartition(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EpicPartition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

