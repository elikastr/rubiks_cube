#include "Cube.h"

Cube::Cube(std::string cube) {
    if (cube.size() != 54) cube = "wwwwwwwwwooooooooogggggggggrrrrrrrrrbbbbbbbbbyyyyyyyyy";

    for (int i = 0; i < 9; i++) {
        up.push_back(cube[i]);
        left.push_back(cube[i + 9]);
        front.push_back(cube[i + 18]);
        right.push_back(cube[i + 27]);
        back.push_back(cube[i + 36]);
        down.push_back(cube[i + 45]);
    }
}

Cube::Cube() : Cube("") {}

void Cube::print() {
    std::cout << "    " << up[0] << up[1] << up[2] << std::endl;
    std::cout << "    " << up[3] << up[4] << up[5] << std::endl;
    std::cout << "    " << up[6] << up[7] << up[8] << std::endl;

    std::cout << left[0] << left[1] << left[2] << " ";
    std::cout << front[0] << front[1] << front[2] << " ";
    std::cout << right[0] << right[1] << right[2] << " ";
    std::cout << back[0] << back[1] << back[2] << std::endl;

    std::cout << left[3] << left[4] << left[5] << " ";
    std::cout << front[3] << front[4] << front[5] << " ";
    std::cout << right[3] << right[4] << right[5] << " ";
    std::cout << back[3] << back[4] << back[5] << std::endl;

    std::cout << left[6] << left[7] << left[8] << " ";
    std::cout << front[6] << front[7] << front[8] << " ";
    std::cout << right[6] << right[7] << right[8] << " ";
    std::cout << back[6] << back[7] << back[8] << std::endl;

    std::cout << "    " << down[0] << down[1] << down[2] << std::endl;
    std::cout << "    " << down[3] << down[4] << down[5] << std::endl;
    std::cout << "    " << down[6] << down[7] << down[8] << std::endl << std::endl;
}

void Cube::rotate(std::string &face) {
    std::string temp = face;

    face[0] = temp[6];
    face[1] = temp[3];
    face[2] = temp[0];
    face[3] = temp[7];
    face[5] = temp[1];
    face[6] = temp[8];
    face[7] = temp[5];
    face[8] = temp[2];
}

void Cube::F() {
    rotate(front);

    std::string temp = up.substr(6, 3);

    up[6] = left[8];
    up[7] = left[5];
    up[8] = left[2];

    left[2] = down[0];
    left[5] = down[1];
    left[8] = down[2];

    down[0] = right[6];
    down[1] = right[3];
    down[2] = right[0];

    right[0] = temp[0];
    right[3] = temp[1];
    right[6] = temp[2];
}

void Cube::Fi() {
    F();
    F();
    F();
}

void Cube::U() {
    rotate(up);

    std::string temp = front.substr(0, 3);

    front[0] = right[0];
    front[1] = right[1];
    front[2] = right[2];

    right[0] = back[0];
    right[1] = back[1];
    right[2] = back[2];

    back[0] = left[0];
    back[1] = left[1];
    back[2] = left[2];

    left[0] = temp[0];
    left[1] = temp[1];
    left[2] = temp[2];
}

void Cube::Ui() {
    U();
    U();
    U();
}

void Cube::L() {
    rotate(left);

    std::string temp;
    temp.push_back(up[0]);
    temp.push_back(up[3]);
    temp.push_back(up[6]);

    up[0] = back[8];
    up[3] = back[5];
    up[6] = back[2];

    back[2] = down[6];
    back[5] = down[3];
    back[8] = down[0];

    down[0] = front[0];
    down[3] = front[3];
    down[6] = front[6];

    front[0] = temp[0];
    front[3] = temp[1];
    front[6] = temp[2];
}

void Cube::Li() {
    L();
    L();
    L();
}

void Cube::R() {
    rotate(right);

    std::string temp;
    temp.push_back(up[2]);
    temp.push_back(up[5]);
    temp.push_back(up[8]);

    up[2] = front[2];
    up[5] = front[5];
    up[8] = front[8];

    front[2] = down[2];
    front[5] = down[5];
    front[8] = down[8];

    down[2] = back[6];
    down[5] = back[3];
    down[8] = back[0];

    back[6] = temp[0];
    back[3] = temp[1];
    back[0] = temp[2];
}

void Cube::Ri() {
    R();
    R();
    R();
}

void Cube::B() {
    rotate(back);

    std::string temp = up.substr(0, 3);

    up[0] = right[2];
    up[1] = right[5];
    up[2] = right[8];

    right[2] = down[8];
    right[5] = down[7];
    right[8] = down[6];

    down[6] = left[0];
    down[7] = left[3];
    down[8] = left[6];

    left[0] = temp[2];
    left[3] = temp[1];
    left[6] = temp[0];
}

void Cube::Bi() {
    B();
    B();
    B();
}

void Cube::D() {
    rotate(down);

    std::string temp = front.substr(6, 3);

    front[6] = left[6];
    front[7] = left[7];
    front[8] = left[8];

    left[6] = back[6];
    left[7] = back[7];
    left[8] = back[8];

    back[6] = right[6];
    back[7] = right[7];
    back[8] = right[8];

    right[6] = temp[0];
    right[7] = temp[1];
    right[8] = temp[2];
}

void Cube::Di() {
    D();
    D();
    D();
}
