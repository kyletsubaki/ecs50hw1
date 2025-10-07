#include <iostream>
#include <fstream>
#include <vector>

int index(int n, int i, int j) {
    return i * n - (i * (i - 1)) / 2 + (j - i);
}

std::vector<int> matrixMult(const std::vector<int>& A, const std::vector<int>& B, int n) {
    std::vector<int> result(A.size(), 0);
    for (auto i = 0; i < n; i++) {
        for (auto j = i; j < n; j++) {
            int sum = 0;
            for (auto k = i; k <= j; k++) {
                sum += A[index(n, i, k)] * B[index(n, k, j)];
            }
            result[index(n, i, j)] = sum;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    
    std::ifstream fileA(argv[1]);
    std::ifstream fileB(argv[2]);

    int dimA;
    int dimB;

    fileA >> dimA;
    fileB >> dimB;

    auto n = dimA;
    auto size = (dimA * (dimA +1))/2;
    
    std::vector<int> A;
    std::vector<int> B;
    A.reserve(size);
    B.reserve(size);

    for(auto i = 0; i < size; i++)
    {
        int v;
        fileA >> v;
        A.push_back(v);
    }

    for(auto i = 0; i<size; i++)
    {
        int v;
        fileB >> v;
        B.push_back(v);
    }

    fileA.close();
    fileB.close();

    auto result = matrixMult(A, B, n);
    for (auto v : result) {
        std::cout << v << " ";
    }
}