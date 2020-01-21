#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n,m;
    in>>n>>m;
    int v[n][m][2];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in>>v[i][j][0];
            v[i][j][1]=i;
        }
    }

    for(int j=1;j<m;j++){

        for(int k=0;k<n;k++){
            for(int l=0;l<m;l++){
                cout<<v[k][l][1]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        for(int i=0;i<n;i++){



            int i1=i-1,i2=i+1;

            if(i1<0){
                i1=0;
            }
            if(i2==n){
                i2=n-1;
            }

            int maxi=v[i1][j-1][0];
            v[i][j][1]=v[i1][j-1][1];

            for(int k=i1+1;k<=i2;k++){
                if(maxi<v[k][j-1][0]){
                    maxi=v[k][j-1][0];
                    v[i][j][1]=v[k][j-1][1];
                }
            }
            v[i][j][0]+=maxi;


        }
    }

    for(int k=0;k<n;k++){
            for(int l=0;l<m;l++){
                cout<<v[k][l][1]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;


    /// maximum -- amit a feladat ker az utolso sorra nezve
    /// index   -- a maximum melyik kiindulasi pontra mutat
    int maximum=v[0][m-1][0],index=v[0][m-1][1];
    cout<<index<<endl;
    for(int k=0;k<n;k++){
        if(v[k][m-1][0]>maximum){
            maximum=v[k][m-1][0];
            index=v[k][m-1][1];
        }else if(v[k][m-1][0]==maximum){
            if(v[k][m-1][1]<index){
                index=v[k][m-1][1];
            }
        }
    }
    cout<<endl;
    cout<<maximum<<" "<<index+1;


    return 0;
}
