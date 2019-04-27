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
#include <vector>
using namespace std;
int n, root;
struct node {
    long long score, left, right, parent;
};
struct tree_str {
    node tree[50];
} tree, treedmp;
struct d {
    vector<int> data;
    long long score;
};
d toData(vector<int> data, long long score) {
    d temp;
    temp.data = data;
    temp.data.push_back(root);
    temp.score = score;
    return temp;
}
d build(int l, int r) {
    if (l > r) return toData(vector<int>(-1), 1);
    if (l == r) return toData(vector<int>(l), 2 + tree.tree[r].score);
    long long t = 0, ans = 0, root = 0;
    d ldata, rdata;
    for (int i = l; i <= r; i++) {
        tree.tree[i].parent = 0;
        ldata = build(l, i - 1);
        rdata = build(i + 1, r);
        t = ldata.score * rdata.score + tree.tree[i].score;
        if (t > ans) {
            tree.tree[i].left = ldata.data[0];
            tree.tree[i].right = rdata.root;
            tree.tree[ldata.root].parent = i;
            tree.tree[rdata.root].parent = i;
            ans = t;
            root = i;
        }
    }
    return toData(root, ans);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tree.tree[i].score;
    cout << build(1, n).score << endl;
    return 0;
}