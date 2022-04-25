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

int S[102];


class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
		vector<int> Xs={0};
		vector<pair<int,int>> ev;
		FORR(v,rectangles) {
			ev.push_back({-v[0],-v[1]});
		}
		int i;
		FOR(i,points.size()) {
			ev.push_back({-points[i][0],i});
		}
		ZERO(S);
		vector<int> R(points.size());
		sort(ALL(ev));
		FORR(e,ev) {
			int y=e.second;
			if(y<0) {
				S[-y]++;
			}
			else {
				int ty=points[y][1];
				for(int i=ty;i<=100;i++) R[y]+=S[i];
			}
			
		}
		return R;
    }
};
