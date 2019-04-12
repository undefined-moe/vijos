/*                        ..
                        .' @`._
         ~       ...._.'  ,__.-;
      _..- - - /`           .-'    ~
     :     __./'       ,  .'-'- .._
  ~   `- -(.-'''- -.    \`._       `.   ~
    _.- '(  .______.'.-' `-.`         `.
   :      `-..____`-.                   ;
   `.             ````  稻花香里说丰年，  ;   ~
     `-.__          听取人生经验。  __.-'
          ````- - -.......- - -'''    ~
       ~                   ~
-------------------------------------
|           Code by masnn           |
|        Email:admin@masnn.ml       |
|            Do not copy            |
-----------------------------------*/
#include<iostream>
using namespace std;
int n,m,map[600][600],cnt;
char ch;
void put(int x,int y){
    map[x][y]=1;
    if (x>1) if (map[x-1][y]==0) put(x-1,y);
    if (y>1) if (map[x][y-1]==0) put(x,y-1);
    if (x<n) if (map[x+1][y]==0) put(x+1,y);
    if (y<m) if (map[x][y+1]==0) put(x,y+1);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>ch;
            if (ch=='*') map[i][j]=-1;
            else map[i][j]=0;
        }
    for(int i=1;i<=n;i++){
        if (map[i][1]==0) put(i,1);
        if (map[i][m]==0) put(i,m);
    }
    for(int i=1;i<=m;i++){
        if (map[1][i]==0) put(1,i);
        if (map[n][i]==0) put(n,i);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (map[i][j]==0) cnt++;
    cout<<cnt<<endl;
    return 0;
}