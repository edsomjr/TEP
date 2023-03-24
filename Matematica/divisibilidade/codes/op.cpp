int main()
{
    int a = 11;
    int b = 7;

    cout << (a % b) << '\n';       // 4
    cout << (a % -b) << '\n';      // 4
    cout << (-a % b) << '\n';      // -4
    cout << (-a % -b) << '\n';     // -4

    return 0;
}
