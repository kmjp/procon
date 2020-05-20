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


class Solution {
public:
	int num(vector<vector<int>>& points,double x,double y,int r) {
		int ret=0;
		FORR(p,points) if((p[0]-x)*(p[0]-x)+(p[1]-y)*(p[1]-y)<=r*r+1e-6) ret++;
		return ret;
	}
    int numPoints(vector<vector<int>>& points, int r) {
        int ma=1;
        int N=points.size();
        FORR(p,points) p[0]*=4,p[1]*=4;
        r*=4;
        
        int i,j,k;
        FOR(i,N) {
			ma=max(ma,num(points,points[i][0],points[i][1],r));
			FOR(j,i) {
				ma=max(ma,num(points,(points[i][0]+points[j][0])/2,(points[i][1]+points[j][1])/2,r));
				if(hypot(points[i][0]-points[j][0],points[i][1]-points[j][1])<=2*r) {
					int mx=(points[i][0]+points[j][0])/2;
					int my=(points[i][1]+points[j][1])/2;
					double dx=(points[i][0]-points[j][0])/2;
					double dy=(points[i][1]-points[j][1])/2;
					double d=hypot(dx,dy);
					dx/=d;
					dy/=d;
					double len=sqrt(r*r-(mx-points[i][0])*(mx-points[i][0])-(my-points[i][1])*(my-points[i][1]));
					dx*=len;
					dy*=len;
					ma=max(ma,num(points,mx+dy,my+dx,r));
					ma=max(ma,num(points,mx+dy,my-dx,r));
					ma=max(ma,num(points,mx-dy,my+dx,r));
					ma=max(ma,num(points,mx-dy,my-dx,r));
					
					
				}
			}
		}
        return ma;
    }
};
