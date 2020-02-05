#include<iostream>
#include<cstdlib>
using  namespace std;
int ip;
char arr[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void grid(){
    system("clear");
    cout<<"Plater 1: O   VS   Player 2: X"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<arr[1]<<"  |  "<<arr[2]<<"  |  "<<arr[3]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<arr[4]<<"  |  "<<arr[5]<<"  |  "<<arr[6]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<arr[7]<<"  |  "<<arr[8]<<"  |  "<<arr[9]<<"  "<<endl;
    cout<<"     |     |     "<<endl<<endl;
    
}
int check(){
    if((arr[1]==arr[2])&&arr[2]==arr[3])
    return 1;
    if((arr[4]==arr[5])&&arr[5]==arr[6])
    return 1;
    if((arr[7]==arr[8])&&arr[8]==arr[9])
    return 1;
    if((arr[1]==arr[4])&&arr[4]==arr[7])
    return 1;
    if((arr[2]==arr[5])&&arr[5]==arr[8])
    return 1;
    if((arr[3]==arr[6])&&arr[6]==arr[9])
    return 1;
    if((arr[1]==arr[5])&&arr[5]==arr[9])
    return 1;
    if((arr[3]==arr[5])&&arr[5]==arr[7])
    return 1;
    return 0;
}
void manager(int mode,int z){
    grid();
    while(z<=9){
    cout<<"Player "<<((z%2)==1?'1':'2')<<"'s turn: ";
    cin>>ip;
    printf("%d %d", ip, arr[ip]);
    if(arr[ip]-48==ip){
        arr[ip]=((z%2)==1?'O':'X');
        grid();
        z++;
    }
    else{
        cout<<"Wrong Selection!"<<endl;
    }
    if(z>4){
        if(check()==1){
            cout<<"Player "<<((z%2)==0?'1':'2')<<" Won!!";
            return;
        }
        else if(z==9){
            cout<<"It's a Tie";
            return;
        }
    }
    }
}
int main(){
    int choice,mode,z=1;
    system("clear");
    do{
        cout<<"Press 1 to Play or 0 to Exit: "<<endl;
        cin>>choice;
        system("clear");
        switch(choice){
            case 1:
            cout<<"Choose Mode:"<<endl<<"1)Human vs Human"<<endl<<"2)Human vs PC"<<endl;
            cin>>mode;
            manager(mode,z);
            break;
            case 0:
            exit(0);
            break;
            default:
            system("clear");
            cout<<"Invalid Input";
        }
    }while(choice!=0);
    return 0; 
}