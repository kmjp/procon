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

template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size();
	if(v.empty()) return 0;
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	// FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i]-1; ìØÇ∂êîílÇÃòAë±Ç‡ãñâ¬Ç∑ÇÈèÍçá
	return *max_element(id.begin(),id.end())+1;
}

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
		vector<pair<int,int>> A,B;
		int i,x,y;
		FOR(i,coordinates.size()) if(i!=k) {
			x=coordinates[i][0]-coordinates[k][0];
			y=coordinates[i][1]-coordinates[k][1];
			if(x>0&&y>0) A.push_back({x,-y});
			if(x<0&&y<0) {
				x=-x;
				y=-y;
				B.push_back({x,-y});
			}
		}
        sort(ALL(A));
        sort(ALL(B));
        vector<int> X,Y;
        FORR(a,A) X.push_back(-a.second);
        FORR(a,B) Y.push_back(-a.second);
        return LIS_num(X)+LIS_num(Y)+1;
    }
};
