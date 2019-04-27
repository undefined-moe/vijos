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
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct DATA {
    string name, score;
} d[1010];
int n;
bool cmp(DATA a, DATA b) {
    if (a.score.length() > b.score.length()) return true;
    if (a.score.length() < b.score.length()) return false;
    for (int i = 0; i < a.score.length(); i++) {
        if (a.score[i] > b.score[i]) return true;
        if (a.score[i] < b.score[i]) return false;
    }
    return a.name < b.name;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i].name >> d[i].score;
    sort(d + 1, d + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << d[i].name << endl;
    return 0;
}