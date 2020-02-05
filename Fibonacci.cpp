#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

bool menu();
void submenuPascal();
void submenuFibonacci();
void pascal(int, int);
void fibonacci(int);
void printPascale(std::ostream&, int mat[][10], int);
void printFibonacci(std::ostream&, int n, std::string);
std::string addStrings(std::string A, std::string B);

int main()
{
    while (menu());
    return 0;
}

bool menu()
{
    int selection = 0;
    std::cout<<"*******************MENU********************"<<std::endl<<std::endl;
    std::cout<<"\t1:\tPascal\'s triangle\n\t2:\tFibonacci Numbers\n\t3:\tExit"<<std::endl<<std::endl;
    while (true)
    {
        std::cout<<"\tEnter Selection: ";
        std::cin>>selection;
        if(!std::cin)
        {
            std::cout<<"Invalid Input!";
            std::cin.clear();
            continue;
        }
        else if(selection>3 || selection<1)
        {
            std::cout<<"Invalid Input!";
            std::cin.clear();
            continue;
        }
        break;
    }
    if (selection==1)
    {
        submenuPascal();
        return true;
    }
    else if (selection==2)
    {
        submenuFibonacci();
        return true;
    }
    return false;
}

void submenuPascal()
{
    int seed=0, siz=0;
    while(true)
    {
        std::cout<<"Enter an integer to start the triangle(1-999): ";
        std::cin>>seed;

        if(!std::cin)
        {
            std::cout<<"Invalid Input!"<<std::endl;
            std::cin.clear();
            continue;
        }

        while(true)
        {
            std::cout<<"Enter the size of the triangle(5-10): ";
            std::cin>>siz;
            if(!std::cin)
            {
                std::cout<<"Invalid Input!"<<std::endl;
                std::cin.clear();
                continue;
            }
            if(siz>10||siz<5)
            {
                std::cout<<"Invalid Input!"<<std::endl;
                std::cin.clear();
                continue;
            }
            break;
        }
        break;
    }
    pascal(seed, siz);
    return;
}

void submenuFibonacci ()
{
    int n=0;
    while(true)
    {
        std::cout<<"Enter an integer for n to get the nth Fibonnacci Number: ";
        std::cin>>n;
        if(!std::cin)
        {
            std::cout<<"Invalid Input!"<<std::endl;
            std::cin.clear();
            continue;
        }
        break;
    }
    fibonacci(n);
    return;
}

void pascal(int seed, int siz)
{
    ///creates and fills the matrix
    int matrix[siz+1][10];

    for(int i=0; i<=siz; i++)
    {
        for(int j=0; j<siz; j++)
        {
            matrix[i][j]=0;
        }
    }

    matrix[1][0]=seed;

    for(int i=2; i<=siz; i++)
    {
        for(int j=0; j<i; j++)
        {
            matrix[i][j]=matrix[i-1][j-1] + matrix[i-1][j];
        }
    }

    printPascale(std::cout, matrix, siz);

    return;
}

void fibonacci (int n)
{
    ///fibonacci numbers grow very fast and quickly become too large
    ///for primitive number data types (google max sizes for int double and float)
    ///One solution is to use strings to hold the numbers
    ///and then perform the addition manually
    std::string A="0";
    std::string B="1";
    std::string C="";
    /// we don't need to know all of the numbers in the sequence. Just the current number (C) and the previous two (A,B)
    /// so we don't need an array of strings, just these 3.

    for(int i=0;i<(n-1); i++){
        ///C=A+B;
        C = addStrings(A,B);

        ///shift B to A and C(current) to B
        A=B;
        B=C;
    }
    printFibonacci(std::cout, n, C);
    return;
}

void printPascale(std::ostream& out, int mat[][10], int siz)
{
    ///prints the matrix
    for(int i=1; i<=siz; i++)
    {
        int l = ((7*siz)/2)-((7*i)/2);
        out<<std::setw(l)<<" ";
        for(int j=0; j<i; j++)
            out<<std::left<<std::setw(7)<<mat[i][j];
        out<<std::endl;
    }
    out<<"\n\n\tPress Enter to return to menu..."<<std::flush;
    std::cin.sync();
    std::cin.ignore();
    return;
}

void printFibonacci (std::ostream& out, int n, std::string C)
{
    out<<"The "<<n<<"th Fibonacci Number: "<<C<<std::endl;
    out<<"\n\n\tPress Enter to return to menu..."<<std::flush;
    std::cin.sync();
    std::cin.ignore();
    return;
}

std::string addStrings (std::string A, std::string B)
{
    /// reset C to "" for the result of each round
    std::string C="";
    std::string tempA = A;
    std::string tempB = B;
    /// Calculate length of the strings
    int n1 = tempA.length(), n2 = tempB.length();

    /// Reverse both of the strings so you can loop from beginning to end
    std::reverse(tempA.begin(), tempA.end());
    std::reverse(tempB.begin(), tempB.end());
    ///carry is outside the for loop so that it persists between loops
    int carry = 0;

    for (int i=0; i<n1; i++)
    {
        /// get the sum of
        /// current digits and last loops carry. Notice the chars are being subtracted by '0', added to the carry value
        /// and then '0' gets added back before it gets put at the back of the solution.
        /// Look at the ASCii chart and the decimal values for chars to see why this works
        int sum = ((tempA[i]-'0')+(tempB[i]-'0')+carry);
        C.push_back(sum%10 + '0');

        /// Calculate carry for the next loop
        carry = sum/10;
    }

    /// Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((tempB[i]-'0')+carry);
        C.push_back(sum%10 + '0');
        carry = sum/10;
    }

    /// Add remaining carry
    if (carry)
        C.push_back(carry+'0');

    /// reverse result string C
    std::reverse(C.begin(), C.end());
    return C;
}
