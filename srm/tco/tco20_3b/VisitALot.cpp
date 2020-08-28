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



class VisitALot {
	public:
	string travel(int R, int C, vector <int> obsr, vector <int> obsc) {
		int L=2*(R-1+C-1);
		string S;
		if(L*2>=R*C) {
			int i;
			FOR(i,C-1) S+="E";
			FOR(i,R-1) S+="S";
			FOR(i,C-1) S+="W";
			FOR(i,R-2) S+="N";
			return S;
			
		}
		int NC[51]={};
		int NR[51]={};
		FORR(r,obsr) NR[r]++;
		FORR(c,obsc) NC[c]++;
		// LR
		int x,y;
		L=R;
		FOR(y,R) if(NR[y]==0) L+=C-1;
		if(L*2>=R*C) {
			int side=0;
			FOR(y,R) {
				if(NR[y]==0) {
					FOR(x,C-1) S+="EW"[side];
					side^=1;
				}
				if(y==R-1) break;
				S+="S";
			}
			return S;
		}
		L=C;
		FOR(x,C) if(NC[x]==0) L+=R-1;
		if(L*2>=R*C) {
			int side=0;
			FOR(x,C) {
				if(NC[x]==0) {
					FOR(y,R-1) S+="SN"[side];
					side^=1;
				}
				if(x==C-1) break;
				S+="E";
			}
			return S;
		}
		return "";
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "SENE"; verify_case(0, Arg4, travel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; int Arr2[] = {1, 1, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "SSEESWWSSEENEE"; verify_case(1, Arg4, travel(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 8; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE"; verify_case(2, Arg4, travel(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  VisitALot ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

