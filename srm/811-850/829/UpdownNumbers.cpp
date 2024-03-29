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

const ll mo=1000000007;

ll from[1<<10][1<<10];
ll to[1<<10][1<<10];

int Utable[1<<10][10];
int Dtable[1<<10][10];

class UpdownNumbers {
	public:
	int count(int D, int S) {
		
		ZERO(Utable);
		ZERO(Dtable);
		int m1,m2;
		int mask,i,j;
		FOR(mask,1<<10) {
			FOR(i,10) {
				for(j=i;j<10;j++) if(mask&(1<<j)) break;
				if(j==10) Utable[mask][i]=mask^(1<<i);
				else Utable[mask][i]=mask^(1<<j)^(1<<i);
				
				for(j=i;j>=0;j--) if(mask&(1<<j)) break;
				if(j==-1) Dtable[mask][i]=mask^(1<<i);
				else Dtable[mask][i]=mask^(1<<j)^(1<<i);
			}
		}
		
		ZERO(from);
		from[0][0]=1;
		int first=1;
		while(D--) {
			ZERO(to);
			FOR(m1,1<<10) FOR(m2,1<<10) if(from[m1][m2]) {
				FOR(i,10) {
					if(first&&i==0) continue;
					(to[Utable[m1][i]][Dtable[m2][i]]+=from[m1][m2])%=mo;
				}
			}
			first=0;
			swap(from,to);
		}
		ll ret=0;
		FOR(m1,1<<10) FOR(m2,1<<10) if(from[m1][m2]) {
			if(__builtin_popcount(m1)>=S&&__builtin_popcount(m2)>=S) 
				ret+=from[m1][m2];
			}
		}
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 9; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 525; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 2; int Arg2 = 986881317; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 73017588; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UpdownNumbers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

