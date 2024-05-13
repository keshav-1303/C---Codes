#include <bits/stdc++.h> 
using namespace std;
#define n 3

void reset(char **arr){
    int c = 49;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = char(c);
            c++;
        }
    }
}

void display(char **arr){
    cout << endl;
    cout << "\n-------------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j == 0)   cout << "|";
            cout << " " << arr[i][j] << " |";
        }
        cout << "\n-------------\n";
    }
}

void turn1(char **arr){

    int t;    cout << "Player 1's move : ";     cin >> t; 

    switch (t){
        case 1:   arr[0][0]='X';    break;
        case 2:   arr[0][1]='X';    break;
        case 3:   arr[0][2]='X';    break;
        case 4:   arr[1][0]='X';    break;
        case 5:   arr[1][1]='X';    break;
        case 6:   arr[1][2]='X';    break;
        case 7:   arr[2][0]='X';    break;
        case 8:   arr[2][1]='X';    break;
        case 9:   arr[2][2]='X';    break;
        default: cout << "Invalid choice ! Next Player's turn now ... " << endl;
    }
    // display(arr);
}

void turn2(char **arr){

    int t;    cout << "Player 2's move : ";     cin >> t; 

    switch (t){
        case 1:   arr[0][0]='O';    break;
        case 2:   arr[0][1]='O';    break;
        case 3:   arr[0][2]='O';    break;
        case 4:   arr[1][0]='O';    break;
        case 5:   arr[1][1]='O';    break;
        case 6:   arr[1][2]='O';    break;
        case 7:   arr[2][0]='O';    break;
        case 8:   arr[2][1]='O';    break;
        case 9:   arr[2][2]='O';    break;
        default: cout << "Invalid choice ! Next Player's turn now ... " << endl;
    }
    // display(arr);
}

// int isgameover(char **arr){
//     int check = 0;
//     for (int i = 0, j = 0; i < n, j < n; i++, j++)
//     { // diagonal south east
//         char key = arr[0][0];
//         if (arr[i][j] == key)
//             check = 1;
//         else
//             check = 0;
//     }
//     if (check == 0)
//     {
//         for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
//         { // diagonal north east
//             char key = arr[0][n - 1];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 0, j = 0; j < n; j++)
//         { // right
//             char key = arr[i][0];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 1, j = 0; j < n; j++)
//         { // right
//             char key = arr[i][0];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 2, j = 0; j < n; j++)
//         { // right
//             char key = arr[i][0];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 0, j = 0; i < n; i++)
//         { // down
//             char key = arr[0][j];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 0, j = 0; i < n; i++)
//         { // down
//             char key = arr[1][j];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     if (check == 0)
//     {
//         for (int i = 0, j = 0; i < n; i++)
//         { // down
//             char key = arr[2][j];
//             if (arr[i][j] == key)
//                 check = 1;
//             else
//                 check = 0;
//         }
//     }
//     return check;
// }

int isgameoverX(char **arr){
    char ch = 'X';    int check = 1;
    if(arr[0][0]==ch && arr[0][1]==ch && arr[0][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[1][0]==ch && arr[1][1]==ch && arr[1][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[2][0]==ch && arr[2][1]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][0]==ch && arr[1][0]==ch && arr[2][0]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][1]==ch && arr[1][1]==ch && arr[2][1]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][2]==ch && arr[1][2]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][0]==ch && arr[1][1]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[2][0]==ch && arr[1][1]==ch && arr[0][2]==ch){
        check = 1;
        return 1;
    }
}

int isgameoverO(char **arr){
    char ch = 'O';    int check = 1;
    if(arr[0][0]==ch && arr[0][1]==ch && arr[0][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[1][0]==ch && arr[1][1]==ch && arr[1][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[2][0]==ch && arr[2][1]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][0]==ch && arr[1][0]==ch && arr[2][0]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][1]==ch && arr[1][1]==ch && arr[2][1]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][2]==ch && arr[1][2]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[0][0]==ch && arr[1][1]==ch && arr[2][2]==ch){
        check = 1;
        return 1;
    }
    if(arr[2][0]==ch && arr[1][1]==ch && arr[0][2]==ch){
        check = 1;
        return 1;
    }
}

int main(){

    string s1;    
    // cout << "Player 1 : ";     cin >> s1;
    string s2;    
    // cout << "Player 2 : ";     cin >> s2;

    s1 = "Player X", s2 = "Player O";
    
    char **arr = (char**) malloc (n * sizeof(char*));
    for(int i=0; i<n; i++)    arr[i] = (char*) malloc (n * sizeof(char));

    reset(arr);

    int i = 0;
    int ans;

    while(1){

        display(arr);

        int x=0, o=0;

        if(i % 2 == 0)    turn1(arr);
        else    turn2(arr);

        x = isgameoverX(arr);
        o = isgameoverO(arr);

        if(x == 1){
            display(arr);
            cout << "Game Over !!! PLAYER1 wins.." << endl;
            break;
        }
        if(o == 1){
            display(arr);
            cout << "Game Over !!! PLAYER2 wins.." << endl;
            break;
        }

        i++;
    }

    free(arr);
	return 0;
}