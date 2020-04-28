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

int nex[101010][27];
int dp[101010][27];

class TreasureOfWinedag {
	public:
	int solvePuzzle(int N, int K, int m, int c0, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4, string s) {
		int i,j,k;
		for(i=s.size();i<N;i++) {
			ll t=i*(ll)c0%m;
			char nc='z';
			FOR(j,25) {
				if(t>=c3[j]&&t<=c4[j]&&((t%c1[j])==c2[j])) {
					nc='a'+j;
					break;
				}
			}
			s+=nc;
		}
		ZERO(nex);
		
		FOR(j,26) nex[N][j]=N;
		for(i=N-1;i>=0;i--) {
			FOR(j,26) nex[i][j]=nex[i+1][j];
			nex[i][s[i]-'a']=i;
		}
		FOR(i,N) sort(nex[i],nex[i]+26);
		MINUS(dp);
		dp[0][0]=0;
		dp[K][25]=N;
		
		FOR(i,K) {
			FOR(j,26) {
				if(dp[i][j]>=N || dp[i][j]<0) continue;
				for(k=0;j+k<=25;k++) dp[i+1][j+k]=max(dp[i+1][j+k], nex[dp[i][j]][k+1]);
			}
		}
		
		int mi=K+25;
		FOR(i,K+1) FOR(j,26) if(dp[i][j]>=N) mi=min(mi,K+j);
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = "aabb"; int Arg9 = 2; verify_case(0, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 3; int Arg2 = 1; int Arg3 = 0; int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = "abaacdddfeff"; int Arg9 = 6; verify_case(1, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arr4[] = {4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = ""; int Arg9 = 6; verify_case(2, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 2; int Arg2 = 100000; int Arg3 = 1; int Arr4[] = {2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {0, 0, 50000, 50000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {49999, 49999, 99999, 99999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = ""; int Arg9 = 4; verify_case(3, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 99980; int Arg2 = 987654; int Arg3 = 654321; int Arr4[] = {26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653, 987653}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = "topcoderopen"; int Arg9 = 99990; verify_case(4, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 424507751; int Arg3 = 79193201; int Arr4[] = {93991416, 122377683, 100930010, 373124588, 366757111, 314344105, 335481602, 25553224, 271158873, 131361019, 331824611, 152948279, 126679689, 84708668, 6797210, 361729904, 145699274, 79606375, 264167932, 413280894, 15762918, 207584964, 154302042, 70002530, 194642143}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {83184146, 70533279, 73860028, 211278755, 121940531, 286864621, 251852612, 18877531, 173979121, 104440673, 50907689, 29428358, 82351994, 20366667, 1415145, 165813027, 100425184, 11939160, 31133943, 157023871, 6513169, 86669984, 104254852, 21419693, 61982959}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {133139882, 123741581, 58820135, 40395052, 204057998, 220052469, 47757992, 135477098, 81874422, 38543527, 64336686, 54070556, 85767758, 394101179, 47318637, 141026976, 283673073, 227348343, 405835722, 203692488, 261118934, 76467402, 110499099, 179937390, 62000638}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {171061341, 420093260, 115970860, 246835989, 273845074, 423933877, 264762986, 225084596, 374349399, 242851788, 292230379, 173105221, 112972969, 417034170, 279113506, 255955057, 297052869, 264177905, 408974790, 348069397, 408363094, 224880992, 416173264, 296181015, 351748226}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); string Arg8 = "c"; int Arg9 = 1; verify_case(5, Arg9, solvePuzzle(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreasureOfWinedag ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

