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

int NG[51][51][51];
int INS[51][51][51];
int UP[51][51][51];
int LO[51][51][51];
vector<ll> BX,BY;
ll side[51][51][51];

ll cr(ll x1,ll y1,ll x2,ll y2) {
	ll v=x1*y2-x2*y1;
	if(v>0) return 1;
	if(v<0) return -1;
	return 0;
}

int inside(ll x,ll y,int a,int b,int c) {
	int num=0;
	num += cr(x-BX[a],y-BY[a],BX[b]-BX[a],BY[b]-BY[a]);
	num += cr(x-BX[b],y-BY[b],BX[c]-BX[b],BY[c]-BY[b]);
	num += cr(x-BX[c],y-BY[c],BX[a]-BX[c],BY[a]-BY[c]);
	return abs(num)==3;
}

class RedAndBluePoints {
	public:
	
	int find(vector <int> bx, vector <int> by, vector <int> rx, vector <int> ry) {
		int B=bx.size(), R=rx.size();
		if(B<3) return B;
		
		int ret=2;
		int a,b,c,d,x,y;
		vector <pair<int,int>> P;
		FOR(a,B) P.push_back({bx[a],by[a]});
		sort(P.begin(),P.end());
		BX.clear();
		BY.clear();
		FOR(a,B) BX.push_back(P[a].first),BY.push_back(P[a].second);
		
		FOR(a,B) FOR(b,B) FOR(c,B) {
			NG[a][b][c]=INS[a][b][c]=0;
			side[a][b][c]=(BX[b]-BX[a])*(BY[c]-BY[a])-(BY[b]-BY[a])*(BX[c]-BX[a]);
			FOR(x,R) NG[a][b][c] |= inside(rx[x],ry[x],a,b,c);
			FOR(x,B) INS[a][b][c] += inside(BX[x],BY[x],a,b,c);
		}
		memset(UP,0xcf,sizeof(UP));
		memset(LO,0xcf,sizeof(LO));
		FOR(b,B) FOR(a,b) UP[a][a][b]=LO[a][a][b]=2;
		for(x=2;x<B;x++) {
			FOR(a,x) FOR(b,x) if(a!=b&&NG[a][b][x]==0) FOR(c,x) if(b!=c) {
				if(side[c][b][x]<0) UP[a][b][x]=max(UP[a][b][x],UP[a][c][b]+1+INS[a][b][x]);
				else LO[a][b][x]=max(LO[a][b][x],LO[a][c][b]+1+INS[a][b][x]);
				ret=max(ret,max(UP[a][b][x],LO[a][b][x]));
			}
		}
		FOR(a,B) FOR(b,B) if(a!=b) FOR(c,B) FOR(d,B) if(side[a][b][c]>0 && side[a][b][d]<0) {
			if(side[c][b][d]<0) ret=max(ret,UP[a][c][b]+LO[a][d][b]-2);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {120}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_4() { int Arr0[] = {5, 6, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {971,966,403,780}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {557,264,395,385}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RedAndBluePoints ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
