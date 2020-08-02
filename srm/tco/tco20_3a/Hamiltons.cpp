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



int dp[1<<14][14];
int dp2[1<<14][14][14][14];
int C[14][14];

class Hamiltons {
	public:
	
	int Maru(int N) {
		int i,mask,j;
		
		FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1<<20;
		FOR(i,N) dp[1<<i][i]=0;
		FOR(mask,1<<N) {
			FOR(i,N) if(mask&(1<<i)) {
				int cur=dp[mask][i];
				FOR(j,N) if((mask&(1<<j))==0) {
					dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],cur+C[i][j]);
				}
			}
		}
		int mi=1<<30;
		FOR(i,N) mi=min(mi,dp[(1<<N)-1][i]);
		//cout<<mi<<endl;
		return mi;
	}
	int Vlado(int N) {
		int i,mask,x,y,j;
		
		FOR(mask,1<<N) FOR(i,N) FOR(x,N) FOR(y,N) dp2[mask][i][x][y]=1<<20;
		FOR(x,N) FOR(y,N) if(x!=y) dp2[(1<<x)|(1<<y)][x][y][y]=C[x][y];
		FOR(mask,1<<N) {
			FOR(x,N) if(mask&(1<<x)) {
				FOR(y,N) if(mask&(1<<y)) {
					FOR(i,N) if(mask&(1<<i)) {
						FOR(j,N) if((mask&(1<<j))==0 && C[i][j]<=C[x][y]) {
							dp2[mask|(1<<j)][x][y][j]=min(dp2[mask|(1<<j)][x][y][j],dp2[mask][x][y][i]+C[i][j]);
						}
					}
				}
			}
		}
		int mi=1<<30,mle=1<<30;
		FOR(x,N) FOR(y,N) FOR(i,N) if(C[x][y]>=C[i][x]) {
			if(dp2[(1<<N)-1][x][y][i]+C[i][x]<mi) {
				mi=dp2[(1<<N)-1][x][y][i]+C[i][x];
				mle=0;
			}
			if(dp2[(1<<N)-1][x][y][i]+C[i][x]==mi) mle=max(mle,C[x][y]);
		}
		//cout<<mi<<" "<<mle<<" "<<mi-mle<<endl;
		return mi-mle;
	}
	
	vector <int> construct(int N, int L) {
		
		int XY,Z;
		int x,y;
		FOR(x,N) FOR(y,N) C[x][y]=L;
		
		for(Z=1;Z<=L;Z++) {
			for(XY=2;XY<=2*L;XY++) {
				if(N*Z<XY+(N-3)*Z+L && (N-1)*Z>=XY+(N-3)*Z+(L+1)/2) {
					FOR(x,N) C[x][(x+1)%N]=C[(x+1)%N][x]=Z;
					C[0][2]=C[2][0]=XY/2;
					C[3][5]=C[5][3]=XY-XY/2;
					goto out;
				}
			}
		}
		out:
		
		assert(Vlado(N)-Maru(N)>=(L+1)/2);
		
		
		vector<int> R;
		FOR(x,N) for(y=x+1;y<N;y++) R.push_back(C[x][y]);
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

	void test_case_0() { int x,y;	for(x=6;x<=14;x++) for(y=10;y<=1000;y++) {
		cout<<x<<" "<<y<<endl;
		construct(x,y);
	}
		}
	void _test_case_1() { int Arg0 = 14; int Arg1 = 999; int Arr2[] = {174, 325, 60, 839, 248, 437, 398, 965, 806, 658, 985, 969, 319, 100, 149 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void _test_case_0() { int Arg0 = 6; int Arg1 = 1000; int Arr2[] = {174, 325, 60, 839, 248, 437, 398, 965, 806, 658, 985, 969, 319, 100, 149 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Hamiltons ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

