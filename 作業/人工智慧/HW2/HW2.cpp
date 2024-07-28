#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

typedef struct MapNode{
    char amap[30];
    char level;
    char action;
    MapNode *ptr;
} MapNode;

char VISITED[1000000000];
MapNode TREE[2000000];
int COUNT = 0, TotalNode=0;
char ACTION_STRING[5][15] = {"             ", " jump left,  ", " move left,  ", " jump right, ", " move right, "};

int main(){
    memset(VISITED, 0, sizeof(char) * 1000000000);

    int num, amap[30] = {0}, target[30] = {0};
    // input
    cin >> num;
    for(int i = 0;i < num;i++){
        cin >> amap[i];
    }
    for(int i = 0;i < num;i++){
        cin >> target[i];
    }
    // queue initialize
    queue<MapNode> q;
    MapNode initial, *result;
    for(int i = 0;i < num;i++){
        initial.amap[i] = amap[i];
        initial.level = 1;
        initial.action = 0;
        initial.ptr = 0;
    }
    q.push(initial);
    // use queue to search
    while(q.empty() == false){
        MapNode node = q.front();
        q.pop();
        // check if duplicated

        int sum = 0;
        for(int i = 0;i < num;i++){
            sum *= 10;
            sum += node.amap[i];
        }
        cout << sum << " node.level " << (int)node.level << endl;
        if( !VISITED[sum] ){
            //cout << "sum: " << sum << "     VISITED[" << sum << "] : " << (int) VISITED[sum] << endl;
            VISITED[sum] = true;
        }
        else{
            //cout << "used" << endl;
            continue;
        }
        // add node to tree array
        TREE[COUNT] = node;
        // check if found the target
        bool found = true;
        for(int i = 0;i < num;i++){
            if(node.amap[i] != target[i]){
                found = false;
                break;
            }
        }
        if(found){
            result = &TREE[COUNT]; // get the address for every action
            break;
        }

        // get position of zero
        int zero_pos;
        for(zero_pos = 0;zero_pos < num;zero_pos++){
            if(node.amap[zero_pos] == 0){
                break;
            }
        }
        // search
        int exchange[4] = {zero_pos - 2, zero_pos - 1, zero_pos + 2, zero_pos + 1};
        for(int i = 0; i < 4; i++){
            if(exchange[i] >= 0 && exchange[i] < num){
                MapNode b = node;
                b.ptr = &TREE[COUNT];
                b.action = i + 1;
                b.level++;
                b.amap[exchange[i]] = 0;
                b.amap[zero_pos] = node.amap[exchange[i]];
                q.push(b);
                TotalNode++;
            }
        }
        COUNT++;
    }
    // add node to stack,for print
    stack<MapNode> s;
    while(true){
        s.push(*result);
        if(result->ptr == 0){
            break;
        }
        *result = *result->ptr;
    }
    // output
    cout << "find depth = " << s.size() - 1 << endl;
    cout << "total nodes(visited) = " << COUNT << endl;
    cout << "total nodes(generated) = " << TotalNode << endl;

    while(s.empty() == false){
        MapNode node = s.top();
        s.pop();
        cout << (int)(node.level - 1) << ACTION_STRING[node.action];
        for(int i = 0;i < num;i++){
            cout << (int)node.amap[i];
        }
        cout << endl;
    }
    return 0;
}
