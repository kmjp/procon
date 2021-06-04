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


class IncorrectCancellation {
	public:
	
	map<int,int> sub(int a,int b) {
		string A=to_string(a);
		string B=to_string(b);
		map<int,int> M;
		int i=0;
		FORR(c,A) {
			if(i<B.size()&&c==B[i]) {
				i++;
				continue;
			}
			M[c-'0']++;
		}
		
		if(i!=B.size()) M.clear();
		return M;
	}
	
	
	int find(int D) {
		
		string S=to_string(D);
		int N=S.size();
		
		int mask,i;
		for(mask=1;mask<(1<<N)-1;mask++) {
			int v=0;
			map<int,int> del;
			FOR(i,N) {
				if(mask&(1<<i)) {
					v=v*10+(S[i]-'0');
					if(v==0) break;
				}
				else {
					del[S[i]-'0']++;
				}
			}
			if(v==0) continue;
			
			for(int c=1;c<v;c++) {
				ll cd=1LL*c*D;
				if(cd%v) continue;
				ll p=cd/v;
				auto M=sub(p,c);
				if(M==del) return p;
			}
		}
		
		
		
		
		return -1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 64; int Arg1 = 16; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 98; int Arg1 = 49; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 470; int Arg1 = 10; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1057; int Arg1 = -1; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 15436; int Arg1 = 454; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { int Arg0 = 15425; int Arg1 = 13574; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { int Arg0 = 6665; int Arg1 = 2666; verify_case(6, Arg1, find(Arg0)); }
	void test_case_7() { int Arg0 = 1221; int Arg1 = 222; verify_case(7, Arg1, find(Arg0)); }
	void test_case_8_() { int Arg0 = 7; int Arg1 = -1; verify_case(8, Arg1, find(Arg0)); }
	void test_case_8() { int Arg0 = 499733; int Arg1 = -1; verify_case(8, Arg1, find(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IncorrectCancellation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

