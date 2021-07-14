#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main(){
    int ladders,snakes;
    cin>>ladders;
    map<int,int> lad;
    map<int,int> snk;
    for(int i=0;i<ladders;i++){
        int u,v;
        cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int u,v;
        cin>>u>>v;
        snk[u]=v;
    }
    int moves =0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101,0);
    vis[1] = true;
    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die = 1;die<=6;die++){
                if(t+die==100){
                    found=true;
                }
                if(t+die<=100 and lad[t+die] and !vis[lad[t+die]]){
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die<=100 and snk[t+die] and !vis[snk[t+die]]){
                    vis[snk[t+die]]=true;
                    if(snk[t+die]==100){
                        found = true;
                    }
                    q.push(snk[t+die]);
                }
                else if(t+die and !vis[t+die] and !snk[t+die] and !lad[t+die]){
                    vis[t+die]=true;
                    q.push(t+die);

                }

            }
        }
        moves++;
    }
    if(found){
        cout<<moves;
    }else{
        cout<<-1;
    }

    
    return 0;
}