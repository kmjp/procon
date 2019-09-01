
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


map<int,int> M;


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int i;
        
        M.clear();
        FORR(w,words) {
			int mask=0;
			FORR(c,w) mask |= 1<<(c-'a');
			M[mask]++;
		}
		
		vector<int> R;
		FORR(p,puzzles) {
			int mask=0;
			FORR(c,p) mask |= 1<<(c-'a');
			int ret=0;
			for(int i=mask; i>=0; i--) {
				i&=mask;
				if(i&(1<<(p[0]-'a'))) {
					ret+=M[i];
				}
			}
			R.push_back(ret);
			
		}
		return R;
		
		
    }
};


