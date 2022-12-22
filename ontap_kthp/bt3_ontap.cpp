#include <bits/stdc++.h>
using namespace std;

struct Product
{
    string serial;
    string name;
    int weight;
    int price;
};

void showProducts(Product products[], int n)
{
    cout << "- list products ------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " > " << products[i].serial << ", " << products[i].name << ", " << products[i].weight << ", " << products[i].price << endl;
    }
    cout << endl;
}

void sort(Product products[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
        {
            if (products[i].name > products[j].name)
            {
                swap(products[i], products[j]);
            }
        }
}

// tra ve vi tri can chen
//  cac vi tri tren list cu tu vi tri chen tien len 1.
int findPositionAddNewProduct(Product products[], int l, int r, string nameNewProduct)
{
    if (l >= r)
    {
        if (products[r].name < nameNewProduct)
        {
            return r + 1;
        }
        return r;
    }
    int m = (l + r) / 2;
    if (products[m].name < nameNewProduct)
        return findPositionAddNewProduct(products, m + 1, r, nameNewProduct);
    else
        return findPositionAddNewProduct(products, l, m, nameNewProduct);
}

// tim xau con chung max
int xauChungMax(string a, string b)
{
    int L[a.length() + 1][b.length() + 1];
    for (int i = 0; i <= a.length(); i++)
        L[i][0] = 0;
    for (int j = 0; j <= b.length(); j++)
        L[0][j] = 0;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[a.length()][b.length()];
}

void findSp(Product products[], int n, Product target)
{
    for (int i = 0; i < n; i++)
    {
        if (xauChungMax(products[i].name, target.name) >= 10)
            cout << products[i].serial << ": " << products[i].name << endl;
    }
}

// xu ly xau ky tu
int char_in_string(string s, char c)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

bool string_in_string(string t, string p)
{
    int i = t.length(), v = t.length();
    while (i <= p.length())
    {
        int x = v - 1, j = i - 1;
        while (t[x] == p[j] && x >= 0)
        {
            --x;
            --j;
        }
        if (x < 0)
            return true;
        else
        {
            x = char_in_string(t, p[j]);
            if (x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return false;
}

void findTivi(Product products[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (string_in_string("ti vi", products[i].name))
        {
            cout << products[i].serial << ", " << products[i].name << endl;
        }
    }
    cout << endl;
}

// end ------------------------------------

int main()
{

    int n = 10;
    Product products[n] = {
        {"ms0123", "bibik ti vi", 10, 12},
        {"ms0234", "jghd", 12, 7},
        {"ms0334", "gvnv", 5, 20},
        {"ms0442", "ti vi sony", 7, 7},
        {"ms0589", "limbim kaka", 15, 2},
        {"ms0341", "keo biti", 8, 26},
        {"ms0343", "banh bao trtr", 3, 13},
        {"ms0dre", "bong nami", 4, 9},
        {"ms0326", "ken haha", 7, 13},
        {"ms0947", "my kokomo", 7, 25}};

    sort(products, n);
    showProducts(products, n);

    // tim vi tri chen san pham moi
    cout << "-- Chen sản phẩm mơi --" << endl;
    Product newProduct = {"ms09238", "giay chay bo(new)", 4, 12};
    int vt = findPositionAddNewProduct(products, 0, n - 1, newProduct.name);
    for (int i = 0; i <= n; i++)
    {
        if (i == vt)
            cout << i << " > " << newProduct.name << endl;
        else if (i < vt)
            cout << i << " > " << products[i].name << endl;
        else
            cout << i << " > " << products[i - 1].name << endl;
    }

    cout << "-- tim san có tên giống 10 ký tự tro lên --" << endl;
    Product sp0088 = {"sp0901", "banh ao tr", 12, 12};
    findSp(products, n, sp0088);

    cout << "--- find ti vi ----" << endl;
    findTivi(products, n);
    return 0;
}