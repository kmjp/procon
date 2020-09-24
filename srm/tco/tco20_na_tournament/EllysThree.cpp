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

int cost[200][3];
int dp[200][3];
class EllysThree {
	public:
	int getMin(int N, int M, vector <string> matrix) {
		ZERO(cost);
		int y,x,i;
		FOR(y,N) FOR(x,M) {
			int v=matrix[y][x];
			int r=y+x;
			if(v=='0') {
				cost[r][1]++;
				cost[r][2]+=2;
			}
			else if(v=='9') {
				cost[r][1]+=2;
				cost[r][2]++;
			}
			else {
				cost[r][(v+1)%3]++;
				cost[r][(v+2)%3]++;
			}
		}
		FOR(x,N+M+2) FOR(y,3) dp[x][y]=1<<30;
		dp[0][0]=0;
		FOR(i,N+M-1) {
			FOR(x,3) FOR(y,3) dp[i+1][(x+y)%3]=min(dp[i+1][(x+y)%3],dp[i][x]+cost[i][y]);
		}
		return dp[N+M-1][0];
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; string Arr2[] = {"1849312",
 "8951400",
 "5678129",
 "8721365"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 3; string Arr2[] = {"042"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"0002", "0020", "0200", "0001"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMin(Arg0, Arg1, Arg2)); }

	void test_case_2_() { int Arg0 = 9; int Arg1 = 1; string Arr2[] = {"1", "3", "3", "7", "6", "6", "6", "4", "2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(2, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 13; string Arr2[] = {"9454743993694",
 "2621082535304",
 "7042910517370",
 "1085880558575",
 "1649500905308",
 "1329832441329",
 "8039295627801"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 42; verify_case(3, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 33; int Arg1 = 28; string Arr2[] = {"3924540372699482461959052373",
 "3775662604951838761645280661",
 "4590019155668566895846525300",
 "7660057219937532806711524044",
 "1564147647984682605010172146",
 "7045841532282877576364456274",
 "3814819683751796473651237567",
 "4031424800358860980124855111",
 "5002523845580224146215648232",
 "8491414555026773578968320263",
 "4946734059870766934433755091",
 "9792652664307908810065499322",
 "5883633601313699981657212869",
 "0270456241288992902960982050",
 "8248225251569913625753339601",
 "6038989966909434471708165284",
 "7157408935676850512694539390",
 "1903308470539870820923313050",
 "5672155010906362182244410101",
 "5613238011479959434003125799",
 "1616602903240654799752974673",
 "9917238043310329767524789648",
 "9386866245651931148351599616",
 "0288261775320885692141607061",
 "4502491177791892689367563262",
 "2387625226003663573293368187",
 "1851685890743516942422293606",
 "6116997930274118769324412710",
 "0640686746123981416169165875",
 "2809115257849686014067667122",
 "2036057721028023144804036953",
 "8941139704540145857739666512",
 "9853874329000744480537363737"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 484; verify_case(4, Arg3, getMin(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysThree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

