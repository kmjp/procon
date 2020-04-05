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




int from[101][101][101][7];

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
		MINUS(from);
		from[0][0][0][6]=1;
		int x,y,z,i;
		int mx=0,my=0,mz=0,s=0;
		FOR(x,a+1) FOR(y,b+1) FOR(z,c+1) FOR(i,7) if(from[x][y][z][i]>=0) {
			if(x<a && i!=1) from[x+1][y][z][(i==0)?1:0]=i+10;
			if(y<b && i!=3) from[x][y+1][z][(i==2)?3:2]=i+20;
			if(z<c && i!=5) from[x][y][z+1][(i==4)?5:4]=i+30;
			
			if(from[x][y][z][i]>=0 && x+y+z>mx+my+mz) mx=x,my=y,mz=z,s=i;
		}
		
		string S;
		while(mx+my+mz>0) {
			int i=from[mx][my][mz][s]/10;
			int j=from[mx][my][mz][s]%10;
			
			if(i==1) S.push_back('a'),mx--,s=j;
			if(i==2) S.push_back('b'),my--,s=j;
			if(i==3) S.push_back('c'),mz--,s=j;
		}
		return S;
		
		
		
		
    }
};

