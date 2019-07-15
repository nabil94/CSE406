#include<bits/stdc++.h>

using namespace std;

vector<int> factors;
vector<vector<int> > permute;
vector<int> ser;

void primeFactors(int n)
{
    for (int i = 5; i < n; i++)
    {
        if(n%i == 0){
            factors.push_back(i);
        }
    }
}


int findPermutations(int a[], int n)
{
    sort(a, a + n);
    //cout << "Possible permutations are:\n";
    int c = 0;
    do{
        vector<int> temp;
        for(int i = 0; i < n; i++){
            temp.push_back(a[i]);
        }
        permute.push_back(temp);
        c++;
    }
    while (next_permutation(a, a + n));
    return c;
}

string getDecodedMsg(string st,int col,vector<int> vec)
{
    int row = st.size()/col;
    char s[col][row];
    for (int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            s[i][j] = st[j + (i * row)] - 'A' + 'a';
        }

    }

    char newD[row][col];
    for (int i = 0; i < col; ++i){
        for (int j = 0; j < row; ++j){
            newD[j][i]= s[i][j];
        }
    }

    char uu[row][col];
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            uu[j][i] = newD[j][vec[i]];
        }
    }

    string msg;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            msg.push_back(uu[i][j]);
        }
    }
    return msg;
}

int isSubstring(string s1, string s2){
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++){
        int j;

        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return 1;
    }

    return -1;
}

string f(string g, int h,string aa,string b,string c,string d){
    int a[h];
    for(int i = 0; i < h; i++){
        a[i] = i;
    }
    int t = findPermutations(a, h);
    int p;
    string gg;
    for(int i = 0; i < t; i++)
    {
        gg = getDecodedMsg(g,h,permute[i]);
        if(isSubstring(aa,gg) == 1 && isSubstring(b,gg) == 1 && isSubstring(c,gg) == 1 && isSubstring(d,gg) == 1){
            cout<<gg<<endl;
            p = i;
            break;
        }
   }
   for(int i = 0; i < h; i++){
        ser.push_back(permute[p][i]);
        cout<<permute[p][i]+1<<" ";
   }
    return gg;

}

int main(){
    string d;// = "ERLENAOFALGNOGIPIAMAPRSOXEYCERTRVNTTINHSRLTITNIOEXRMLLGTRIWDATRTROLRBFADIVXTDWONAOOEHHELIEUTSBNEZVNSHAIMIDMWDOEUMNAPWTOGRAIMX";
    cin>>d;
    string pp,qq,rr,ss;
    cin>>pp;
    cin>>qq;
    cin>>rr;
    cin>>ss;
    primeFactors(d.size());
    string tt;
    int key;
    for(int i = 0; i < factors.size(); i++){
        tt = f(d,factors[i],pp,qq,rr,ss);
        if(isSubstring(pp,tt) == 1 && isSubstring(qq,tt) == 1 && isSubstring(rr,tt) == 1 && isSubstring(ss,tt) == 1){
            key = factors[i];
            break;
        }
    }
    cout<<"key size : "<<key<<endl;
    cout<<tt<<endl;

    int r = tt.size()/key;
    char ddd[r][key];
    for (int i = 0; i < r; i++){
        for(int j = 0; j < key; j++){
            ddd[i][j] =tt[j + (i * key)] + 'A' - 'a';
        }

    }

    /*for (int i = 0; i < r; i++){
        for(int j = 0; j < key; j++){
            cout<<ddd[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<endl;
    char uu[r][key];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < key; j++){
            uu[i][ser[j]] = ddd[i][j];
        }
    }

    /*for(int i = 0; i < ser.size(); i++){
        cout<<ser[i]<<" ";
    }
    cout<<endl;*/

    /*for (int i = 0; i < r; i++){
        for(int j = 0; j < key; j++){
            cout<<uu[i][j]<<" ";
        }
        cout<<endl;
    }*/

    char s[key][r];
    for (int i = 0; i < key; i++){
        for(int j = 0; j < r; j++){
           s[i][j] = uu[j][i];
        }

    }
    cout<<endl;
    /*for (int i = 0; i < key; i++){
        for(int j = 0; j < r; j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }*/
    string dec="";
    for(int i = 0; i < key; i++){
        for(int j = 0; j < r; j++){
            dec.push_back(s[i][j]);
        }
    }
    cout<<dec<<endl;
    int y = 0;
    for(int i = 0; i <dec.size(); i++){
        if(d[i] == dec[i]){
            y++;
        }
    }
    double t2 = (y/dec.size())*100;
    cout<<"accuracy : "<<t2<<"%"<<endl;

    return 0;
}

