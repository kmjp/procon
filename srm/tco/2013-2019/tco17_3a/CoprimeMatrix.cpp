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


class CoprimeMatrix {
	public:

	string isPossible(vector <string> coprime) {
		string YES="Possible";
		string NO="Impossible";
		
		int N=coprime.size();
		int i,j,x,y;
		FOR(x,N) FOR(y,N) coprime[x][y]=coprime[x][y]=='Y';
		
		if(coprime[0][0]) {
			FOR(x,N) FOR(y,N) if(coprime[x][y] != (__gcd(x+1,y+1)==1)) return NO;
			return YES;
		}
		
		FOR(x,N) FOR(y,N) {
			if(x==y && coprime[x][x]) return NO;
			if(coprime[x][y]!=coprime[y][x]) return NO;
		}
		
		auto A=coprime;
		FOR(x,N) FOR(y,N) A[y][x]=x!=y;
		
		for(i=2;i<=N;i++) {
			for(j=2;j<i;j++) if(i%j==0) break;
			if(j!=i) continue;
			x = -1;
			for(j=0;j<i && j+i<N; j++) {
				if(coprime[j][j+i]==0) {
					x = j;
					break;
				}
			}
			if(j==i) return NO;
			
			if(x>=0) {
				for(;x<N;x+=i) for(y=x+i;y<N;y+=i) A[x][y]=A[y][x]=0;
			}
		}
		
		return (A==coprime)?YES:NO;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNYN",
 "YNYYN",
 "NYNYN",
 "YYYNY",
 "NNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYYN",
 "YNYNNN",
 "YYNYYY",
 "YNYNYN",
 "YNYYNY",
 "NNYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(3, Arg1, isPossible(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CoprimeMatrix ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

