#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

int s;
vector< vector<int> > m(2, vector<int>(2));

int CreateMatrix(int size) {
	assert(size > 0);
	m.resize(size);
	for (int i = 0; i < size; i++) {
		m[i].resize(size);
		for (int j = 0; j < size; j++) {
			m[i][j] = 0;
		}
	}
	s = size;
	return size;
}

void AddToMatrix(int x, int y) {
	assert((x >= 0) && (y >= 0));
	assert((x < s) && (y < s));
	m[x][y] = 1;
}

void DeleteFromMatrix(int x, int y) {
	assert((x > 0) && (y > 0));
	assert((x < s) && (y < s));
	m[x][y] = 0;
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
			if (m[i][j] == 1) {
				for (int k = 0; k < s; k++) {
					m[j][k] = (m[j][k] || m[i][k]);
				}
			}
		}
	}
}

TEST_CASE("Check CreateMatrix") {
	CreateMatrix(10);
	CHECK(s == 10);
}

TEST_CASE("Check AddToMatrix") {
	CreateMatrix(10);
	AddToMatrix(2,3);
	CHECK(m[2][3] == 1);
}

TEST_CASE("Check DeleteFromMatrix") {
	CreateMatrix(10);
	AddToMatrix(2, 3);
	AddToMatrix(5, 1);
	AddToMatrix(7, 7);
	AddToMatrix(9, 4);
	CHECK(m[5][1] == 1);
	DeleteFromMatrix(5, 1);
	CHECK(m[5][1] == 0);
}

TEST_CASE("Check TransitMatrix") {
	 CreateMatrix(4);
    AddToMatrix(0, 1);
    AddToMatrix(0, 3);
    AddToMatrix(1, 2);
    AddToMatrix(1, 3);
    AddToMatrix(1, 0);
    AddToMatrix(2, 3);
    AddToMatrix(3, 3);
	CHECK(m[2][2] == 0);
	TransitMatrix();
	CHECK(m[2][2] == 0);
}