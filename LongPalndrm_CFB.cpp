#include <iostream>

using namespace std;
int n, m;
string s[51];
string palindrom;
int length = 0;

bool isPalindrom(string s) {
    int l = s.size();
    
    for(int i = 0; i < l; i++) {
        if(s[i] != s[l-i-1])
            return false;
    }
    return true;
}

bool folosit[51];
void formarePalindrom(string sir1, int lgSir1, int i) {

    for(int j = 1; j <= n; j++) {
            if(i != j && folosit[j] == false) {
                 string sir2 = s[j];
                    int lgSir2 = sir2.size();

                        sir1 += sir2;
                        lgSir1 = sir1.size();
                       
                        folosit[j] = true;
                        formarePalindrom(sir1, lgSir1, j);
                        sir1.erase(lgSir1 - lgSir2, lgSir2);
                        lgSir1 = sir1.size();
                       
                        folosit[j] = false;

            }

        }
    if(length < lgSir1 && isPalindrom(sir1)) {
            palindrom = sir1;
            length = lgSir1;
            //cout << palindrom << endl;
    }
    return;
}
int main()
{

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        folosit[i] = false;
    }


    for(int i = 1; i <= n; i++) {
        string sir1 = s[i];
        int l1 = sir1.size();
        
        folosit[i] = true;
        formarePalindrom(sir1, l1, i);
        folosit[i] = false;

    }
    cout << length << "\n";
    cout << palindrom << "\n";
    return 0;
}

