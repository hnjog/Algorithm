#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health;
    int time = 0;
    int hilltime = bandage[0];
    int hps = bandage[1];
    int fullhill = bandage[2];
    
    for(auto& a : attacks)
    {
        int atime = a[0];
        int amount = a[1];
        
        int t = atime - time;
        time = atime;
        
        if(t > 1)
        {
            t--;
            hp += (hps * t);
            hp += (fullhill * (t / hilltime));
            if(hp > health)
                hp = health;    
        }
        
        
        hp -= amount;
        
        if(hp <= 0)
            return -1;
    }
    
    return hp;
}