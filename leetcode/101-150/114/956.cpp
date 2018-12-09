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



bitset<5100> B[5160];
bitset<5100> C[5160];

class Solution {
public:
int tallestBillboard(vector<int>& rods) {
	int N=rods.size();
	int i,j,mask;
	
	ZERO(C);
	ZERO(B);
	B[0][0]=C[0][0]=1;
	
	int sum=0;
	sort(ALL(rods));
	FORR(r,rods) {
		FOR(i,sum+1) C[i+r] |= B[i];
		FOR(i,sum+1) C[i] |= B[i]<<r;
		sum+=r;
		memmove(B,C,sizeof(B));
	}
	
	int ma=0;
	
	FOR(i,5010) if(B[i][i]) ma=i;
	return ma;
    
}

};
