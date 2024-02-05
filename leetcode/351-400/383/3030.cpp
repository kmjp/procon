#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

vector<int> V[500][500];
class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
		int H=image.size();
		int W=image[0].size();
		auto A=image;
		int y,x,y1,x1;
		
		FOR(y,H) FOR(x,W) V[y][x].clear();
		FOR(y,H-2) FOR(x,W-2) {
			int sum=0;
			FOR(y1,3) FOR(x1,3) {
				sum+=image[y+y1][x+x1];
				if(y1&&abs(image[y+y1][x+x1]-image[y+y1-1][x+x1])>threshold) {
					sum=-1<<20;
					break;
				}
				if(x1&&abs(image[y+y1][x+x1]-image[y+y1][x+x1-1])>threshold) {
					sum=-1<<20;
					break;
				}
			}
			if(sum>=0) {
				sum/=9;
				FOR(y1,3) FOR(x1,3) {
					V[y+y1][x+x1].push_back(sum);
				}
			}
		}
		
		FOR(y,H) FOR(x,W) {
			if(V[y][x].empty()) A[y][x]=image[y][x];
			else {
				int sum=0;
				FORR(a,V[y][x]) sum+=a;
				A[y][x]=sum/V[y][x].size();
			}
		}
		return A;
        
    }
};
