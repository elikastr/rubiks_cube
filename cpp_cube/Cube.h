#ifndef RUBIKS_CUBE_CUBE_H
#define RUBIKS_CUBE_CUBE_H

#include <iostream>
#include <string>

class Cube {
public:
    explicit Cube(std::string cube = "");

    std::string up, left, front, right, back, down;

    void print();

    std::string solve();

private:
    std::string solution;

    void replace(const std::string& s1, const std::string& s2);

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

    bool isEdgeUp(const char c1, const char c2);
    bool isCornerUp(const char c1, const char c2, const char c3);

    bool isCrossReady();
    void bottomCross();

    void bottomCorners();
    void middleEdges();
    void topCross();
    void topCorners();
    void topEdges();
};


#endif //RUBIKS_CUBE_CUBE_H
