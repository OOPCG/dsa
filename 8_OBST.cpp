#include <iostream>
using namespace std;
class obst
{
    int a[10], r[10][10], n;
    float p[10], q[10], w[10][10], c[10][10];
    public:
    void accept();
    void cons_obst();
    int find_min(int, int);
    void tree(int i, int j);
};
void obst::accept()
{
    int i;
    cout << "\n How many elements are there in the tree? : ";
    cin >> n;
    cout << "\n Enter" << n << "elements :";
    for (i = 1; i <= n; i++)
    cin >> a[i] ;
    cout << "\n Enter" << n << "their Successful probabilities : ";
    for (i = 1; i <= n; i++)
    cin >>  p[i];
    cout << "\n Enter" << n + 1 << "failure probabilities : ";
    for (i = 0; i <= n; i++)
    cin >> q[i];
}
void obst::cons_obst()
{
    int i, m, j, k;
    for (i = 0; i < n; i++) /* Initialize the weight and cost matrices , when j-i =0 and j-i=1 */
    {
        w[i][i] = q[i];
        r[i][i] = c[i][i] = 0;
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = w[i][i + 1];
    }
    w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
    /* calculate the weight and cost matrices. when i=0,  for m=2,
    loop iterate  for i=0,1,2 so (i,j) = (0,2) (1,3) (2,4)*/

    for (m = 2; m <= n; m++) {
        for (i = 0; i <= n - m; i++)
        {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            k = find_min(i, j); /* find minimum value in the range r[i-1][j] to r[i][j-1] */
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }
    cout << "root node is " << a[r[0][n]];
    cout << "\n Left child of " << a[r[0][n]] << " is ";
    tree(0, r[0][n] - 1);
    cout << "\n Right child of " << a[r[0][n]] << " is ";
    tree(r[0][n], n);
}
int obst::find_min(int i, int j)
{
    int min = 999, k, z;
    for (k = r[i][j - 1]; k <= r[i + 1][j]; k++)
    {
        cout<<"\n i = "<<i<<"j= "<<j<<"k= "<<k;
        if (min > c[i][k - 1] + c[k][j])
        {
            min = c[i][k - 1] + c[k][j];
            z = k;
        }
    }
    return (z);
}
void obst::tree(int i, int j)
{
    if (r[i][j] == 0)
    {
    cout<<" NULL\n";
    return;
    }
    cout << " :: " << a[r[i][j]];
    cout << "\n Left child of is ::" << a[r[i][j]];
    tree(i, r[i][j] - 1);
    cout << "\n Right child of is :: " << a[r[i][j]];
    tree(r[i][j], j);
}
int main()
{
    obst o;
    o.accept();
    o.cons_obst();
}



