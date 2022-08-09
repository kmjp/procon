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

class GoThereExactly {
	public:
	string walk(int r1, int c1, int r2, int c2, int s) {
		
		string S;
		int i;
		if(r1==r2&&c1==c2) {
			if(s==0) return "";
			if(s%2) return "IMPOSSIBLE";
			FOR(i,s/2-1) S+="R";
			S+="D";
			FOR(i,s/2-1) S+="L";
			S+="U";
		}
		else {
			while(s>abs(r2-r1)+abs(c2-c1)+1) {
				s-=2;
				if(c2!=c1+1) S+="RL";
				else S+="LR";
			}
			
			
			while(s--) {
				if(r1<r2) {
					r1++;
					S+="D";
				}
				else if(r1>r2) {
					r1--;
					S+="U";
				}
				else if(c1<c2) {
					c1++;
					S+="R";
				}
				else {
					c1--;
					S+='L';
				}
			}
		}
		if(r1==r2&&c1==c2) return S;
		return "IMPOSSIBLE";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; string Arg5 = ""; verify_case(0, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 8; int Arg4 = 42; string Arg5 = "IMPOSSIBLE"; verify_case(1, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; int Arg3 = 7; int Arg4 = 12; string Arg5 = "UUURRRDDDLLL"; verify_case(2, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 4; int Arg3 = 0; int Arg4 = 14; string Arg5 = "LLDDRRDRRRDLLL"; verify_case(3, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 18; int Arg1 = 16; int Arg2 = 16; int Arg3 = 13; int Arg4 = 5; string Arg5 = "UULLL"; verify_case(4, Arg5, walk(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoThereExactly ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

