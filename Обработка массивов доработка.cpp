/*********************************
 * Автор:     Иккерт А.С.        *
 * Название:  Обработка массивов *
 * Вариант:   7                  *
 *********************************/


#include <iostream>  
#include <vector>  

using namespace std;  

int main() {  
    int matrixSize, rowToRemove;  
    
    // Ввод размера матрицы и значения k  
    cout << "Enter the size of the square matrix: ";
    cin >> matrixSize;  
    
    cout << "Enter k value (from 1 to " << matrixSize << "): ";
    cin >> rowToRemove;  
    
    // Корректировка k  
    rowToRemove = rowToRemove - 1;  
    
    // Создаем матрицу  
    vector<vector<int>> originalMatrix(matrixSize, vector<int>(matrixSize));  
    
    cout << "Enter matrix elements " << matrixSize << "x" << matrixSize << ":" << endl;  
    for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {  
        for (int colIndex = 0; colIndex < matrixSize; colIndex++) {  
            cin >> originalMatrix[rowIndex][colIndex];  
        }  
    }  
    
    // Вывод оригинальной матрицы  
    cout << "\nOriginal matrix V:" << endl;  
    for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {  
        for (int colIndex = 0; colIndex < matrixSize; colIndex++) {  
            cout << originalMatrix[rowIndex][colIndex] << " ";  
        }  
        cout << endl;  
    }  
    
    // Создаем новую матрицу  
    vector<vector<int>> resultMatrix(matrixSize - 1, vector<int>(matrixSize - 1));  
    
    int newRowIndex = 0;  
    for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {  
        if (rowIndex == rowToRemove) continue; // Пропускаем k строку  
        
        int newColIndex = 0;  
        for (int colIndex = 0; colIndex < matrixSize; colIndex++) {  
            if (colIndex == rowToRemove) continue; // Пропускаем k столбец  
            
            resultMatrix[newRowIndex][newColIndex] = originalMatrix[rowIndex][colIndex];  
            newColIndex++;  
        }  
        newRowIndex++;  
    }  
    
    // Вывод результата  
    cout << "\nMatrix after removing " << rowToRemove + 1 << "-th row and " << rowToRemove + 1 << "-th column:" << endl;  
    for (int rowIndex = 0; rowIndex < matrixSize - 1; rowIndex++) {  
        for (int colIndex = 0; colIndex < matrixSize - 1; colIndex++) {  
            cout << resultMatrix[rowIndex][colIndex] << " ";  
        }  
        cout << endl;  
    }  
    
    return 0;  
}