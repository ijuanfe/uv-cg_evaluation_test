/*
    Subject: Computer Graphics
    File Name: computer_graphics.cpp
    Description: Diagnostic evaluation test
        Implement a program in C++ that read two NxN matrices
        from an input file and calculate the transpose of each
        matrix and its matrix product
    Version: 0.1
    Author: Juan Felipe Orozco Escobar 
    Student ID: 1426244
    Systems Engineering and Computing, University of Valle - 2019
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Importing data from file:
	freopen ("matrices_data.txt","r", stdin);

    // Initializing variables:
    int matrices_size;
	cin >> matrices_size;
    int matrix_1[matrices_size][matrices_size];
    int matrix_2[matrices_size][matrices_size];
    int matrix_1_traspose[matrices_size][matrices_size];
    int matrix_2_traspose[matrices_size][matrices_size];
    int matrix_product[matrices_size][matrices_size];

    // Reading and printing original matrices:
    cout << "Original Matrix 1:" << endl;
    for (int row = 0; row < matrices_size; row++)
    {
        for (int column = 0; column < matrices_size; column++)
        {
            cin >> matrix_1[row][column]; // Getting matrix data from file
            cout << matrix_1[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Original Matrix 2:" << endl;
    for (int row = 0; row < matrices_size; row++)
    {
        for (int column = 0; column < matrices_size; column++)
        {
            cin >> matrix_2[row][column]; // Getting matrix data from file
            cout << matrix_2[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Computing and printing trasposed matrices:
    cout << "Traspose of original matrix 1:" << endl;
    for (int row = 0; row < matrices_size; row++)
    {
        for (int column = 0; column < matrices_size; column++)
        {
            matrix_1_traspose[row][column] = matrix_1[column][row];
            cout << matrix_1_traspose[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Traspose of original matrix 2:" << endl;
    for (int row = 0; row < matrices_size; row++)
    {
        for (int column = 0; column < matrices_size; column++)
        {
            matrix_2_traspose[row][column] = matrix_2[column][row];
            cout << matrix_2_traspose[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Initializing matrix product: to avoid getting unexpected errors when computing matrix product in '+='
    for (int i = 0; i < matrices_size; i++)
    {
        for (int j = 0; j < matrices_size; j++)
        {
            matrix_product[i][j] = 0;
        }
    }
    
    // Computing matrix product of trasposed matrices:
    cout << "Matrix product of traposed matrices 1 & 2:" << endl;
    for (int matrix_1_aux = 0; matrix_1_aux < matrices_size; matrix_1_aux++)
    {
        for (int matrix_2_aux = 0; matrix_2_aux < matrices_size; matrix_2_aux++)
        {
            for (int matrices_aux = 0; matrices_aux < matrices_size; matrices_aux++)
            {
                matrix_product[matrix_1_aux][matrix_2_aux] += matrix_1_traspose[matrix_1_aux][matrices_aux] * matrix_2_traspose[matrices_aux][matrix_2_aux];
            }
        }
    }
    
    // Printing matrix product:
    for (int row = 0; row < matrices_size; row++)
    {
        for (int column = 0; column < matrices_size; column++)
        {
            cout << matrix_product[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;

    fclose (stdout);
    return 0;
}