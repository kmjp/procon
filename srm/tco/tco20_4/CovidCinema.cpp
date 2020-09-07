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

class CovidCinema {
	public:
	int hoge(int R,int C,int N[2],vector<string>& V,int i) {
		int x,y;
		FOR(y,R) FOR(x,C) if(N[i^1]) {
			int ok=1;
			if(V[y][x]!='.') ok=0;
			if(y&&V[y-1][x]=='A'+i) ok=0;
			if(x&&V[y][x-1]=='A'+i) ok=0;
			if(y+1<R&&V[y+1][x]=='A'+i) ok=0;
			if(x+1<C&&V[y][x+1]=='A'+i) ok=0;
			if(ok) {
				V[y][x]='A'+(i^1);
				N[i^1]--;
			}
		}
		return N[0]==0&&N[1]==0;
	}
	vector <string> seat(int R, int C, int A, int B) {
		string S(C,'.');
		vector<string> tmp,NG;
		int y,x,i;
		FOR(y,R) tmp.push_back(S);
		
		int w,h;
		FOR(i,2) { //A,B
			
			for(w=1;w<=C;w++) {
				auto V=tmp;
				int N[2]={A,B};
				FOR(y,R) FOR(x,w) if(N[i]) V[y][x]='A'+i, N[i]--;
				if(hoge(R,C,N,V,i)) return V;
				
			}
			for(h=1;h<=R;h++) {
				auto V=tmp;
				int N[2]={A,B};
				FOR(x,C) FOR(y,h) if(N[i]) V[y][x]='A'+i, N[i]--;
				if(hoge(R,C,N,V,i)) return V;
			}
			for(h=1;h<=min(R,C);h++) {
				auto V=tmp;
				int N[2]={A,B};
				FOR(y,h) FOR(x,h-1-y) if(N[i]) V[y][x]='A'+i, N[i]--;
				if(hoge(R,C,N,V,i)) return V;
			}
		}
		return NG;
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 2; int Arg3 = 3; string Arr4[] = {"......", ".A..BB", "......", "B.A..." }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, seat(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 13; int Arg3 = 7; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, seat(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 14; int Arg3 = 2; string Arr4[] = {"B.AAA", ".AAAA", "AAAA.", "AAA.B" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, seat(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 17; int Arg3 = 4; string Arr4[] = {"AAAAA", "AAAAA", "..AAA", "BB.AA", "BB.AA" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, seat(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CovidCinema ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

