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

vector<string> S;
int sp[31][31];

class RoomPairs {
	public:
	vector <string> construct(int R, int C, int N) {
		S.clear();
		int x,y;
		
		ZERO(sp);
		
		if(N==2) {
			if(R==2&&C==2) return {};
			sp[0][0]=sp[R-1][C-1]=1;
		}
		else if(C>R) {
			FOR(y,R) {
				FOR(x,C) {
					int add=2;
					
					if(N==1 && y<R-1&&x<C-1) {
						sp[R-1][C-1]=1;
						N-=1;
					}
					
					if(x==0 || y==R-1) add--;
					if(N>=add) sp[y][x]=1,N-=add;
				}
			}
		}
		else {
			FOR(x,C) {
				FOR(y,R) {
					int add=2;
					if(N==1 && y<R-1&&x<C-1) {
						sp[R-1][C-1]=1;
						N-=1;
					}
					
					if(y==0 || x==C-1) add--;
					if(N>=add) sp[y][x]=1,N-=add;
				}
			}
		}
		
		
		FOR(y,2*R+1) {
			S.push_back(string(2*C+1,' '));
			if(y%2==0) {
				for(x=0;x<=2*C;x+=2) S[y][x]='+';
			}
			if(y==0 || y==2*R) for(x=1;x<=2*C;x+=2) S[y][x]='-';
			if(y%2) S[y][0]=S[y][2*C]='|';
		}
		
		FOR(y,R) FOR(x,C) {
			if(y+1<R && (sp[y][x]||sp[y+1][x])) S[2*(y+1)][x*2+1]='-';
			if(x+1<C && (sp[y][x]||sp[y][x+1])) S[y*2+1][2*(x+1)]='|';
		}
		
		FORR(s,S) cout<<s<<endl;
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; string Arr3[] = {"+-+-+-+-+", "| |   | |", "+ + +-+ +", "|   |   |", "+-+-+-+-+" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; string Arr3[] = {"+-+-+-+", "| | | |", "+-+ +-+", "|     |", "+-+ +-+", "| | | |", "+-+-+-+" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"+-+-+-+-+", "|       |", "+ +-+-+ +", "| | | | |", "+ +-+-+ +", "|       |", "+-+-+-+-+" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, construct(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 31; string Arr3[] = {"+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, construct(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RoomPairs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

