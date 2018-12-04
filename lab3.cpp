#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;
// 8. Построить транзитивное замыкание для графа и найти матрицу связности графа.

int s;
vector<vector<int>> m(2, vector<int>(2));//у першому векторі два пустих, і вийшов двомірний масив

int CreateMatrix(int size) {
	if (size > 0) {
        m.resize(size);
        for (int i = 0; i < size; i++) {
            m[i].resize(size);
            for (int j = 0; j < size; j++) {
                m[i][j] = 0;
            }
        }
    }
	s = size;
	return size;
}

void AddToMatrix(int x, int y) {
	if (((x >= 0) && (y >= 0))) {
        if (((x < s) && (y < s))){
            m[x][y] = 1;
        }
    }
}

int CreateTop(int top, int size) {
	if (top > 0) {
        m.resize(top);
        for (int i = size; i < top; i++) {
            m[i].resize(top);
            for (int j = size; j < top; j++) {
                m[i][j] = 0;
            }
        }
    }
	s = top;
	return top;
}

int List() {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (m[i][j] == 1) {
                cout << i << " сужіно з " << j << endl;
            }
        }
    }
}

void DeleteFromMatrix(int x, int y) {
	if (((x > 0) && (y > 0))) {
        if (((x < s) && (y < s))){
            m[x][y] = 0;
        }
    }
}

void PrintMatrix() {
	for (int i = 0; i < s; i++) {
		cout << endl;
		for (int j = 0; j < s; j++) {
			cout << m[i][j] << " ";
		}
	}
	cout << endl;
}

void TransitMatrix() {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
            for (int k = 0; k < s; k++) {
				m[j][k] = (m[j][k] || m[i][k]);
			}
		}
	}
}

int main() {
    // CreateMatrix(4);
    // AddToMatrix(0, 1);
    // AddToMatrix(0, 3);
    // AddToMatrix(1, 2);
    // AddToMatrix(1, 3);
    // AddToMatrix(1, 0);
    // AddToMatrix(2, 3);
    // AddToMatrix(3, 3);
    // PrintMatrix();
    // TransitMatrix();
    // PrintMatrix();
    CreateMatrix(3);
    AddToMatrix(1,2);
    AddToMatrix(2,1);
    AddToMatrix(1,0);
    PrintMatrix();
    CreateTop(4,3);
    PrintMatrix();
    List();
}