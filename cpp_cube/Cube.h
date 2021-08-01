#ifndef RUBIKS_CUBE_CUBE_H
#define RUBIKS_CUBE_CUBE_H

#include <iostream>
#include <string>

#define CUBE "wwwwwwwwwgggggggggrrrrrrrrrbbbbbbbbboooooooooyyyyyyyyy"
#define MAX 50

class Cube {
public:
    explicit Cube(std::string cube = CUBE);

    std::string up, left, front, right, back, down;

    void print();

    std::string solve();
    std::string reverseSolve();

private:
    std::string solution;
    std::string reverseSolution;

    static void count(char v, int counter[]);
    void replace(const std::string& s1, const std::string& s2);
    void optimize();

    static void rotate(std::string &face);

    void F(int i = 1);
    void Fi();
    void U(int i = 1);
    void Ui();
    void L(int i = 1);
    void Li();
    void R(int i = 1);
    void Ri();
    void B(int i = 1);
    void Bi();
//    void D(int i = 1);
//    void Di();

    bool isEdgeUp(char c1, char c2);
    bool isCornerUp(char c1, char c2, char c3);
    bool isCrossReady();

    void bottomCross();
    void bottomCorners();
    void middleEdges();
    void topCross();
    void topCorners();
    void topEdges();
};


#endif //RUBIKS_CUBE_CUBE_H
