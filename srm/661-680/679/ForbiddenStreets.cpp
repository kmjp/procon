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

vector<pair<int,int> > E[101];
ll dist[101][101];
ll pat[2][101][101];
ll mo[2]={1000000007,1000000009};

class ForbiddenStreets {
	public:
	vector <int> find(int N, vector <int> A, vector <int> B, vector <int> time) {
		int i,j,x,y;
		
		FOR(x,N) E[x].clear();
		FOR(x,A.size()) E[A[x]].push_back({B[x],time[x]});
		FOR(x,A.size()) E[B[x]].push_back({A[x],time[x]});
		
		FOR(x,N) FOR(y,N) dist[x][y]=10000000;
		priority_queue<pair<int,int>> Q;
		FOR(x,N) dist[x][x]=0,pat[0][x][x]=pat[1][x][x]=1, Q.push({0,x*100+x});
			
		while(Q.size()) {
			auto q=Q.top();
			Q.pop();
			
			int co=-q.first;
			int st=q.second%100;
			int cur=q.second/100;
			if(dist[st][cur]!=co) continue;
			FORR(r,E[cur]) {
				if(dist[st][r.first]>co+r.second) {
					dist[st][r.first]=co+r.second;
					Q.push({-dist[st][r.first],st*100+r.first});
					pat[0][st][r.first]=pat[1][st][r.first]=0;
				}
				if(dist[st][r.first]==co+r.second) {
					(pat[0][st][r.first]+=pat[0][st][cur])%=mo[0];
					(pat[1][st][r.first]+=pat[1][st][cur])%=mo[1];
				}
			}
		}
		
		vector<int> V(A.size());
		FOR(i,A.size()) {
			int a=A[i],b=B[i];
			FOR(x,N) FOR(y,N) if(dist[x][a]+time[i]+dist[y][b]==dist[x][y]) {
				if(pat[0][x][y]==pat[0][x][a]*pat[0][b][y]%mo[0]&&
				   pat[1][x][y]==pat[1][x][a]*pat[1][b][y]%mo[1])
				   	V[i]++;
			}
		}
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 4, 3 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0,0,0,0,1,1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,2,3,4,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 4, 4, 4, 0, 0, 0, 0, 0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {0,0,0,0,1,1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,2,3,4,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,1,2,1,2,1,2,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 0, 1, 0, 1, 0, 1, 1, 1, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 3; int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 13; int Arr1[] = {12,12,12,12,6,6,0,6,9,1,6,6,9,11,4,0,1,4,11,2,4,0,0,10,12,3,9,7,7,2,9,12,1,10,6,9,0,3,1,1,7,3,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,1,6,7,0,8,11,10,5,4,3,2,11,3,5,4,11,2,6,10,11,12,2,7,2,7,0,4,5,11,8,3,10,12,4,2,5,4,5,2,8,10,3,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {764,541,173,212,568,783,863,68,930,23,70,394,230,920,199,371,92,874,997,328,314,896,815,751,789,652,933,369,227,602,318,281,445,730,98,928,498,20,341,724,847,351,35,492}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0, 12, 4, 0, 0, 0, 12, 0, 35, 26, 0, 21, 0, 9, 10, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 3, 0, 11, 0, 0, 0, 0, 0, 2, 36, 0, 0, 1, 0, 12, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ForbiddenStreets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
