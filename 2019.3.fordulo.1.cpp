#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n;
    int maxim=-1;
    int minim;

    in>>n>>minim;

    int x;
    int legjobb=0;
    int index=n,jindex=0;

    int index2=0;

    for(int i=2;i<=n;i++){
        in>>x;
        if(x<minim){
            index2=i;
            minim=x;
            maxim=0;
        }else if(x>maxim){
            maxim=x;
            if(maxim-minim>legjobb){
                legjobb=maxim-minim;

                index=index2;
                jindex=i;


            }
        }else if(maxim==0){
            maxim=x;
        }

    }


    cout<<index<<" "<<jindex;

    return 0;
}
