typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


double from[25][25][9][9];
double to[25][25][9][9];

double comb(int P_,int Q_) {
	static const int N_=1020;
	static double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

class Solution {
public:
    double getProbability(vector<int>& balls) {
		int N=balls.size();
		int sum=0;
		FORR(b,balls) sum+=b;
		
		int i;
		double fact[51];
		fact[0]=1;
		for(int i=1;i<=50;i++) fact[i]=fact[i-1]*i;
		
		ZERO(from);
		from[0][0][0][0]=1;
		FOR(i,N) {
			ZERO(to);
			int a,b,x,y,c;
			FOR(a,sum/2+1) FOR(b,sum/2+1) FOR(x,i+1) FOR(y,i+1) if(from[a][b][x][y]) {
				FOR(c,balls[i]+1) if(a+c<=sum/2 && b+balls[i]-c<=sum/2) {
					int d=balls[i]-c;
					to[a+c][b+d][x+(c>0)][y+(d>0)]+=from[a][b][x][y]*comb(a+c,c)*comb(b+d,d);
				}
			}
			
			swap(from,to);
		}
        
        double ret=0;
        FOR(i,9) ret+=from[sum/2][sum/2][i][i];
		sum=0;
		FORR(b,balls) {
			sum+=b;
			ret/=comb(sum,b);
		}
        
        return ret;
        
    }
};


