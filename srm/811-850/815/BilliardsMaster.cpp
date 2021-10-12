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

class BilliardsMaster {
	public:
	vector <int> play(int tx, int ty, int sx, int sy, int fx, int fy, int b) {
		vector<vector<ll>> cand;
		
		for(int bx=-b;bx<=b;bx++) {
			for(int i=-1;i<=1;i+=2) {
				int by=i*(b-abs(bx));
				
				ll ax=0,ay=0;
				if(bx%2==0) ax=fx+1LL*bx*tx;
				else ax=(2*tx-fx)+1LL*(bx-1)*tx;
				if(by%2==0) ay=fy+1LL*by*ty;
				else ay=(2*ty-fy)+1LL*(by-1)*ty;
				
				ll d=(ax-sx)*(ax-sx)+(ay-sy)*(ay-sy);
				
				vector<ll> a;
				a.push_back(d);
				if(bx>=0) {
					a.push_back(abs(bx)/2); //ç∂
					a.push_back(abs(bx)-abs(bx)/2); //âE
				}
				else {
					a.push_back(abs(bx)-abs(bx)/2); //ç∂
					a.push_back(abs(bx)/2); //âE
				}
				if(by>=0) {
					a.push_back(abs(by)-abs(by)/2); //â∫
					a.push_back(abs(by)/2); //è„
				}
				else {
					a.push_back(abs(by)/2); //è„
					a.push_back(abs(by)-abs(by)/2); //â∫
				}
				cand.push_back(a);
				if(by==0) break;
			}
			
		}
		sort(ALL(cand));
		vector<int> V={0,0,0,0};
		FORR(r,cand) {
			if(r[0]==cand[0][0]) {
				V[0]=max(V[0],(int)r[1]);
				V[1]=max(V[1],(int)r[2]);
				V[2]=max(V[2],(int)r[3]);
				V[3]=max(V[3],(int)r[4]);
			}
		}
		
		sort(ALL(V));
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 0; int Arr7[] = {0, 0, 0, 0 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(0, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 1; int Arr7[] = {1, 1, 1, 1 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(1, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 2; int Arr7[] = {1, 1, 1, 1 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(2, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 4; int Arg3 = 2; int Arg4 = 4; int Arg5 = 2; int Arg6 = 1; int Arr7[] = {0, 0, 1, 1 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(3, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 3; int Arg2 = 47; int Arg3 = 1; int Arg4 = 48; int Arg5 = 2; int Arg6 = 8; int Arr7[] = {0, 0, 4, 4 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(4, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 1; int Arg6 = 0; int Arr7[] = {0, 0, 0, 0 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(5, Arg7, play(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BilliardsMaster ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

