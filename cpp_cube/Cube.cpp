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

//    print();
//    bottomCross();
//    bottomCorners();
//    middleEdges();
//    topCross();
//    topCorners();
//    std::cout << solution << std::endl;
//    print();
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

// rotate front face clockwise
void Cube::F(int i) {
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

    if (i) solution.append("F ");
}

// rotate front face counter clockwise
void Cube::Fi() {
    F(0);
    F(0);
    F(0);

    solution.append("Fi ");
}

// rotate up face clockwise
void Cube::U(int i) {
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

    if (i) solution.append("U ");
}

// rotate up face counter clockwise
void Cube::Ui() {
    U(0);
    U(0);
    U(0);

    solution.append("Ui ");
}

// rotate left face clockwise
void Cube::L(int i) {
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

    if (i) solution.append("L ");
}

// rotate left face counter clockwise
void Cube::Li() {
    L(0);
    L(0);
    L(0);

    solution.append("Li ");
}

// rotate right face clockwise
void Cube::R(int i) {
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

    if (i) solution.append("R ");
}

// rotate right face counter clockwise
void Cube::Ri() {
    R(0);
    R(0);
    R(0);

    solution.append("Ri ");
}

// rotate back face clockwise
void Cube::B(int i) {
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

    if (i) solution.append("B ");
}

// rotate back face counter clockwise
void Cube::Bi() {
    B(0);
    B(0);
    B(0);

    solution.append("Bi ");
}

// rotate down face clockwise
void Cube::D(int i) {
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

    if (i) solution.append("D ");
}

// rotate down face counter clockwise
void Cube::Di() {
    D(0);
    D(0);
    D(0);

    solution.append("Di ");
}

// solve bottom cross
void Cube::bottomCross() {
    char c = down[4];

    // bring bottom edges to the top
    while (up[1] != c || up[3] != c || up[5] != c || up[7] != c) {
        if (front[1] == c) {
            F(); Ui(); R(); U();
        }
        if (right[1] == c) {
            R(); Ui(); B(); U();
        }
        if (back[1] == c) {
            B(); Ui(); L(); U();
        }
        if (left[1] == c) {
            L(); Ui(); F(); U();
        }

        if (front[3] == c) {
            while (up[3] == c) U();
            Li();
        }
        if (front[5] == c) {
            while (up[5] == c) U();
            R();
        }
        if (right[3] == c) {
            while (up[7] == c) U();
            Fi();
        }
        if (right[5] == c) {
            while (up[1] == c) U();
            B();
        }
        if (left[3] == c) {
            while (up[1] == c) U();
            Bi();
        }
        if (left[5] == c) {
            while (up[7] == c) U();
            F();
        }
        if (back[3] == c) {
            while (up[5] == c) U();
            Ri();
        }
        if (back[5] == c) {
            while (up[3] == c) U();
            L();
        }

        if (down[1] == c) {
            while (up[7] == c) U();
            F(); F();
        }
        if (down[3] == c) {
            while (up[3] == c) U();
            L(); L();
        }
        if (down[5] == c) {
            while (up[5] == c) U();
            R(); R();
        }
        if (down[7] == c) {
            while (up[1] == c) U();
            B(); B();
        }

        if (front[7] == c) {
            while (up[7] == c) U();
            Fi(); Ui(); R();
        }
        if (right[7] == c) {
            while (up[5] == c) U();
            Ri(); Ui(); B();
        }
        if (left[7] == c) {
            while (up[3] == c) U();
            Li(); Ui(); F();
        }
        if (back[7] == c) {
            while (up[1] == c) U();
            Bi(); Ui(); L();
        }
    }

    // bring the edges to the bottom
    while (front[1] != front[4] || up[7] != c) U();
    F(); F();

    while (right[1] != right[4] || up[5] != c) U();
    R(); R();

    while (left[1] != left[4] || up[3] != c) U();
    L(); L();

    while (back[1] != back[4] || up[1] != c) U();
    B(); B();
}

// solve bottom corners
void Cube::bottomCorners() {
    char c = down[4];

    // bring bottom corners to the top
    if (front[8] == c || right[6] == c || down[2] == c) {
        while (up[8] == c || front[2] == c || right[0] == c) U();
        R(); U(); Ri(); Ui();
    }
    if (front[6] == c || left[8] == c || down[0] == c) {
        while (up[6] == c || front[0] == c || left[2] == c) U();
        F(); U(); Fi(); Ui();
    }
    if (back[6] == c || right[8] == c || down[8] == c) {
        while (up[2] == c || right[2] == c || back[0] == c) U();
        B(); U(); Bi(); Ui();
    }
    if (back[8] == c || left[6] == c || down[6] == c) {
        while (up[0] == c || left[0] == c || back[2] == c) U();
        L(); U(); Li(); Ui();
    }

    // bring corners to the bottom
    char c1 = front[4];
    char c2 = right[4];
    while ((up[8] != c && up[8] != c1 && up[8] != c2)
           || (front[2] != c && front[2] != c1 && front[2] != c2)
           || (right[0] != c && right[0] != c1 && right[0] != c2)) U();
    while (front[8] != c1 || right[6] != c2 || down[2] != c) {
        R(); U(); Ri(); Ui();
    }

    c2 = left[4];
    while ((up[6] != c && up[6] != c1 && up[6] != c2)
           || (front[0] != c && front[0] != c1 && front[0] != c2)
           || (left[2] != c && left[2] != c1 && left[2] != c2)) U();
    while (front[6] != c1 || left[8] != c2 || down[0] != c) {
        F(); U(); Fi(); Ui();
    }

    c1 = back[4];
    c2 = right[4];
    while ((up[2] != c && up[2] != c1 && up[2] != c2)
           || (back[0] != c && back[0] != c1 && back[0] != c2)
           || (right[2] != c && right[2] != c1 && right[2] != c2)) U();
    while (back[6] != c1 || right[8] != c2 || down[8] != c) {
        B(); U(); Bi(); Ui();
    }

    c2 = left[4];
    while ((up[0] != c && up[0] != c1 && up[0] != c2)
           || (back[2] != c && back[2] != c1 && back[2] != c2)
           || (left[0] != c && left[0] != c1 && left[0] != c2)) U();
    while (back[8] != c1 || left[6] != c2 || down[6] != c) {
        L(); U(); Li(); Ui();
    }
}

void Cube::middleEdges() {
    char c = up[4];

    // bring middle edges to the top
    if (front[3] != c && left[5] != c) {
        while (up[7] != c && front[1] != c) U();
        Ui(); Li(); U(); L(); U(); F(); Ui(); Fi();
    }
    if (front[5] != c && right[3] != c) {
        while (up[7] != c && front[1] != c) U();
        U(); R(); Ui(); Ri(); Ui(); Fi(); U(); F();
    }
    if (back[3] != c && right[5] != c) {
        while (up[1] != c && back[1] != c) U();
        Ui(); Ri(); U(); R(); U(); B(); Ui(); Bi();
    }
    if (back[5] != c && left[3] != c) {
        while (up[1] != c && back[1] != c) U();
        U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
    }

    // bring edges to the middle
    for (int i = 0; i < 4; i++) {
        while (up[7] == c || front[1] == c) U();

        char c1 = front[1];
        char c2 = up[7];

        if (c1 == front[4] && c2 == left[4]) {
            Ui(); Li(); U(); L(); U(); F(); Ui(); Fi();
        }
        else if (c1 == front[4] && c2 == right[4]) {
            U(); R(); Ui(); Ri(); Ui(); Fi(); U(); F();
        }

        else if (c1 == left[4] && c2 == back[4]) {
            Bi(); U(); B(); U(); L(); Ui(); Li();
        }
        else if (c1 == left[4] && c2 == front[4]) {
            U(); U(); F(); Ui(); Fi(); Ui(); Li(); U(); L();
        }

        else if (c1 == right[4] && c2 == front[4]) {
            U(); U(); Fi(); U(); F(); U(); R(); Ui(); Ri();
        }
        else if (c1 == right[4] && c2 == back[4]) {
            B(); Ui(); Bi(); Ui(); Ri(); U(); R();
        }

        else if (c1 == back[4] && c2 == right[4]) {
            U(); Ri(); U(); R(); U(); B(); Ui(); Bi();
        }
        else if (c1 == back[4] && c2 == left[4]) {
            Ui(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
        }
    }
}

void Cube::topCross() {
    char c = up[4];

    while (up[1] != c || up[3] != c || up[5] != c || up[7] != c) {
        if (up[7] == c && (up[3] == c || up[1] == c)) U();
        else if (up[5] == c && up[7] == c) {
            U(); U();
        }
        else if (up[1] == c && up[5] == c) Ui();

        F(); R(); U(); Ri(); Ui(); Fi();
    }
}

void Cube::topCorners() {
    char c = up[4];

    // orient corners
    int corners = 0;
    if (up[0] == c) corners++;
    if (up[2] == c) corners++;
    if (up[6] == c) corners++;
    if (up[8] == c) corners++;

    while (corners != 4) {
        if (corners == 0) {
            while (left[2] != c) U();
        }
        else if (corners == 1) {
            while (up[6] != c) U();
        }
        else if (corners == 2) {
            while (front[0] != c) U();
        }

        R(); U(); Ri(); U(); R(); U(); U(); Ri();

        corners = 0;
        if (up[0] == c) corners++;
        if (up[2] == c) corners++;
        if (up[6] == c) corners++;
        if (up[8] == c) corners++;
    }

    // position corners
    if (left[0] != left[2] && front[0] != front[2] && right[0] != right[2] && back[0] != back[2]) {
        R(); U(); Ri(); Ui(); Ri(); F(); R(); R(); Ui(); Ri(); Ui(); R(); U(); Ri(); Fi();
    }

    while (left[0] != left[2]) U();
    R(); U(); Ri(); Ui(); Ri(); F(); R(); R(); Ui(); Ri(); Ui(); R(); U(); Ri(); Fi();
}
