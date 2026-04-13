class Robot {
public:
    int idx = 0;
    vector<vector<int>> pos;
    bool moved = false;
    Robot(int width, int height) {
        //bottom
        for(int x = 0;x < width; x++){
            pos.push_back({x,0,0});
        }
        //right
        for(int y=1; y<height; y++){
            pos.push_back({width -1, y, 1});
        }
        //top
        for(int x=width-2 ; x>=0 ; x--){
            pos.push_back({x,height-1,2});
        }
        //left
        for(int y=height-2; y>0; y--){
            pos.push_back({0,y,3});
        }
        //corner case
        pos[0][2] = 3;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx+num)%pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0],pos[idx][1]};
    }
    
    string getDir() {
        if(moved == false) return "East";
        if(pos[idx][2] == 0){
            return "East";
        }
        else if(pos[idx][2] == 1){
            return "North";
        }
        else if(pos[idx][2] == 2){
            return "West";
        }else{
            return "South";
        }
    }
};
