#include <iostream>
#include <vector>
#include <string>
using namespace std;

char structure[3][3] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
int turns = 0;

class player{
public:
    char val;
    int row,column;
    void assign(char value){
        val = value;
    }
    void input(char structure[3][3]){
        int temp = 0;
        if(turns%2 == 0) cout<<"P1 turn:- ";
        else cout<<"P2 turn:- ";
        cin>>temp;
        column = temp%10 - 1;
        row = temp/10 - 1;
        if(structure[row][column] == '_'){ structure[row][column] = val; }//assigning the 'X' or 'O'
        else{
            cout<<"(Error) That Place is Already Occupied : Please Retry"<<endl;
            input(structure);
        }     
        cout<<endl;   
    }
    void display(char structure[3][3]){
        for(int i = 0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                cout<<structure[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int check(char structure[3][3]){
        if((structure[0][0] != '_' && structure[0][0] == val && structure[0][0] == structure[1][1] && structure[1][1] == structure[2][2]) || (structure[0][2] != '_' && structure[0][2] == val && structure[0][2] == structure[1][1] && structure[1][1] == structure[2][0])){ return 1;}
        else if((structure[0][0] != '_' && structure[0][0] == val && structure[0][0] == structure[0][1] && structure[0][1] == structure[0][2]) || (structure[1][0] != '_' && structure[1][0] == val && structure[1][0] == structure[1][1] && structure[1][1] == structure[1][2]) || (structure[2][0] != '_' && structure[2][0] == val && structure[2][0] == structure[2][1] && structure[2][1] == structure[2][2])){ return 1; }
        else if((structure[0][0] != '_' && structure[0][0] == val && structure[0][0] == structure[1][0] && structure[1][0] == structure[2][0]) || (structure[0][1] != '_' && structure[0][1] == val && structure[0][1] == structure[1][1] && structure[1][1] == structure[2][1]) || (structure[0][2] != '_' && structure[0][2] == val && structure[0][2] == structure[1][2] && structure[1][2] == structure[2][2])){ return 1; }
        return 0;
    }
};

int main(){
    player p1;
    player p2;
    cout<<"Input Format:- xy --> xth row and yth column"<<endl;
    p1.assign('X');
    p2.assign('O');
    cout<<"_ _ _\n_ _ _\n_ _ _"<<endl;
    int temp = 0;int match = 0;
    while(temp!=9){
        if(turns%2 == 0){
            p1.input(structure);
            p1.display(structure);
            match = p1.check(structure);
            if(match == 1){
                cout<<"Player 1 Won!!\nPress Any Key to Continue... "<<endl;
                cin.ignore();
                cin.get();
                return 0;
            }
        }
        else{
            p2.input(structure);
            p2.display(structure);
            match = p2.check(structure);
            if(match == 1){
                cout<<"Player 2 Won!!\nPress Any Key to Continue... "<<endl;
                cin.ignore();
                cin.get();
                return 0;
            }
        }
        temp--;
        turns++;
    }
    cout<<"No One Won!!\nPress Any Key to Continue... "<<endl;
    cin.ignore();
    cin.get();
    return 0;
}
