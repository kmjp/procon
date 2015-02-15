#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

vector<int> T[2][4001];
int LL,RR;
pair<int,int> memo[4001];

int L[4001],R[4001];
int eid;

void EulerTour(int cur,int pre) {
	if(pre==-1) ZERO(L),ZERO(R),eid=0;
	L[cur]=eid++;
	ITR(it,T[0][cur]) if(*it!=pre) EulerTour(*it,cur);
	R[cur]=eid;
}

class TreesAnalysis {
	public:
	int N,st1;
	ll ret;
	
	pair<int,int> sumsum(int cur,int pre) {
		int i;
		if(memo[cur].first!=-1) return memo[cur];
		
		pair<int,int> tot=make_pair(0,0);
		if(LL<=L[cur] && L[cur]<RR) tot.second++;
		else tot.first++;
		FOR(i,T[1][cur].size()) {
			int tar=T[1][cur][i];
			if(tar!=pre) {
				pair<int,int> pp=sumsum(tar,cur);
				tot.first+=pp.first;
				tot.second+=pp.second;
			}
		}
		return memo[cur]=tot;
	}
	
	void dfs1(int cur,int pre) {
		int i;
		if(pre!=-1) {
			LL=L[cur];
			RR=R[cur];
			FOR(i,N) memo[i].first=-1;
			sumsum(st1,-1);
			FOR(i,N) if(i!=st1) {
				int mama=max(min(max(memo[i].first,N-(RR-LL)-memo[i].first),N-(RR-LL)),
				             min(max(memo[i].second,RR-LL-memo[i].second),RR-LL));
				ret += mama*(ll)mama;
			}
		}
		
		FOR(i,T[0][cur].size()) {
			int tar=T[0][cur][i];
			if(tar!=pre) dfs1(tar,cur);
		}
	}
	
	long long treeSimilarity(vector <int> tree1, vector <int> tree2) {
		N=tree1.size()+1;
		int i;
		FOR(i,N) T[0][i].clear();
		FOR(i,N) T[1][i].clear();
		FOR(i,N-1) {
			T[0][i].push_back(tree1[i]);
			T[0][tree1[i]].push_back(i);
			T[1][i].push_back(tree2[i]);
			T[1][tree2[i]].push_back(i);
		}
		FOR(i,N) if(T[1][i].size()==1) st1=i;
		ret=0;
		FOR(i,N) if(T[0][i].size()==1) {
			EulerTour(i,-1);
			dfs1(i,-1);
			break;
		}
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, treeSimilarity(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 4, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 111LL; verify_case(1, Arg2, treeSimilarity(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 128LL; verify_case(2, Arg2, treeSimilarity(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 4, 4, 5, 8, 5, 6, 10, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 0, 1, 0, 3, 0, 5, 0, 7, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6306LL; verify_case(3, Arg2, treeSimilarity(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {222, 261, 167, 133, 174, 150, 165, 311, 208, 268, 111, 222, 154, 277, 282, 201, 46, 124, 194, 331, 4, 216, 111, 
275, 72, 322, 137, 216, 241, 48, 72, 101, 232, 165, 151, 263, 139, 16, 122, 140, 84, 135, 314, 106, 309, 126, 102, 
151, 208, 27, 242, 93, 83, 314, 136, 77, 82, 215, 16, 232, 286, 156, 294, 38, 67, 204, 206, 137, 174, 282, 188, 
143, 84, 279, 236, 136, 158, 10, 65, 332, 122, 44, 329, 62, 174, 67, 102, 216, 245, 296, 287, 307, 93, 197, 169, 
268, 266, 294, 157, 277, 95, 68, 214, 135, 211, 127, 82, 108, 212, 161, 243, 212, 207, 119, 119, 158, 97, 290, 21, 
217, 230, 85, 171, 13, 138, 294, 304, 204, 318, 115, 70, 210, 195, 223, 37, 164, 149, 3, 164, 328, 316, 108, 330, 
48, 38, 324, 222, 193, 50, 41, 184, 93, 148, 41, 151, 139, 106, 301, 264, 80, 249, 110, 244, 109, 212, 223, 279, 
330, 67, 27, 301, 165, 236, 194, 3, 157, 1, 217, 311, 87, 105, 4, 286, 37, 6, 31, 111, 66, 230, 227, 244, 322, 
196, 65, 69, 305, 112, 133, 231, 68, 153, 206, 309, 248, 329, 58, 69, 69, 328, 0, 29, 233, 243, 305, 167, 80, 65, 
194, 190, 179, 142, 196, 324, 206, 134, 50, 272, 261, 10, 147, 329, 322, 14, 142, 169, 21, 296, 284, 241, 55, 304, 
150, 166, 230, 167, 304, 87, 156, 156, 97, 274, 324, 196, 101, 82, 106, 260, 242, 233, 207, 305, 10, 166, 53, 18, 
154, 233, 217, 296, 263, 168, 138, 30, 115, 135, 188, 98, 309, 292, 204, 150, 210, 332, 330, 166, 96, 70, 24, 229, 
215, 201, 285, 40, 287, 142, 68, 133, 208, 268, 161, 310, 41, 203, 73, 275, 184, 163, 227, 89, 110, 328, 108, 112, 
125, 164, 127, 179, 267, 221, 49, 139, 1, 84, 136, 38, 6, 70, 246, 243, 3, 188, 297}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {174, 262, 195, 288, 157, 278, 36, 133, 230, 273, 222, 138, 97, 23, 189, 141, 296, 55, 45, 301, 81, 199, 188, 289, 
187, 164, 113, 58, 138, 300, 289, 282, 329, 91, 130, 178, 92, 143, 48, 81, 311, 133, 151, 286, 171, 196, 199, 80, 
83, 121, 65, 151, 277, 136, 49, 111, 58, 36, 259, 14, 31, 9, 136, 181, 122, 324, 249, 114, 9, 37, 259, 242, 165, 
174, 34, 36, 298, 92, 301, 237, 178, 82, 65, 295, 110, 311, 274, 235, 68, 56, 259, 180, 195, 52, 110, 68, 140, 71, 
52, 296, 290, 115, 213, 82, 209, 209, 74, 178, 302, 131, 99, 205, 296, 309, 288, 180, 329, 71, 143, 58, 152, 273, 
196, 7, 169, 88, 231, 331, 213, 181, 80, 249, 170, 246, 16, 127, 75, 276, 332, 174, 21, 180, 163, 78, 242, 312, 
295, 199, 89, 142, 85, 195, 115, 119, 95, 94, 279, 290, 3, 33, 93, 284, 20, 47, 47, 78, 331, 271, 113, 179, 249, 
331, 92, 324, 9, 71, 232, 46, 28, 289, 80, 28, 80, 134, 20, 280, 277, 48, 205, 107, 52, 320, 4, 191, 160, 182, 
189, 227, 295, 115, 54, 195, 78, 292, 189, 273, 301, 69, 305, 36, 222, 167, 326, 106, 48, 45, 74, 61, 181, 311, 
292, 270, 201, 34, 314, 218, 214, 92, 269, 18, 37, 151, 142, 209, 11, 227, 327, 198, 28, 272, 152, 22, 47, 143, 
332, 253, 273, 35, 78, 130, 295, 223, 181, 329, 18, 238, 300, 186, 274, 99, 300, 322, 41, 185, 311, 288, 198, 2, 
37, 83, 238, 133, 122, 178, 107, 106, 66, 238, 69, 90, 38, 109, 246, 278, 288, 250, 321, 269, 130, 28, 115, 122, 
33, 185, 275, 99, 130, 99, 152, 268, 133, 249, 180, 30, 210, 201, 324, 29, 290, 143, 3, 269, 68, 106, 230, 1, 
269, 29, 120, 259, 324, 328, 23, 243, 9, 61, 14, 118, 199, 146, 237, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 11478648052LL; verify_case(4, Arg2, treeSimilarity(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  TreesAnalysis ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
