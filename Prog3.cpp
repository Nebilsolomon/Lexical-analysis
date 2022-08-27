//
//  main.cpp
//  Prog3
//
//  Created by nebil on 6/9/22.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>      // std::stringstream
#include <set>



/*
 
 This Program asked for source code, so when you add source code it read and tokenize it. if it is reserved word "“cout<<”, “for”, “int”, “while”", it print it. If it is not it check if it is number, operator or special chrachter. we write dfa and convert to scanner table, and we make scanner table 2 dimention array. Scanner table is in CheckEachToken function. Also, you can see dfa and scanner table in the attach.
 
    Note: For some reason this program wasn't work in window OS it work perfectly in my Computer. if it is not work in your please let me know i can show in my computer. Thank you and have a great day.

 
 */





using namespace::std;

int getCharx(char token);
string CheckEachToken(string token);
void runProgram();





int main(){
   
    
    char continueProgram ;
    bool run = true;
    
while (run)
{
    runProgram();

    cout << "DCONTINUE(y/n)? n";
    cin >> continueProgram;
    
    if (continueProgram == 'y') {
        
        run = true;
        
    }else {
        
        run = false;
        break;
    }

}
    
    
    return 0;
}


void runProgram () {
    
    
    string  reservedWords[8]={ "for", "cout<<",  "int", "while", "Cout<<", "For", "While", "Int"};
     
     string myText;
     
     std::set<string> my_set;
     
    
     
     cout << " Please Enter your source code to parse "  << endl;
     getline (cin, myText);
    
     
     
     string parsed;
     stringstream input_stringstream(myText);

    
    
    // Read Whole Source code and Tokenize it
    
     while (getline(input_stringstream,parsed,' '))
     {
        
         
         
     /* We add each token to set because it is easier to check each element of it
       */
         my_set.insert(parsed);

         
        
     }
     
     
  
     
   
     
     
   /*
    here we check each element of set if it is reserved world we print and delete from set.
    
    */
     set<string>::iterator it = my_set.begin();
     
     for (; it != my_set.end(); it++) {
         
         
         for (int i = 0 ; i < 7; i++) {
             
             if( reservedWords[i] == *it) {
                 
                cout << " reserved world   " << *it<<  endl;
                 

                 
                 my_set.erase(*it);

                 
             }
             
         
         
         
     }
    
     }
     
     
    /*
     we already delete all reserved now set has no reserved, so we can check eack element of set if it is operator, special world, number or identifier
    */
     set<string>::iterator nebil = my_set.begin();
     
     for (; nebil != my_set.end(); nebil++) {
     

       
         
         /* everything happed in CheckEachToken we check if it is number, identfier, or operator or specil world with scanner table that we made from dfa of all these character.
         */
         
         cout << CheckEachToken(*nebil) << endl;
        
        // cout<< "my set is------- " << *nebil <<  endl;
     }

     
     
     
     
    
     
    
    
    
    
    
    
    
}


/* this function convert each char to one digit to order to use in scanner table

 */

 int getCharx(char token) {
    
    int num = 0;
    
    
    
    switch (token) {
        case '+':
            num = 0;
            
            break;
        case '-':
            num = 1;
            
            break;
        case '*':
            num = 2;
            
            break;
        case '/':
            num = 3;
            
            
            break;
        case '<':
            num = 4;
            
            break;
            
            
            break;
        case '=':
            num = 5;
            
            break;
            
            break;
        case ';':
            num = 6;
            
            break;
            
            break;
        case '(':
            num = 7;
            
            break;
            
        case ')':
            num = 8;
            
            break;
            
            
        case ',':
            num = 9;
            
            break;
            
      
            
            //////
            
        case 'A':
            num = 10;
            
            break;
            
            
        case 'B':
            num = 11;
            
            break;
            
        case 'C':
            num = 12;
            
            break;
            
            
        case 'D':
            num = 13;
            
            break;
            
            
        case 'E':
            num = 14;
            
            break;
            
            
            
        case 'F':
            num = 15;
            
            break;
            
            
        case 'G':
            num = 16;
            
            break;
            
            
            
        case 'H':
            num = 17;
            
            break;
            
            
            
        case 'I':
            num = 18;
            
            break;
            
            
        case 'J':
            num = 19;
            
            break;
            
            
            
        case 'K':
            num = 20;
            
            break;
            
            
            
        case 'L':
            num = 21;
            
            break;
            
            
            
        case 'M':
            num = 22;
            
            break;
            
            
            
        case 'N':
            num = 23;
            
            break;
            
            
        case 'O':
            num = 24;
            
            break;
            
            
        case 'P':
            num = 25;
            
            break;
            
            
            
        case 'Q':
            num = 26;
            
            break;
            
            
        case 'R':
            num = 27;
            
            break;
            
            
            
        case 'S':
            num = 28;
            
            break;
            
            
            
        case 'T':
            num = 29;
            
            break;
            
            
            
        case 'U':
            num = 30;
            
            break;
            
            
            
        case 'V':
            num = 31;
            
            break;
            
            
            
        case 'W':
            num = 32;
            
            break;
            
            
        case 'X':
            num = 33;
            
            break;
            
            
        case 'Y':
            num = 34;
            
            break;
            
            
            
        case 'Z':
            num = 35;
            
            break;
            
            
        case 'a':
            num = 36;
            
            break;
            
            
            
        case 'b':
            num = 37;
            
            break;
            
            
        case 'c':
            num = 38;
            
            break;
            
            
            
        case 'd':
            num = 39;
            
            break;
            
            
            
        case 'e':
            num = 40;
            
            break;
            
            
            
        case 'f':
            num = 41;
            
            break;
            
            
            
        case 'g':
            num = 42;
            
            break;
            
            
            
        case 'h':
            num = 43;
            
            break;
            
            
        case 'i':
            num = 44;
            
            break;
            
            
        case 'j':
            num = 45;
            
            break;
            
            
            
        case 'k':
            num = 46;
            
            break;
            
            
            
        case 'l':
            num = 47;
            
            break;
            
            
            
        case 'm':
            num = 48;
            
            break;
            
            
            
        case 'n':
            num = 49;
            
            break;
            
            
            
        case 'o':
            num = 50;
            
            break;
            
            
            
        case 'p':
            num = 51;
            
            break;
            
            
            
        case 'q':
            num = 52;
            
            break;
            
            
            
        case 'r':
            num = 53;
            
            break;
            
            
        case 's':
            num = 54;
            
            break;
            
            
            
        case 't':
            num = 55;
            
            break;
            
            
        case 'u':
            num = 56;
            
            break;
            
            
        case 'v':
            num = 57;
            
            break;
            
            
        case 'w':
            num = 58;
            
            break;
            
            
        case 'x':
            num = 59;
            
            break;
            
            
        case 'y':
            num = 60;
            
            break;
            
            
        case 'z':
            num = 61;
            
            break;
            
            
        case '0':
            num = 62;
            
            break;
            
            
        case '1':
            num = 63;
            
            break;
            
            
        case '2':
            num = 64;
            
            break;
            
            
        case '3':
            num = 65;
            
            break;
            
           
           // char a = '4';
         //   int ia = a - '0';
            
        case '4':
            num = 66;
            
            
         //   cout << "this is from case" << endl;
            break;
            
            
        case '5':
            num = 67;
            
            break;
            
            
        case '6':
            num = 68;
            
            break;
            
            
        case '7':
            num = 69;
            
            break;
            
            
        case '8':
            num = 70;
            
            break;
            
            
        case '9':
            num = 71;
            
            break;
            
        case '_':
            num = 72;
            
            break;
            
            
        default:
            break;
    }
    
    
    
    return num;
}



/*
 
 All important work is happed in this function. we make DFA from operator, specail char, number and identier, and we make scanner table from them. two dimention array in this fucntion is scanner table. -1 is empty, 15 is accepted for digit, 2 to 7 is accepted for operator, 8 to 14 is accepted for special, and 17 is accepted state for identifier.
 
 
 
 
 
 */




string CheckEachToken(string token) {
    
    
    
    int currentState = 1;
    string returnTypeOfToken = "";
    //string tokenn = "num_12";
                        
    int table[18][73] = {

// +    -   *   /   <   =  ;  (  )   ,  A    B  C   D   E    F   G   H  I   J    K  L   M    N  O    P   Q   R   S  T   U   V    W   X   Y   Z
{  0,   1,  2,  3,  4,  5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
    
//   a   b  c    d   e   f   g   h   i   j   k   l   m   n   o  p   q    r   s   t   u   v   w  x    y   z   0   1  2    3   4   5   6   7   8  9
    36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
//  _
    72
    
},
                         
{4,  2,   6,  7, 8 , 10, 11, 12, 13, 14 ,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17 ,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17 ,17,17,17,17,17,17 ,15,15,15,15,15 ,15,15,15,15,15,16
    
    
    
}, // firt row
        
{-1 , 3,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1 ,  15, 15, 15, 15, 15, 15, 15, 15, 15,15      -1, }, // second row
                         
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },// third row
                       
        {5 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, }, // fourt row
        
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, }, // fifth row
                        
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, }, // sixth row
                      
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },       // seventh
                        
        {-1 , -1,   -1, -1, -1, 9, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },         // eight
             
        
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, },             // nine
        
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },            //ten
      
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },          // eleven
                                
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },        // 12 row
          
        
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },    // 13 row
                                         
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1      -1, },  // 14 row
                            
        {-1 , -1,   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1    -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1  -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1,-1   -1, -1, -1, -1, -1, -1, -1, -1, -1 ,-1 ,  15, 15, 15, 15, 15, 15, 15, 15, 15,15      -1, },    // 15 row
        
        
        
        {-1, -1, -1, -1,-1, -1, -1, -1, -1,-1    ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17  ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17    ,17, 17, 17, 17, 17, 17, 17,17, 17, 17  , 17, 17, 17
            
            
        },   // 16 row
                          
    
        
    {-1, -1, -1, -1,-1, -1, -1, -1, -1,-1    ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17  ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17   ,17, 17, 17, 17, 17, 17, 17,17, 17, 17    ,17, 17, 17, 17, 17, 17, 17,17, 17, 17  , 17, 17, 17
            
            
        }    // 17 row
    };
    
    

    
    
    for (int i = 0; i<token.length(); i++) {
        

        int xx =  getCharx(token[i]);
        
        
        
     
        if (table[currentState][xx] != -1) {
            
            currentState = table[currentState][xx];
        }
        else {
            
            cout << token <<" is not from Langauge " << endl;
            currentState = -1;
            break;
        }
        
        
        
        
        
        
        
    }
    
    
    if (currentState == 15) {
      
        returnTypeOfToken =  token + "  Number ";
        
        
    }
    
    else if (currentState <= 2 && currentState <= 7) {
        
        returnTypeOfToken =  token + "  operator ";
        
    }
    else if (currentState <= 8 && currentState <= 14) {
        
        returnTypeOfToken =  token + "  special symbol ";
      
        
    }
    
    else if (currentState == 17) {
        
        returnTypeOfToken =  token + "    identifier ";

        
    }
    
    
    
    return returnTypeOfToken;
    
    
}
