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

int from[3030];
int to[3030];
int stt[1024][26];
const char base='a';
ll mo=1000000009;

void CreateSTT(string& pat) {
	int x,y,z,l;
	ZERO(stt);
	l=pat.size();
	FOR(x,l) {
		FOR(y,26) {
			if(base+y == pat[x]) stt[x][y]=x+1;
			else {
				string pre=pat.substr(0,x)+(char)(base+y);
				for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
			}
		}
	}
	FOR(y,26) stt[l][y]=l;
}

class LinenCenterEasy {
	public:
	int countStrings(string S, int N, int K) {
		int i,j,c,d;
		int L=S.size();
		CreateSTT(S);
		
		ZERO(from);
		from[0]=1;
		ll ret=0;
		if(K==0) ret++;
		for(i=1;i<=L*K+N;i++) {
			ZERO(to);
			
			FOR(j,i) FOR(c,26) (to[(j/L)*L+stt[j%L][c]] += from[j])%=mo;
			
			swap(from,to);
			if(i>=L*K && i<=L*K+N) for(j=L*K;j<L*(K+1);j++) ret+=from[j];
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "xy"; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2079; verify_case(0, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "q"; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1926; verify_case(1, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ababab"; int Arg1 = 5; int Arg2 = 4; int Arg3 = 527166180; verify_case(2, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "fgcdx"; int Arg1 = 10; int Arg2 = 3; int Arg3 = 586649223; verify_case(3, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "ghjhhhgjhjhgjhghghjhjg"; int Arg1 = 8; int Arg2 = 10; int Arg3 = 192161304; verify_case(4, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfe" ; int Arg1 = 49; int Arg2 = 25; int Arg3 = 164673990; verify_case(5, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "a"; int Arg1 = 7; int Arg2 = 0; int Arg3 = 357828722; verify_case(6, Arg3, countStrings(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arg0 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ; int Arg1 = 50; int Arg2 = 50; int Arg3 = 960113657; verify_case(7, Arg3, countStrings(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LinenCenterEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
