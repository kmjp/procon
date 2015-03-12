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

class NoRightTurnDiv2 {
	public:
	vector<int> X,Y;
	
	bool okok(vector<int> R) {
		int s,t;
		FOR(t,R.size()-1) FOR(s,t-1) {
			ll dx1=X[R[s+1]]-X[R[s]];
			ll dy1=Y[R[s+1]]-Y[R[s]];
			ll dx2=X[R[t]]-X[R[s]];
			ll dy2=Y[R[t]]-Y[R[s]];
			ll dx3=X[R[t+1]]-X[R[s]];
			ll dy3=Y[R[t+1]]-Y[R[s]];
			
			if((((dx1*dy2-dx2*dy1)<0) ^ ((dx1*dy3-dx3*dy1)<0))==0) continue;
			dx1=X[R[t+1]]-X[R[t]];
			dy1=Y[R[t+1]]-Y[R[t]];
			dx2=X[R[s]]-X[R[t]];
			dy2=Y[R[s]]-Y[R[t]];
			dx3=X[R[s+1]]-X[R[t]];
			dy3=Y[R[s+1]]-Y[R[t]];
			if((((dx1*dy2-dx2*dy1)<0) ^ ((dx1*dy3-dx3*dy1)<0))==0) continue;
			return false;
			
		}
		return true;
		
	}
	
	vector <int> findPath(vector <int> x, vector <int> y) {
		X=x, Y=y;
		int N=X.size(),i,s[2];
		double pi=acos(-1);
		
		FOR(s[0],N) FOR(s[1],N) if(s[0]!=s[1]) {
			int vis[60]={};
			int p=s[0], q=s[1];
			
			vis[s[0]]=vis[s[1]]=1;
			vector<int> R;
			R.push_back(s[0]);
			R.push_back(s[1]);
			
			while(R.size()<N) {
				double ang=atan2(Y[q]-Y[p],X[q]-X[p]);
				double mia=pi;
				int id=-1;
				
				FOR(i,N) if(vis[i]==0) {
					double ma=atan2(Y[i]-Y[q],X[i]-X[q])-ang;
					while(ma<0) ma += 2*pi;
					if(ma<mia) mia=ma, id=i;
				}
				if(id==-1) break;
				R.push_back(id);
				vis[id]=1;
				p=q;
				q=id;
			}
			
			if(R.size()==N && okok(R)) return R;
		}
		return vector<int>();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-10, 0, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, -10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findPath(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,-3,-3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,1,-3,3,-3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 4, 5, 3, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findPath(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,9,16,25,36,49,64,81,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findPath(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 2,-2, 4,-4, 2,-2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 2, 4, 4, 6, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 2, 0, 1, 3, 5, 6, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findPath(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10,
55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47,
9,39,42,63,-97,94}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9,
42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78,
-99,57,67,-52,-46,61,-10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findPath(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NoRightTurnDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

