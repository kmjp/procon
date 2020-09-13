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

int R,C,K;
int cost[303][303];
double S[303][303];
vector <int> roses, tulips;
vector<pair<double,int>> cand[2][303][303];

class ProposalOptimization {
	public:
	int ok2(vector<pair<double,int>>& A,vector<pair<double,int>>& B) {
		sort(ALL(A));
		sort(ALL(B));
		vector<pair<double,int>> C;
		FORR(b,B) {
			while(C.size() && C.back().second>=b.second) C.pop_back();
			if(C.size()&&C.back().first==b.first) continue;
			C.push_back(b);
		}
		FORR(a,A) {
			auto b=lower_bound(ALL(C),make_pair(-a.first,0));
			if(b!=C.end() && a.second+b->second<=K) {
				return 1;
			}
		}
		return 0;
	}
	
	int ok(double v) {
		int y,x;
		FOR(y,R) FOR(x,C) S[y][x]=roses[y*C+x]-v*tulips[y*C+x];
		FOR(y,R) FOR(x,C) cand[0][y][x].clear(),cand[1][y][x].clear();
		cand[0][0][0].push_back({0,0});
		cand[1][R-1][C-1].push_back({0,0});
		int i;
		for(i=0;;i++) {
			int did=0;
			FOR(y,R) {
				x=i-y;
				
				if(x>=0&&x<C) {
					if(cand[1][y][x].size()) {
						did++;
						FORR(c,cand[1][y][x]) c.first-=S[y][x], c.second-=cost[y][x];
						if(ok2(cand[0][y][x],cand[1][y][x])) return 1;
						cand[0][y][x].clear();
						cand[1][y][x].clear();
					}
					else {
						if(did) continue;
						if(y+1<R) {
							FORR(c,cand[0][y][x]) cand[0][y+1][x].push_back({c.first+S[y+1][x],c.second+cost[y+1][x]});
						}
						if(x+1<C) {
							FORR(c,cand[0][y][x]) cand[0][y][x+1].push_back({c.first+S[y][x+1],c.second+cost[y][x+1]});
						}
					}
				}
			}
			if(did) return 0;
			FOR(y,R) {
				x=R+C-2-i-y;
				if(x>=0&&x<C) {
					if(cand[0][y][x].size()) {
						did++;
						FORR(c,cand[1][y][x]) c.first-=S[y][x], c.second-=cost[y][x];
						if(ok2(cand[0][y][x],cand[1][y][x])) return 1;
						cand[0][y][x].clear();
						cand[1][y][x].clear();
					}
					else {
						if(did) continue;
						if(y) {
							FORR(c,cand[1][y][x]) cand[1][y-1][x].push_back({c.first+S[y-1][x],c.second+cost[y-1][x]});
						}
						if(x) {
							FORR(c,cand[1][y][x]) cand[1][y][x-1].push_back({c.first+S[y][x-1],c.second+cost[y][x-1]});
						}
					}
				}
			}
			if(did) return 0;
		}
		return 0;
		
	}
	
	double bestPath(int R, int C, int K, vector <int> roses, vector <int> tulips, vector <int> costs) {
		int x,y;
		::R=R;
		::C=C;
		::K=K;
		::roses=roses;
		::tulips=tulips;
		FOR(y,R) FOR(x,C) cost[y][x]=costs[y*C+x];
		
		double VL=0,VR=1e9;
		if(!ok(VL)) return -1;
		FOR(x,100) {
			if(VR-VL<=1e-10) break;
			double VM=(VL+VR)/2;
			if(ok(VM)) VL=VM;
			else VR=VM;
		}
		return VL;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0_() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 100; int Arr3[] = {0, 2, 3, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 3, 5, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 70, 80, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 0.6666666666666667; verify_case(0, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_0() { int Arg0 = 2; int Arg1 = 145; int Arg2 = 10000000; int Arr3[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 0.6666666666666667; verify_case(0, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 100; int Arr3[] = {0, 2, 3, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 3, 5, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 170, 100, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 0.6; verify_case(1, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 98; int Arr3[] = {0, 1, 1, 1, 1, 1, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 1, 1, 1, 1, 1, 1, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 33, 33, 33, 33, 33, 33, 33, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = -1.0; verify_case(2, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 9; int Arg2 = 622; int Arr3[] = {0, 2, 12, 1, 6, 10, 10, 24, 3, 1, 7, 4, 4, 1, 37, 4, 6, 8, 2, 20, 5, 20, 6, 7, 22, 3, 2, 8, 31, 18, 5, 28, 11, 1, 34, 1, 4, 2, 6, 1, 6, 9, 5, 7, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 4, 37, 22, 3, 14, 10, 6, 5, 6, 5, 17, 4, 7, 12, 3, 1, 3, 3, 1, 5, 1, 11, 37, 6, 24, 6, 3, 21, 1, 2, 27, 7, 1, 8, 1, 8, 1, 26, 20, 6, 6, 6, 7, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 19, 70, 79, 18, 43, 49, 65, 16, 38, 61, 69, 43, 12, 62, 11, 44, 35, 7, 62, 40, 88, 60, 57, 65, 38, 46, 18, 69, 87, 28, 80, 47, 5, 64, 1, 15, 3, 86, 41, 86, 21, 56, 28, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 2.161290322580645; verify_case(3, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; int Arr3[] = {0, 1, 3, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 2, 6, 1, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 18, 9, 1, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 1.0; verify_case(4, Arg6, bestPath(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ProposalOptimization ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

