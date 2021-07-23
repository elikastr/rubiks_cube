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

    void F();
    void Fi();
    void U();
    void Ui();
    void L();
    void Li();
    void R();
    void Ri();
    void B();
    void Bi();
    void D();
    void Di();

private:
    std::string solution;

    void rotate(std::string &face);
};


#endif //RUBIKS_CUBE_CUBE_H
