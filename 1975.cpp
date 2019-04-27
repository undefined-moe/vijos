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
#include <iostream>
using namespace std;
int n, m, map[110][110];
char ch;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == '*')
                map[i][j] = -1;
            else
                map[i][j] = 0;
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (map[i][j] == -1) {
                if (i > 1 && map[i - 1][j] >= 0) map[i - 1][j]++;
                if (j > 1 && map[i][j - 1] >= 0) map[i][j - 1]++;
                if (i < n && map[i + 1][j] >= 0) map[i + 1][j]++;
                if (j < m && map[i][j + 1] >= 0) map[i][j + 1]++;
                if (i > 1 && j > 1 && map[i - 1][j - 1] >= 0) map[i - 1][j - 1]++;
                if (i > 1 && j < m && map[i - 1][j + 1] >= 0) map[i - 1][j + 1]++;
                if (i < n && j > 1 && map[i + 1][j - 1] >= 0) map[i + 1][j - 1]++;
                if (i < n && j < m && map[i + 1][j + 1] >= 0) map[i + 1][j + 1]++;
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (map[i][j] == -1)
                cout << '*';
            else
                cout << map[i][j];
        cout << endl;
    }
    return 0;
}