#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int mat[51][51];
int ma[51][51];


class AllGraphCuts {
	public:
	vector <int> findGraph(vector <int> X) {
		int N=0,x,y,z;
		while(N*N<X.size()) N++;
		FOR(y,N) FOR(x,N) mat[y][x]=X[y*N+x];
		vector<pair<int,int>> E;
		FOR(y,N) FOR(x,N) {
			if(x==y && mat[x][x]) return {-1};
			if(mat[x][y]!=mat[y][x]) return {-1};
			if(x<y) E.push_back({mat[x][y],x*100+y});
		}
		ZERO(ma);
		
		sort(E.begin(),E.end());
		reverse(E.begin(),E.end());
		FOR(x,N) FOR(y,N) ma[x][y]=-1;
		FOR(x,N) ma[x][x]=100000;
		vector<int> v;
		FORR(r,E) {
			x=r.second/100;
			y=r.second%100;
			if(ma[x][y]>=0) continue;
			ma[x][y]=ma[y][x]=r.first;
			v.push_back(r.first*N*N+y*N+x);
			FOR(z,N) FOR(x,N) FOR(y,N) ma[x][y]=max(ma[x][y],min(ma[x][z],ma[z][y]));
		}
		
		FOR(y,N) FOR(x,N) if(x!=y && ma[x][y]!=mat[x][y]) return {-1};
		
		return v;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0,1,
 1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findGraph(Arg0)); }
	void test_case_1() { int Arr0[] = {0,1,
 1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findGraph(Arg0)); }
	void test_case_2() { int Arr0[] = {0,2,2,
 2,0,2,
 2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 11, 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findGraph(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,
 1,0,2,3,4,
 1,2,0,3,4,
 1,2,3,0,4,
 1,2,3,4,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findGraph(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findGraph(Arg0)); }
	void test_case_5() { int Arr0[] = {
0, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 3082,
2545, 0, 2348, 2545, 2545, 2545, 2013, 2545, 2545, 2440, 2495, 2262, 2342, 2545, 2545, 2545, 2545, 2545, 2545, 2545,
2348, 2348, 0, 2348, 2348, 2348, 2013, 2348, 2348, 2348, 2348, 2262, 2342, 2348, 2348, 2348, 2348, 2348, 2348, 2348,
2993, 2545, 2348, 0, 2606, 2623, 2013, 2993, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 2993, 2993,
2606, 2545, 2348, 2606, 0, 2606, 2013, 2606, 2606, 2440, 2495, 2262, 2342, 2606, 2606, 2606, 2606, 2606, 2606, 2606,
2623, 2545, 2348, 2623, 2606, 0, 2013, 2623, 2623, 2440, 2495, 2262, 2342, 2617, 2623, 2623, 2623, 2623, 2623, 2623,
2013, 2013, 2013, 2013, 2013, 2013, 0, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013,
3001, 2545, 2348, 2993, 2606, 2623, 2013, 0, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3001, 3001,
2626, 2545, 2348, 2626, 2606, 2623, 2013, 2626, 0, 2440, 2495, 2262, 2342, 2617, 2626, 2626, 2626, 2626, 2626, 2626,
2440, 2440, 2348, 2440, 2440, 2440, 2013, 2440, 2440, 0, 2440, 2262, 2342, 2440, 2440, 2440, 2440, 2440, 2440, 2440,
2495, 2495, 2348, 2495, 2495, 2495, 2013, 2495, 2495, 2440, 0, 2262, 2342, 2495, 2495, 2495, 2495, 2495, 2495, 2495,
2262, 2262, 2262, 2262, 2262, 2262, 2013, 2262, 2262, 2262, 2262, 0, 2262, 2262, 2262, 2262, 2262, 2262, 2262, 2262,
2342, 2342, 2342, 2342, 2342, 2342, 2013, 2342, 2342, 2342, 2342, 2262, 0, 2342, 2342, 2342, 2342, 2342, 2342, 2342,
2617, 2545, 2348, 2617, 2606, 2617, 2013, 2617, 2617, 2440, 2495, 2262, 2342, 0, 2617, 2617, 2617, 2617, 2617, 2617,
2773, 2545, 2348, 2773, 2606, 2623, 2013, 2773, 2626, 2440, 2495, 2262, 2342, 2617, 0, 2662, 2736, 2773, 2773, 2773,
2662, 2545, 2348, 2662, 2606, 2623, 2013, 2662, 2626, 2440, 2495, 2262, 2342, 2617, 2662, 0, 2662, 2662, 2662, 2662,
2736, 2545, 2348, 2736, 2606, 2623, 2013, 2736, 2626, 2440, 2495, 2262, 2342, 2617, 2736, 2662, 0, 2736, 2736, 2736,
2827, 2545, 2348, 2827, 2606, 2623, 2013, 2827, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 0, 2827, 2827,
3044, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 0, 3044,
3082, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 0
}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {76801, 87602, 76403, 15604, 14005, 14406, 95607, 14408, 45609, 54010, 113211, 102812, 53613, 72414, 10015, 90416, 110417, 108818, 76819, 20022, 5223, 16824, 14025, 20426, 37227, 115628, 118829, 105230, 39631, 114032, 70833, 2434, 9235, 71636, 3637, 108438, 68439, 16443, 24444, 37245, 54046, 118447, 46048, 13249, 38450, 27651, 23652, 105253, 76054, 22455, 112056, 5657, 82458, 28859, 31264, 117665, 73666, 91667, 11268, 67269, 110870, 18471, 114872, 119673, 22074, 86075, 44876, 22477, 74478, 93679, 96085, 8486, 59687, 110088, 1689, 107290, 56091, 56092, 74893, 61294, 109295, 109296, 18097, 66498, 20899, 12506, 98907, 82908, 77309, 51710, 110111, 108112, 22513, 66514, 43315, 36516, 19717, 15318, 26519, 34127, 70128, 8929, 20930, 131, 81732, 80133, 29334, 68935, 53336, 81737, 36538, 57739, 35348, 96149, 25750, 19351, 15752, 4153, 80554, 107355, 96556, 70557, 66958, 48559, 33769, 81370, 55771, 15372, 61373, 72574, 11375, 2976, 66577, 108178, 57779, 590, 78991, 14992, 10593, 69794, 47395, 33796, 113397, 77398, 68999, 77811, 28212, 12613, 64614, 80215, 9816, 27017, 30618, 73819, 46632, 66633, 7834, 100635, 636, 7437, 4238, 76639, 87453, 16254, 10255, 31856, 50257, 18258, 3459, 73474, 69475, 63876, 41077, 3878, 28679, 13495, 56696, 109497, 101098, 116699, 60316, 107517, 12318, 98719, 51137, 91138, 81139, 108358, 119959, 106379 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findGraph(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AllGraphCuts ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
