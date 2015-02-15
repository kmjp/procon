#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class ShadowSculpture {
	public:
	int N;
	int bl[11][11][11];
	int con[11][11][11];
	
	void conn(int sx,int sy,int sz) {
		int x,y,z,i;
		ZERO(con);
		if(bl[sz][sy][sx]==0) return;
		
		queue<int> Q;
		con[sz][sy][sx]=1;
		Q.push(sz*10000+sy*100+sx);
		while(Q.size()) {
			int k=Q.front();
			Q.pop();
			int sz=k/10000,sy=k/100%100,sx=k%100;
			FOR(i,6) {
				int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
				int tx=sx+dx[i],ty=sy+dy[i],tz=sz+dz[i];
				if(tx<0 || ty<0 || tx>=N || ty>=N || tz<0 || tz>=N) continue;
				if(bl[tz][ty][tx]==0 || con[tz][ty][tx]) continue;
				con[tz][ty][tx]=1;
				Q.push(tz*10000+ty*100+tx);
			}
		}
	}
	
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		string po="Possible";
		string im="Impossible";
		
		int x,y,z,sx,sy,sz;
		N=XY.size();
		
		FOR(y,N) FOR(x,N) FOR(z,N) bl[z][y][x]=1;
		FOR(y,N) FOR(x,N) if(XY[x][y]=='N') FOR(z,N) bl[z][y][x]=0;
		FOR(z,N) FOR(x,N) if(ZX[z][x]=='N') FOR(y,N) bl[z][y][x]=0;
		FOR(z,N) FOR(y,N) if(YZ[y][z]=='N') FOR(x,N) bl[z][y][x]=0;
		
		FOR(sz,N) FOR(sy,N) FOR(sx,N) {
			conn(sx,sy,sz);
			int ok=1;
			FOR(y,N) FOR(x,N) {
				int bll=0;
				FOR(z,N) bll+=bl[z][y][x]&&con[z][y][x];
				if(XY[x][y]=='Y' && bll==0) ok=0;
			}
			FOR(z,N) FOR(x,N) {
				int bll=0;
				FOR(y,N) bll+=bl[z][y][x]&&con[z][y][x];
				if(ZX[z][x]=='Y' && bll==0) ok=0;
			}
			FOR(z,N) FOR(y,N) {
				int bll=0;
				FOR(x,N) bll+=bl[z][y][x]&&con[z][y][x];
				if(YZ[y][z]=='Y' && bll==0) ok=0;
			}
			if(ok) return po;
		}
		
		return im;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
//	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NNN", "NNN", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN", "YNN", "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNY", "NNN", "NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }
// END CUT HERE

};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShadowSculpture ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
