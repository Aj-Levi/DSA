#include<iostream>
#include<vector>
#include<queue>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;

int visited[8][8];
int level[8][8];

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited[i][j]=0;
            level[i][j]=0;
        }
    }
}
int xcord(string s){
    return s[0]-'a';
}
int ycord(string s){
    return s[1]-'1';
}

vector<pair<int,int> > movements;

bool isvalid(int i,int j){
    return (i>=0 && j>=0 && i<8 && j<8);
}

int bfs(string source, string destination){
    int sourcex=xcord(source);
    int sourcey=ycord(source);
    int destx=xcord(destination);
    int desty=ycord(destination);

    queue<pair<int,int> >q;
    q.push(make_pair(sourcex,sourcey));
    visited[sourcex][sourcey]=1;

    while(!q.empty()){
        pair<int,int> cur_v=q.front();
        q.pop();
        int cur_v_x=cur_v.first;
        int cur_v_y=cur_v.second;
        for(auto &movenment:movements){
            if(!isvalid(cur_v_x+movenment.first,cur_v_y+movenment.second)){
                continue;
            }
            if(!visited[cur_v_x+movenment.first][cur_v_y+movenment.second]){
                q.push(make_pair(cur_v_x+movenment.first,cur_v_y+movenment.second));
                visited[cur_v_x+movenment.first][cur_v_y+movenment.second]=1;
                level[cur_v_x+movenment.first][cur_v_y+movenment.second]=level[cur_v_x][cur_v_y]+1;
            }
        }
        if(level[destx][desty]!=0){
            break;
        }
    }
    return level[destx][desty];
}

int main(){
    movements.push_back(make_pair(1,2));
    movements.push_back(make_pair(1,-2));
    movements.push_back(make_pair(2,1));
    movements.push_back(make_pair(2,-1));
    movements.push_back(make_pair(-1,2));
    movements.push_back(make_pair(-1,-2));
    movements.push_back(make_pair(-2,1));
    movements.push_back(make_pair(-2,-1));
    int t;cin>>t;
    while(t--){
        reset();
        string s1,s2;cin>>s1>>s2;
        cout<<bfs(s1,s2)<<endl;
    }
}