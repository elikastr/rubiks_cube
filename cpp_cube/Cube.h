#ifndef RUBIKS_CUBE_CUBE_H
#define RUBIKS_CUBE_CUBE_H

#include <iostream>
#include <string>

class Cube {
public:
    Cube(std::string cube);
    Cube();

    std::string up, left, front, right, back, down;

    void print();

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
    void D(int i = 1);
    void Di();

private:
    std::string solution;

    void rotate(std::string &face);

    void bottomCross();
    void bottomCorners();
};


#endif //RUBIKS_CUBE_CUBE_H
