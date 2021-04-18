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
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> R;
		FORR(q,queries) {
			int num=0;
			FORR(p,points) {
				if((p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1])<=q[2]*q[2]) num++;
			}
			R.push_back(num);
		}
        return R;
    }
};
