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

ll mo=1000000007;
ll X[303];
vector<int> E[303][303];
vector<pair<int,int>> E2[303];
vector<int> P[303][303];

int mat[303][303][303];
int ok[303][303][303];
int dp[303][303];

class TreeMovingDiv2 {
	public:
	void dfs(int id,int base,int cur,int pre,int d) {
		mat[id][base][cur]=d;
		FORR(e,E[id][cur]) if(e!=pre) dfs(id,base,e,cur,d+1);
	}
	int count(int n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c) {
		int i,k,j,x;
		int m=a.size();
		FOR(i,303) FOR(k,303) E[i][k].clear();
		
		FOR(i,m) {
			E2[i].clear();
			ll X=c[i];
			FOR(j,n-1) {
				int u=(roots[i]+j+1)%n;
				int v=(roots[i]+(X%(j+1)))%n;
				E[i][u].push_back(v);
				E[i][v].push_back(u);
				E2[i].push_back({u,v});
				X = (a[i]*X+b[i])%mo;
			}
			FOR(j,n) dfs(i,j,j,j,0);
		}
		FOR(i,m) {
			FOR(k,n-1) {
				P[i][k].clear();
				FOR(j,n-1) {
					int x1=E2[i][k].first;
					int y1=E2[i][k].second;
					int x2=E2[(i+1)%m][j].first;
					int y2=E2[(i+1)%m][j].second;
					int xcl = (mat[(i+1)%m][x1][x2] < mat[(i+1)%m][x1][y2]) ? x2 : y2;
					int ycl = (mat[(i+1)%m][y1][x2] < mat[(i+1)%m][y1][y2]) ? x2 : y2;
					if(xcl!=ycl) P[i][k].push_back(j);
				}
			}
		}
		ll ret=0;
		FOR(x,n-1) {
			ZERO(dp);
			dp[0][x]=1;
			FOR(i,m) {
				FOR(k,n-1) if(dp[i][k]) {
					FORR(e,P[i][k]) {
						dp[i+1][e] += dp[i][k];
						if(dp[i+1][e]>=mo) dp[i+1][e]-=mo;
					}
				}
			}
			ret += dp[m][x];
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 5, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0, 1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 4, 7, 9, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8, 3, 9, 5, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {6, 0, 1, 5, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 22; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122064284, 9662111, 120616497}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20137061, 408976122, 494878172}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {242061783, 603049107, 805670429}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 15; int Arr1[] = {11, 3, 13, 5, 0, 3, 0, 8, 9, 4, 9, 7, 5, 12, 12, 11, 12, 2, 6, 5, 13, 13, 11, 8, 14, 9, 2, 0, 3, 11, 10, 12, 10, 11, 11, 12, 13, 7, 12, 11, 2, 14, 8, 3, 6, 6, 4, 13, 5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {983816220, 620877501, 728957664, 719453482, 891241034, 959047323, 459235325, 188837384, 749336264, 40650017, 404049008, 121578182, 640967952, 444329307, 181115164, 697849277, 12923013, 711014676, 308063158, 403714366, 341206103, 674610097, 743172147, 27978413, 95548595, 93823839, 844476902, 863583697, 568069127, 618319911, 659846531, 341309147, 735202433, 531047579, 967335611, 311192666, 753647731, 36420180, 609571991, 208600401, 915548304, 926479460, 672275772, 545217041, 864561330, 32472050, 852336473, 144521601, 383750815, 616511468}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {715457951, 308091233, 686233659, 523365634, 260145657, 96581518, 754153775, 622990522, 78662953, 689973864, 609423534, 534351235, 56822117, 899080526, 236413795, 747521954, 249656307, 790813221, 238598034, 203856426, 170015231, 791645278, 991710627, 747864180, 331241135, 416320805, 820623220, 811261319, 154661650, 914880513, 270905767, 954448019, 261442212, 954262444, 293791600, 493225233, 67542211, 911866345, 567575019, 95716070, 410883122, 337767450, 375732581, 616839717, 416849487, 140196829, 200763187, 51759408, 992789421, 882490836}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {650915191, 363659051, 226659197, 706291662, 748630395, 163284394, 663006670, 2890697, 639793395, 728890798, 570088430, 967259303, 101778889, 249725396, 968816738, 276471315, 905010209, 467925249, 798793109, 857289233, 494026470, 476417587, 98570430, 596160845, 211373787, 188742439, 364805067, 757845257, 317224756, 74104796, 455729968, 78933290, 769895010, 476555278, 45379277, 957039727, 395817921, 447349376, 629724490, 287334171, 227424105, 603337884, 467060652, 254067677, 237332026, 976429932, 93075762, 960441433, 132935737, 671265490}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 755767349; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeMovingDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

