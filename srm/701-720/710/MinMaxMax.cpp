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

ll minw[303][303];
ll mind[303][303];

class MinMaxMax {
	public:
	long long findMin(vector <int> a, vector <int> b, vector <int> w, vector <int> v) {
		int N=v.size();
		int i,x,y;
		pair<int,int> P[303];
		FOR(i,N) P[i]={v[i],i};
		sort(P,P+N);
		
		FOR(y,N) FOR(x,N) minw[x][y]=1LL<<40;
		FOR(y,N) FOR(x,N) mind[x][y]=1LL<<60;
		FOR(i,a.size()) minw[a[i]][b[i]]=minw[b[i]][a[i]]=w[i];
		
		FOR(i,N) {
			int z=P[i].second;
			FOR(x,N) FOR(y,N) {
				minw[x][y] = min(minw[x][y], max(minw[x][z],minw[z][y]));
				mind[x][y] = min(mind[x][y], 1LL*minw[x][y] * max({v[x],v[y],v[z]}));
			}
		}
		
		
		ll tot=0;
		FOR(y,N) FOR(x,y) tot+=mind[x][y];
		
		return tot;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 30LL; verify_case(0, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,5,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 186LL; verify_case(1, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 300LL; verify_case(2, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000,1,1000000,1,1000000,1,1000000,1,1000000,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000000,1,1000000,1,1000000,1,1000000,1,1000000,1,1000000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 50000005000000LL; verify_case(3, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {9,12,4,11,0,8,6,11,11,10,12,7,3,12,3,10,0,3,2,7,
0,10,8,1,11,9,2,0,3,6,4,2,3,5,9,0,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5,6,5,10,2,1,2,3,4,6,9,9,10,5,5,6,4,12,5,12,7,
7,3,4,12,4,1,8,7,1,6,6,4,11,5,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {879651,656980,11,51564,206,420,917584,205,59290,3323,
644,1,13243,84162,154,561242,1,190,10,136901,420623,
353,573129,81,25,133670,72,528049,5,715560,82641,46,
1,527672,923948,1,13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,1829,51302,3026,4,14,5189,3,25289,2,2967,15994,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 157740289LL; verify_case(4, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {4,16,0,10,11,21,11,21,20,6,13,10,10,3,20,15,16,9,6,14,13,8,
17,9,2,21,3,4,10,13,5,7,13,1,12,1,3,13,5,21,12,0,19,15,6,0,
5,13,1,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17,1,8,2,1,7,6,12,18,21,7,20,18,7,6,7,17,20,15,10,14,16,2,6,
19,3,19,3,6,18,10,11,10,4,17,13,15,9,15,17,11,16,13,1,19,17,
19,17,10,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {327583,4194,990205,481090,868602,722789,547481,738569,188373,
973550,462208,74066,639614,693164,86808,442101,811939,995334,
551737,335601,147231,93330,799032,130164,839277,757103,234057,
909252,415269,945015,715797,549525,581349,130104,493780,553519,
755216,626951,743631,231151,205857,917585,553454,352015,873807,
573520,569698,317228,754891,875856}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {220468,844712,599675,53333,825995,711279,289092,415428,805292,
985205,197039,193974,95433,244829,558762,555423,725065,498922,
519543,4803,305565,61949}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 64390854062526LL; verify_case(5, Arg4, findMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinMaxMax ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

