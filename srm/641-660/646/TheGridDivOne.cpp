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

int dist[200][200];
int block[200][200];

class TheGridDivOne {
	public:
	int find(vector <int> X, vector <int> Y, int K) {
		int N=X.size(),i,j,x,y;
		map<int,int> mx,my;
		
		my[-1]=my[0]=my[1]=0;
		mx[-1]=mx[0]=mx[1]=0;
		FOR(i,N) mx[X[i]-1]=mx[X[i]]=mx[X[i]+1]=0;
		FOR(i,N) my[Y[i]-1]=my[Y[i]]=my[Y[i]+1]=0;
		
		vector<int> rx,ry;
		ITR(it,mx) it->second=rx.size(),rx.push_back(it->first);
		ITR(it,my) it->second=ry.size(),ry.push_back(it->first);
		rx.push_back(1<<30);
		ry.push_back(1<<30);
		
		FOR(i,200) FOR(j,200) dist[i][j]=1<<30;
		ZERO(block);
		FOR(i,N) block[mx[X[i]]][my[Y[i]]]=1;
		
		dist[mx[0]][my[0]]=0;
		priority_queue<pair<ll,int> > q;
		q.push(make_pair(0,mx[0]*1000+my[0]));
		
		while(q.size()) {
			ll d=-q.top().first;
			int cx=q.top().second/1000;
			int cy=q.top().second%1000;
			q.pop();
			if(dist[cx][cy]!=d) continue;
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(tx<0 || tx>=rx.size() || ty<0 || ty>=ry.size()) continue;
				if(block[tx][ty]) continue;
				if(d+abs(rx[cx]-rx[tx])+abs(ry[cy]-ry[ty])<dist[tx][ty]) {
					dist[tx][ty] = d+abs(rx[cx]-rx[tx])+abs(ry[cy]-ry[ty]);
					q.push(make_pair(-dist[tx][ty],tx*1000+ty));
				}
			}
		}
		
		int ma=0;
		FOR(i,rx.size()) FOR(j,ry.size()) if(dist[i][j]<=K)
			ma=max(ma,rx[i]+min(K-dist[i][j],rx[i+1]-rx[i]-1));
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 1000; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 31; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheGridDivOne ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

