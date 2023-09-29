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

class RankUp {
	public:
	string level(string record) {
		int rank=0;
		int star=0;
		int i;
		FOR(i,record.size()) {
			if(record[i]=='W') {
				star=min(star+2,5);
				if(star==5&&record[i-1]=='W'&&record[i-2]=='W'&&rank<15) {
					rank++;
					star=0;
				}
			}
			else {
				star=max(star-1,0);
				if(star==0&&record[i-1]=='L'&&record[i-2]=='L'&&rank%4) {
					rank--;
					star=5;
				}
			}
		}
		
		string A[4]={"Bronze ","Silver ","Gold ","Platinum "};
		string a=A[rank/4];
		a+='4'-rank%4;
		return a;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLLLL"; string Arg1 = "Bronze 4"; verify_case(0, Arg1, level(Arg0)); }
	void test_case_1() { string Arg0 = "WWLWW"; string Arg1 = "Bronze 4"; verify_case(1, Arg1, level(Arg0)); }
	void test_case_2() { string Arg0 = "WWLLWWW"; string Arg1 = "Bronze 3"; verify_case(2, Arg1, level(Arg0)); }
	void test_case_3() { string Arg0 = "WWWLLL"; string Arg1 = "Bronze 4"; verify_case(3, Arg1, level(Arg0)); }
	void test_case_4() { string Arg0 = "WWWWWWWWWWWWWLLL"; string Arg1 = "Silver 4"; verify_case(4, Arg1, level(Arg0)); }
	void test_case_5() { string Arg0 = "WWWWWLLL"; string Arg1 = "Bronze 3"; verify_case(5, Arg1, level(Arg0)); }
	void test_case_6() { string Arg0 = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"; string Arg1 = "Platinum 1"; verify_case(6, Arg1, level(Arg0)); }
	void test_case_7() { string Arg0 = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWLLLLLLLWWLWWWWLW"; string Arg1 = "Platinum 3"; verify_case(7, Arg1, level(Arg0)); }
	void test_case_8() { string Arg0 = "WWWWWWLLLLLL"; string Arg1 = "Bronze 3"; verify_case(8, Arg1, level(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RankUp ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

