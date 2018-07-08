#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int num[1010];
int memo[1010][1010];

class LeftToRightGame {
	public:
	int L,D;
	
	int win_a(int d,int cur) {
		if(d==L) return cur!=0;
		if(memo[d][cur]>=0) return memo[d][cur];
		
		int i;
		int win=0;
		for(i=0;i<=9;i++) {
			if(i==0 && d==0) continue;
			int now=(cur+num[L-1-d]*i)%D;
			if(win_b(d+1,now)==0) win=1;
		}
		return memo[d][cur]=win;
		
	}
	int win_b(int d,int cur) {
		if(d==L) return cur==0;
		if(memo[d][cur]>=0) return memo[d][cur];
		int i;
		int win=0;
		for(i=0;i<=9;i++) {
			int now=(cur+num[L-1-d]*i)%D;
			if(win_a(d+1,now)==0) win=1;
		}
		return memo[d][cur]=win;
	}
	
	string whoWins(int length, int divisor) {
		L=length;
		D=divisor;
		int i,j,k;
		num[0]=1;
		
		MINUS(memo);
		FOR(i,length) num[i+1]=num[i]*10%D;
		
		if(win_a(0,0)) return "Alice";
		else return "Bob";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 10; string Arg2 = "Bob"; verify_case(0, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1000; string Arg2 = "Alice"; verify_case(1, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Bob"; verify_case(2, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 147; int Arg1 = 47; string Arg2 = "Alice"; verify_case(3, Arg2, whoWins(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LeftToRightGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

