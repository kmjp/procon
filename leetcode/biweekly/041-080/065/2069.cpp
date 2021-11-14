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

class Robot {
public:
	int H,W,y,x;
	string S;
    Robot(int width, int height) {
        H=height-1;
        W=width-1;
        y=x=0;
        S="East";
    }
    
    void move(int num) {
		if(num>2*(H+W)) num=num%(2*(H+W))+2*(H+W);
        while(num--) {
			if(y==0&&x<W) {
				S="East";
				x++;
			}
			else if(x==W&&y<H) {
				S="North";
				y++;
			}
			else if(y==H&&x) {
				S="West";
				x--;
			}
			else {
				S="South";
				y--;
			}
		}
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return S;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
 