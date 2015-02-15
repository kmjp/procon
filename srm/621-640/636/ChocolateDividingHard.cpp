#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class ChocolateDividingHard {
	public:
	int S[80][80];
	int H,W;
	int sum(int x1,int y1,int x2,int y2) {
		return S[y2][x2]-S[y1][x2]-S[y2][x1]+S[y1][x1];
	}
	
	int okok(int val) {
		int y[3];
		for(y[0]=1;y[0]<=H;y[0]++)
			for(y[1]=y[0]+1;y[1]<=H;y[1]++)
				for(y[2]=y[1]+1;y[2]<=H;y[2]++) {
					int bx=0,num=0,x;
					FOR(x,W) {
						int ok=1;
						if(sum(bx,0,x+1,y[0])<val) ok=0;
						if(sum(bx,y[0],x+1,y[1])<val) ok=0;
						if(sum(bx,y[1],x+1,y[2])<val) ok=0;
						if(sum(bx,y[2],x+1,H)<val) ok=0;
						if(ok) num++, bx=x+1;
					}
					if(num>=4) return 1;
				}
		return 0;
	}
	
	int findBest(vector <string> C) {
		int x,y,mi=0;
		H=C.size(), W=C[0].size();
		ZERO(S);
		FOR(y,H) {
			FOR(x,W) S[y+1][x+1]=S[y+1][x]+C[y][x]-'0';
			FOR(x,W) S[y+1][x+1]+=S[y][x+1];
		}
		
		int ok=0;
		for(x=20;x>=0;x--) if(okok(ok+(1<<x))) ok+=1<<x;
		return ok;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"95998",
"21945",
"23451",
"99798",
"74083"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"12942",
"23456",
"99798",
"98998",
"67675"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"129420",
"234560",
"997980",
"989980",
"676760"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, findBest(Arg0)); }
	void test_case_3() { string Arr0[] = {"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, findBest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChocolateDividingHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
