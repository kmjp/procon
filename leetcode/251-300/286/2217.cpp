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
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
		vector<ll> ret;
		FORR(q,queries) {
			vector<int> V;
			q--;
			int i;
			FOR(i,(intLength+1)/2) {
				if(i==(intLength+1)/2-1) {
					V.push_back(q%9+1);
					q/=9;
				}
				else {
					V.push_back(q%10);
					q/=10;
				}
			}
			if(q) {
				ret.push_back(-1);
			}
			else {
				ll v=0;
				reverse(ALL(V));
				FOR(i,(intLength+1)/2) {
					v=v*10+V[i];
				}
				if(intLength%2==1) V.pop_back();
				reverse(ALL(V));
				FORR(a,V) v=v*10+a;
				ret.push_back(v);
			}
			
		}
        return ret;
    }
};
