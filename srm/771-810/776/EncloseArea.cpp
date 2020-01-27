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

int B[52][52];

class EncloseArea {
	public:
	vector <string> enclose(int A) {
		if(A%2) return {};
		A/=2;
		
		ZERO(B);
		int x,y;
		
		for(x=1;x<=49;x++) if(A) A--, B[1+(x%2==0)][x]=1;
		
		for(y=3;y<=49;y++) {
			for(x=1+(y%2==0);x<=49;x+=2) if(A) A--,B[y][x]=1;
		}
		
		if(A>0) return {};
		
		vector<string> S;
		FOR(y,50) {
			S.push_back(string(50,'.'));
			FOR(x,50) {
				if((B[y][x]==1)!=(B[y+1][x+1]==1)) S[y][x]='/';
				if((B[y][x+1]==1)!=(B[y+1][x]==1)) S[y][x]='\\';
			}
			cout<<S[y]<<endl;
		}
		
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 12; string Arr1[] = {"........", "../\\....", "./..\\...", ".\\...\\..", "..\\../..", "...\\/...", "........", "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, enclose(Arg0)); }
	void test_case_1() { int Arg0 = 7; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, enclose(Arg0)); }
	void test_case_2() { int Arg0 = 2498; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, enclose(Arg0)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"./\\..", "/./..", "\\.\\/\\", ".\\../", "..\\/." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, enclose(Arg0)); }
	void test_case_4() { int Arg0 = 26; string Arr1[] = {"/\\/\\/\\", "\\..../", "/....\\", "\\..../", "/....\\", "\\/\\/\\/" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, enclose(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EncloseArea ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

