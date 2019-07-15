#include<bits/stdc++.h>

using namespace std;

vector<string> vect;

int PI[64] = {58, 50, 42, 34, 26, 18, 10, 2,
              60, 52, 44, 36, 28, 20, 12, 4,
              62, 54, 46, 38, 30, 22, 14, 6,
              64, 56, 48, 40, 32, 24, 16, 8,
              57, 49, 41, 33, 25, 17, 9, 1,
              59, 51, 43, 35, 27, 19, 11, 3,
              61, 53, 45, 37, 29, 21, 13, 5,
              63, 55, 47, 39, 31, 23, 15, 7
             };

int CP_1[56] = {57, 49, 41, 33, 25, 17, 9,
                1, 58, 50, 42, 34, 26, 18,
                10, 2, 59, 51, 43, 35, 27,
                19, 11, 3, 60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7, 62, 54, 46, 38, 30, 22,
                14, 6, 61, 53, 45, 37, 29,
                21, 13, 5, 28, 20, 12, 4
               };

int CP_2[48] = {14, 17, 11, 24, 1, 5, 3, 28,
                15, 6, 21, 10, 23, 19, 12, 4,
                26, 8, 16, 7, 27, 20, 13, 2,
                41, 52, 31, 37, 47, 55, 30, 40,
                51, 45, 33, 48, 44, 49, 39, 56,
                34, 53, 46, 42, 50, 36, 29, 32
               };

int E[48] = {32, 1, 2, 3, 4, 5,
             4, 5, 6, 7, 8, 9,
             8, 9, 10, 11, 12, 13,
             12, 13, 14, 15, 16, 17,
             16, 17, 18, 19, 20, 21,
             20, 21, 22, 23, 24, 25,
             24, 25, 26, 27, 28, 29,
             28, 29, 30, 31, 32, 1
            };

int PI_2[32] = {35, 38, 46, 6, 43, 40, 14, 45,
                33, 19, 26, 15, 23, 8, 22, 10,
                12, 11, 5, 25, 27, 21, 16, 31,
                28, 32, 34, 24, 9, 37, 2, 1
               };

int P[32] = {16, 7, 20, 21, 29, 12, 28, 17,
             1, 15, 23, 26, 5, 18, 31, 10,
             2, 8, 24, 14, 32, 27, 3, 9,
             19, 13, 30, 6, 22, 11, 4, 25
            };

int PI_1[64] = {40, 8, 48, 16, 56, 24, 64, 32,
                39, 7, 47, 15, 55, 23, 63, 31,
                38, 6, 46, 14, 54, 22, 62, 30,
                37, 5, 45, 13, 53, 21, 61, 29,
                36, 4, 44, 12, 52, 20, 60, 28,
                35, 3, 43, 11, 51, 19, 59, 27,
                34, 2, 42, 10, 50, 18, 58, 26,
                33, 1, 41, 9, 49, 17, 57, 25
               };

int SHIFT[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

string padding(string gg)
{
    int length = gg.size();
    int k = 8-(length%8);
    for(int i = 0; i < k; i++)
    {
        gg.append("~");
    }
    return gg;
}

string getBinary(string st)
{
    int n = st.size();
    //int i = 0;
    string gh = "";

    for (int i = 1; i <= st.size(); i++)
    {
        int val = int(st[i-1]);

        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin.push_back('1') : bin.push_back('0');
            val /= 2;
        }
        if(bin.size() != 8)
        {
            int tt = 8 - bin.size();
            for(int i = 0; i < tt; i++)
            {
                bin.push_back('0');
            }
        }
        reverse(bin.begin(), bin.end());
        gh.append(bin);


    }
    return gh;
    /*for(int j = 0; j < vec.size(); j++)
    {
        cout<<vec.at(j)<<endl;
    }*/
}

string permutation(string ff, int p[],int n)
{
    char hh[n];
    for(int i = 0; i < n; i++)
    {
        hh[i] = ff[p[i]-1];
    }
    string q = "";
    for(int i = 0; i < n; i++)
    {
        q.push_back(hh[i]);
    }
    return q;
}

string XOR(string t1,string t2)
{
    string str = "";
    for(int i = 0; i < t2.size(); i++)
    {
        if(t1[i] == t2[i])
        {
            str.append("0");
        }
        else str.append("1");
    }
    return str;
}

char Bit_Op(string s)
{
    int f = 0;
    for(int i=0,j=7; i<s.size(); i++,j--)
    {
        if(s[i]=='1')
        {
            f|=(1<<j);
        }
    }
    char ch = static_cast<char >(f);
    return ch;
}

string binary_To_string(string str)
{
    string ans = "";
    for(int i=0; i<str.size(); i+=8)
    {
        string sub = str.substr(i,8);
        ans+=Bit_Op(sub);
    }
    return ans;
}

string binaryToStr(string data)
{
    stringstream sstream(data);
    string output="";
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output.push_back(c);
    }
    //output.erase(64,72);
    return output;
}

int BinarytoDecimal(string str)
{
    reverse(str.begin(),str.end());

    int sum = 0;
    for(int i = 0; i < 8; i++)
    {
        if(str[i] == '1') sum+=pow(2,i);
    }
    return sum;
}

int main()
{
    freopen("out.txt","w",stdout);
    string plaintext;// = "nabil is good";
    string key;//= "megabuck";
    getline(cin,plaintext);
    cin>>key;
    int blocks = (plaintext.size()/8)+1;
    string datablocks[blocks];
    string pad = padding(plaintext);
    for(int i = 0; i < blocks; i++)
    {
        datablocks[i] = pad.substr(i*8,8);
    }
    string binarykey = getBinary(key);
    //cout<< "binary key       : " <<binarykey<<endl;
    string permuteKey = permutation(binarykey,CP_1,56);
    //cout<<"After permutation : "<<permuteKey<<endl;
    string pp =permuteKey;
    string fin = "";
    string jj ="";
    for(int w = 0; w < blocks; w++)
    {
        string binaryPT = getBinary(datablocks[w]);
        //cout<< "binary plaintext : " <<binaryPT<<endl;


        string permuteText = permutation(binaryPT,PI,64);
        //cout<<"After permutation : "<<permuteText<<endl;

        string LH = permuteText.substr(0,32);
        string RH = permuteText.substr(32,32);
        //cout<<"Left side : "<<LH<<endl;
        //cout<<"Right side: "<<RH<<endl;
        string LO,RO;
        LO = LH;
        RO = RH;
        for(int i = 0; i < 16; i++)
        {
            string LOdup = LO;
            LO = RO;
            string LK = pp.substr(0,28);
            string RK = pp.substr(28,28);
            string LKS = LK.substr(0,SHIFT[i]);
            LK.erase(0,SHIFT[i]);
            LK.append(LKS);
            //cout<<LK<<endl;
            string RKS = RK.substr(0,SHIFT[i]);
            RK.erase(0,SHIFT[i]);
            RK.append(RKS);
            //cout<<RK<<endl;
            pp = LK+RK;
            //cout<<pp<<endl;
            //vect.push_back(pp);
            string key48 = permutation(pp,CP_2,48);
            //cout<<key48<<endl;
            vect.push_back(key48);
            string RH48 = permutation(RO,E,48);
            //cout<<RH48<<endl;
            string func48 = XOR(key48,RH48);
            //cout<<func48<<endl;
            string func32 = permutation(func48,PI_2,32);
            //cout<<func32<<endl;
            string func2_32 = permutation(func32,P,32);
            //cout<<func2_32<<endl;
            string Ri = XOR(LOdup,func2_32);
            //cout<<Ri<<endl;
            RO = Ri;
        }
        string data64 = RO+LO;
        //cout<<"after iteration   :  "<<data64<<endl;
        string finaldata64 = permutation(data64,PI_1,64);

        fin+=finaldata64;
        //string hhh = binary_To_string(finaldata64);
        //cout<<binary_To_string(finaldata64)<<endl;

        for(int i = 0; i < 8; i++)
        {
            string op = finaldata64.substr(i*8,8);
            int kkk = BinarytoDecimal(op);
            //cout<<(unsigned char)kkk;
            jj.push_back((unsigned char)kkk);
        }
        //cout<<jj.size()<<endl;
    }

    //cout<<fin<<endl;
    cout<<jj<<endl;
    int binaryBlocks = fin.size()/64;
    string bb[binaryBlocks];
    for(int i = 0; i < binaryBlocks; i++)
    {
        bb[i] = fin.substr(i*64,64);
    }
    string ans="";
    for(int u = 0; u < binaryBlocks; u++)
    {
        string box1 = permutation(bb[u],PI,64);
        //cout<<box1<<endl;
        string Lbox = box1.substr(0,32);
        string Rbox = box1.substr(32,32);
        string LO1 = Lbox;
        string RO1 = Rbox;
        for(int i = 15; i>=0; i--)
        {
            string LOdup = LO1;
            LO1 = RO1;
            //string key48 = permutation(vect[i],CP_2,48);
            //cout<<key48<<endl;
            //vect.push_back(key48);
            string RH48 = permutation(RO1,E,48);
            //cout<<RH48<<endl;
            string func48 = XOR(vect[i],RH48);
            //cout<<func48<<endl;

            string func32 = permutation(func48,PI_2,32);
            //cout<<func32<<endl;
            string func2_32 = permutation(func32,P,32);
            //cout<<func2_32<<endl;
            string Ri = XOR(LOdup,func2_32);
            //cout<<Ri<<endl;
            RO1 = Ri;
        }
        string encoded = RO1 + LO1;
        //cout<<encoded<<endl;
        string aaa = permutation(encoded,PI_1,64);
        ans += aaa;
        //cout<<binaryToStr(aaa)<<endl;
    }
    cout<<binaryToStr(ans)<<endl;

    return 0;

}
