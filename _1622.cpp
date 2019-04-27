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
#include<cstring>
#include<stack>
using namespace std;
string KeyWord,op;
char ch;
int count;
struct folder{
    string name;
    int count;
};
folder toFolder(string name,int count){
    folder temp;
    temp.name=name;
    temp.count=count;
    return temp;
}
class STACK{
    private:
        int depth;
        folder data[7000];
    public:
        string getpath(){
            string temp;
            for(int i=2;i<=depth;i++)
                temp+=data[i].name+'\\';
            return temp;
        }
        void newFolder(string name,int count){
            depth++;
            data[depth]=toFolder(name,count);
        }
        void dec(){
            data[depth].count--;
            if (data[depth].count==0) depth--;
        }
        void update(){
            while (data[depth].count==0)
                depth--;
        }
}DATA;
bool isFileName(string name){
    for(int i=0;i<=name.length();i++)
        if (name[i]=='.') return true;
    return false;
}
int main(){
    DATA.newFolder("a",9999);
    cin>>KeyWord;
    while (cin>>op){
        if (!isFileName(op)){
            cin>>count;
            DATA.dec();
            DATA.newFolder(op,count);
        }else{
            DATA.update();
            if (op==KeyWord)
                cout<<DATA.getpath()<<op<<endl;
            DATA.dec();
        }
    }
    return 0;
}