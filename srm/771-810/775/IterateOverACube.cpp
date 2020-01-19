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


ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_, q=q*i,P_--;
	
	return p/q;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}


ll pat[3030303];

class IterateOverACube {
	public:
	vector <int> findCell(int N, long long index) {
		int i;
		ll ret=0;
		index++;
		FOR(i,3*N-2) {
			pat[i]=comb(i+2,2);
			if(i>=N) pat[i]-=3*comb(i+2-N,2);
			if(i>=2*N) pat[i]+=3*comb(i+2-2*N,2);
			ret+=pat[i];
			
			if(index<=pat[i]) {
				for(int x=0;x<=min(i,N-1);x++) {
					int left=i-x;
					if(left<=N-1) {
						int num=left+1;
						if(index<=num) return {x,index-1,left-(index-1)};
						index-=num;
					}
					else {
						if(left>2*N-2) continue;
						int num=2*N-1-left;
						if(index<=num) {
							for(int y=0;y<=N-1;y++) {
								int z=i-x-y;
								if(z>=0 && z<=N-1) {
									index--;
									if(index==0) return {x,y,z};
								}
							}
						}
						index-=num;
						
					}
					
				}
			}
			else {
				index-=pat[i];
			}
			
		}
		
		return {};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 9LL; int Arr2[] = {2, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findCell(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 10LL; int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findCell(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4747; long long Arg1 = 106968940722LL; int Arr2[] = {4746, 4746, 4746 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findCell(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; long long Arg1 = 32LL; int Arr2[] = {0, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findCell(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IterateOverACube ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

