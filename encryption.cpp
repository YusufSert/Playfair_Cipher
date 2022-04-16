
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    int i,j,k,n;
    cout<<"Enter the message"<<endl;
    string s,origin;
    getline(cin,origin);
    cout<<"Enter the key"<<endl;
    string key;
    cin>>key;
    for(i=0;i<origin.size();i++){
        if(origin[i]!=' ')
            s+= origin[i];
    }
    char a[5][5];
    n=5;
    map<char,int> mp;
    k=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0 && k<key.size()){ // Check if have key
                k++;
            }   
            if(k != key.length()){
                a[i][j]=key[k];
                mp[key[k]]++;
            }
            if(k==key.size()) // Break kullanmam gerekir yoksa J nin pozisyonumu hatırlayamam
            break;
        }
        if(k==key.size())  // Break yapmam gerekir çunki i pozisyonunu korumalıyım
           break;
    }
    
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){ // j=0 yapamam yoksa sıra bozulur ilk loop sonra 0 yapman gerekir
            while(mp[char(k+'a')] > 0 && k<26){ // Check eğer key varsa if not k++ to go to othe key
                k++;
            }
            if(char(k+'a') == 'j'){ // Eger j key de ve message da yoksa j yi 5x5 arraye koyma
                j--;                // Geri while e dön k++ yap yoksa ayni harf yine soracak
                k++;               // Bu harfi atla k++ ile yoksa infinite loop oluşacak
                continue;
            }
            if(k<26){ // Eğer k 26 dan dusukse array e yerleitir
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++; // Key arttır aynı harfe tekrar bakmasın
            }
        }
        j=0; // İç loopun tekrar işlemesi için
    }
    cout<< endl;
    cout << "          ******** MATRIX ********* ";
    cout << endl;
    for(int k = 0; k<5; k++){
        cout << "     -------------------------------------" << endl;
        for(int c = 0; c<5; c++)
        {
            cout << "     |" << a[k][c] << "|";
        }
        cout << endl;
    }


    string ans;
    if(s.size()%2==1)
        s+="x"; // Eğer text tek sayı ise sonuna x ekle ki eşit olsun
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) // Harf ondan sonraki harf ayni ise 
            s[i+1]='x';
    }


    map<char,pair<int,int> > mp2;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j); // 'a' -> a[0][0] -> i=0, j=0; her key position ata
        }
    }
    
    for(i=0;i<s.size()-1;i+=2){
        int y1 = mp2[s[i]].first; // Harf ve position  -> i; Text deki harf dudeeeee
        int x1 = mp2[s[i]].second; // Harf ve position -> j;
        int y2 = mp2[s[i+1]].first; // Harf+1 ve position -> i;
        int x2 = mp2[s[i+1]].second; // Harf+1 ve position -> j;
        if(y1==y2){ // Same row
            ans+=a[y1][(x1+1)%5]; // % kodugunda 5 olursa 0 verir
            ans+=a[y1][(x2+1)%5];
        }
        else if(x1==x2){ // Same colum
            ans+=a[(y1+1)%5][x1];
            ans+=a[(y2+1)%5][x2];    
        }
        else { // :(((((())))))
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
    }
    cout << endl;
    cout<< "CipherText => " << ans <<'\n';
    return 0;
}
