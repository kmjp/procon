#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

pair<int,int> from[100][22];

class TigerMaster {
	public:
	vector <int> train(int N, int M, vector <int> X, vector <int> Y, vector <int> D) {
		vector<pair<int,int>> E;
		int i;
		FOR(i,M) {
			E.push_back({D[i],i});
		}
		MINUS(from);
		FOR(i,N) from[i][0]={0,0};
		
		int j;
		sort(ALL(E));
		FORR(e,E) {
			int i=e.second;
			int x=X[i],y=Y[i];
			for(j=19;j>=0;j--) {
				if(from[x][j].first>=0&&from[y][j+1].first==-1) {
					from[y][j+1]={i,x};
				}
				if(from[y][j].first>=0&&from[x][j+1].first==-1) {
					from[x][j+1]={i,y};
				}
			}
		}
		FOR(i,N) if(from[i][20].first>=0) {
			int cur=i,step=20;
			vector<int> R;
			while(step) {
				int a=from[cur][step].first;
				int b=from[cur][step].second;
				R.push_back(a);
				cur=b;
				step--;
			}
			R.push_back(cur);
			reverse(ALL(R));
			return R;
		}
		return {};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 23; int Arr2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 21, 6, 1, 19, 22, 3, 10, 14, 13, 12, 2, 8, 15, 0, 9, 7, 17, 4, 20, 5 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, train(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 30; int Arr2[] = {1, 2, 2, 2, 2, 0, 0, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 0, 1, 0, 2, 0, 2, 0, 0, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 2, 0, 0, 1, 1, 0, 0, 0, 2, 1, 2, 2, 1, 1, 2, 0, 1, 2, 2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {55, 73, 50, 53, 13, 61, 72, 30, 91, 76, 73, 16, 46, 65, 12, 89, 60, 98, 45, 98, 33, 72, 39, 33, 14, 48, 1, 80, 79, 55}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 26, 14, 4, 24, 11, 7, 23, 18, 12, 25, 2, 0, 16, 5, 6, 21, 1, 10, 9, 28 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, train(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TigerMaster ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

