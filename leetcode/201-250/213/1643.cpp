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


ll C[32][32];


class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int x,y;
        FOR(x,31) FOR(y,x+1) {
			if(y==0||y==x) C[x][y]=1;
			else C[x][y]=C[x-1][y]+C[x-1][y-1];
		}
        int W=destination[1];
        int H=destination[0];
        string S;
        x=y=0;
        cout<<C[H+W][W]<<endl;
        while(y<H||x<W) {
			if(x==W) {
				S+='V';
				y++;
			}
			else if(y==H) {
				S+='H';
				x++;
			}
			else {
				ll num=C[W+H-(x+1)-y][W-(x+1)];
				cout<<num<<" "<<k<<endl;
				if(k<=num) {
					S+='H';
					x++;
				}
				else {
					k-=num;
					S+='V';
					y++;
				}
			}
			
		}
		return S;
    }
};
