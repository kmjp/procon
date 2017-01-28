#include <bits/stdc++.h>
using namespace std;
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

int H,W;

int hoge(vector<vector<int>>& A, int cy, int cx) {
	if(cy<0 || cy>=H || cx<0 || cx>=W) return 0;
	if(A[cy][cx]==0) return 0;
	A[cy][cx]=0;
	return 1+hoge(A,cy-1,cx)+hoge(A,cy+1,cx)+hoge(A,cy,cx+1)+hoge(A,cy,cx-1);
}

int largestMatrixZone(vector<vector<int>>& A) {
    H=A.size();
    W=A[0].size();
    
    int x,y;
    FOR(y,H) hoge(A,y,0),hoge(A,y,W-1);
    FOR(x,W) hoge(A,0,x),hoge(A,H-1,x);
    
    int ma=0;
    FOR(y,H) FOR(x,W) ma=max(ma,hoge(A,y,x));
    if(ma==0) ma=-1;
    return ma;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    
    cout << largestMatrixZone(A) << "\n";
    return 0;
}