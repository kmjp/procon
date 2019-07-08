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
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> R;
        int A=0,B=0;
        FORR(c,seq) {
			if(c=='(') {
				if(A<=B) {
					A++;
					R.push_back(0);
				}
				else {
					B++;
					R.push_back(1);
				}
			}
			else {
				if(A>=B) {
					A--;
					R.push_back(0);
				}
				else {
					B--;
					R.push_back(1);
				}
			}
		}
        return R;
        
    }
};

