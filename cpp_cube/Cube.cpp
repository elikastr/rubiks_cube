#include "Cube.h"

Cube::Cube(std::string cube) {
    if (cube.size() != 54) cube = "wwwwwwwwwgggggggggrrrrrrrrrbbbbbbbbboooooooooyyyyyyyyy";

    for (int i = 0; i < 9; i++) {
        up.push_back(cube[i]);
        front.push_back(cube[i + 9]);
        right.push_back(cube[i + 18]);
        back.push_back(cube[i + 27]);
        left.push_back(cube[i + 36]);
        down.push_back(cube[i + 45]);
    }
}

void Cube::replace(const std::string& s1, const std::string& s2) {
    size_t pos = solution.find(s1);

    while (pos != std::string::npos) {
        solution.replace(pos, s1.size(), s2);
        pos = solution.find(s1, pos + s2.size());
    }
}

std::string Cube::solve() {
    if (!solution.empty()) {
        std::cout << solution << std::endl;
        return solution;
    }

    bottomCross();
    bottomCorners();
    middleEdges();
    topCross();
    topCorners();
    topEdges();

    if (solution.empty()) {
        std::cout << "The cube is already solved!" << std::endl;
        return solution;
    }

    replace("U U U ", "Ui ");
    replace("U Ui ", "");
    replace("Ui U ", "");
    replace("Ui Ui ", "U2 ");
    replace("U U ", "U2 ");

    replace("F F F ", "Fi ");
    replace("F Fi ", "");
    replace("Fi F ", "");
    replace("Fi Fi ", "F2 ");
    replace("F F ", "F2 ");

    replace("L L L ", "Li ");
    replace("L Li ", "");
    replace("Li L ", "");
    replace("Li Li ", "L2 ");
    replace("L L ", "L2 ");

    replace("R R R ", "Ri ");
    replace("R Ri ", "");
    replace("Ri R ", "");
    replace("Ri Ri ", "R2 ");
    replace("R R ", "R2 ");

    replace("B B B ", "Bi ");
    replace("B Bi ", "");
    replace("Bi B ", "");
    replace("Bi Bi ", "B2 ");
    replace("B B ", "B2 ");

//    replace("D D D ", "Di ");
//    replace("D Di ", "");
//    replace("Di D ", "");
//    replace("Di Di ", "D2 ");
//    replace("D D ", "D2 ");

    int k = 0;
    for (char & c : solution) {
        if (c == ' ') k++;
        if (k == 20) {
            c = '\n';
            k = 0;
        }
    }

    std::cout << solution << std::endl;
    return solution;
}

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

// rotations of down face are not used in this algorithm, but we keep them just in case
/***
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
***/

// check if a given edge is at the top layer (permuted correctly)
bool Cube::isEdgeUp(const char c1, const char c2) {
    if (up[1] == c1 && back[1] == c2) return true;
    if (up[3] == c1 && left[1] == c2) return true;
    if (up[5] == c1 && right[1] == c2) return true;
    if (up[7] == c1 && front[1] == c2) return true;
    return false;
}

// check if a given corner is at the top layer
bool Cube::isCornerUp(const char c1, const char c2, const char c3) {
    if (up[0] == c1 && back[2] == c2 && left[0] == c3) return true;
    if (up[0] == c1 && back[2] == c3 && left[0] == c2) return true;
    if (up[0] == c2 && back[2] == c1 && left[0] == c3) return true;
    if (up[0] == c2 && back[2] == c3 && left[0] == c1) return true;
    if (up[0] == c3 && back[2] == c1 && left[0] == c2) return true;
    if (up[0] == c3 && back[2] == c2 && left[0] == c1) return true;

    if (up[2] == c1 && back[0] == c2 && right[2] == c3) return true;
    if (up[2] == c1 && back[0] == c3 && right[2] == c2) return true;
    if (up[2] == c2 && back[0] == c1 && right[2] == c3) return true;
    if (up[2] == c2 && back[0] == c3 && right[2] == c1) return true;
    if (up[2] == c3 && back[0] == c1 && right[2] == c2) return true;
    if (up[2] == c3 && back[0] == c2 && right[2] == c1) return true;

    if (up[6] == c1 && front[0] == c2 && left[2] == c3) return true;
    if (up[6] == c1 && front[0] == c3 && left[2] == c2) return true;
    if (up[6] == c2 && front[0] == c1 && left[2] == c3) return true;
    if (up[6] == c2 && front[0] == c3 && left[2] == c1) return true;
    if (up[6] == c3 && front[0] == c1 && left[2] == c2) return true;
    if (up[6] == c3 && front[0] == c2 && left[2] == c1) return true;

    if (up[8] == c1 && front[2] == c2 && right[0] == c3) return true;
    if (up[8] == c1 && front[2] == c3 && right[0] == c2) return true;
    if (up[8] == c2 && front[2] == c1 && right[0] == c3) return true;
    if (up[8] == c2 && front[2] == c3 && right[0] == c1) return true;
    if (up[8] == c3 && front[2] == c1 && right[0] == c2) return true;
    if (up[8] == c3 && front[2] == c2 && right[0] == c1) return true;

    return false;
}

// check if the bottom edges are in the correct position to continue the algorithm
bool Cube::isCrossReady() {
    char c1 = down[4];
    char c2 = front[4];
    if ((front[7] != c2 || down[1] != c1) && !isEdgeUp(c1, c2)) return false;

    c2 = right[4];
    if ((right[7] != c2 || down[5] != c1) && !isEdgeUp(c1, c2)) return false;

    c2 = left[4];
    if ((left[7] != c2 || down[3] != c1) && !isEdgeUp(c1, c2)) return false;

    c2 = back[4];
    if ((back[7] != c2 || down[7] != c1) && !isEdgeUp(c1, c2)) return false;

    return true;
}

// solve bottom cross
void Cube::bottomCross() {
    char c = down[4];

    while (!isCrossReady()) {
        // bring incorrect edges to the top layer
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

        if (down[1] == c && front[7] != front[4]) {
            while (up[7] == c) U();
            F(); F();
        }
        if (down[3] == c && left[7] != left[4]) {
            while (up[3] == c) U();
            L(); L();
        }
        if (down[5] == c && right[7] != right[4]) {
            while (up[5] == c) U();
            R(); R();
        }
        if (down[7] == c && back[7] != back[4]) {
            while (up[1] == c) U();
            B(); B();
        }
    }

    // bring down the corners
    if (front[7] != front[4] || down[1] != c) {
        while (front[1] != front[4] || up[7] != c) U();
        F(); F();
    }

    if (right[7] != right[4] || down[5] != c) {
        while (right[1] != right[4] || up[5] != c) U();
        R(); R();
    }

    if (left[7] != left[4] || down[3] != c) {
        while (left[1] != left[4] || up[3] != c) U();
        L(); L();
    }

    if (back[7] != back[4] || down[7] != c) {
        while (back[1] != back[4] || up[1] != c) U();
        B(); B();
    }
}

// solve bottom corners
void Cube::bottomCorners() {
    char c = down[4];

    // bring incorrect corners to the top
    if (front[8] == c || right[6] == c || (down[2] == c && (front[8] != front[4] || right[6] != right[4]))) {
        while (up[8] == c || front[2] == c || right[0] == c) U();
        R(); U(); Ri(); Ui();
    }
    if (front[6] == c || left[8] == c || (down[0] == c && (front[6] != front[4] || left[8] != left[4]))) {
        while (up[6] == c || front[0] == c || left[2] == c) U();
        F(); U(); Fi(); Ui();
    }
    if (back[6] == c || right[8] == c || (down[8] == c && (back[6] != back[4] || right[8] != right[4]))) {
        while (up[2] == c || right[2] == c || back[0] == c) U();
        B(); U(); Bi(); Ui();
    }
    if (back[8] == c || left[6] == c || (down[6] == c && (back[8] != back[4] || left[6] != left[4]))) {
        while (up[0] == c || left[0] == c || back[2] == c) U();
        L(); U(); Li(); Ui();
    }

    // bring corners to the bottom
    char c1 = front[4];
    char c2 = right[4];
    if (isCornerUp(c, c1, c2)) {
        while ((up[8] != c && up[8] != c1 && up[8] != c2)
               || (front[2] != c && front[2] != c1 && front[2] != c2)
               || (right[0] != c && right[0] != c1 && right[0] != c2)) U();

        if (right[0] == c) {
            R(); U(); Ri();
        }
        else if (front[2] == c) {
            Fi(); Ui(); F();
        }
        else {
            R(); U(); U(); Ri(); Ui(); R(); U(); Ri();
        }
    }

    c2 = left[4];
    if (isCornerUp(c, c1, c2)) {
        while ((up[6] != c && up[6] != c1 && up[6] != c2)
               || (front[0] != c && front[0] != c1 && front[0] != c2)
               || (left[2] != c && left[2] != c1 && left[2] != c2)) U();

        if (left[2] == c) {
            Li(); Ui(); L();
        }
        else if (front[0] == c) {
            F(); U(); Fi();
        }
        else {
            Li(); U(); U(); L(); U(); Li(); Ui(); L();
        }
    }

    c1 = back[4];
    c2 = right[4];
    if (isCornerUp(c, c1, c2)) {
        while ((up[2] != c && up[2] != c1 && up[2] != c2)
               || (back[0] != c && back[0] != c1 && back[0] != c2)
               || (right[2] != c && right[2] != c1 && right[2] != c2)) U();

        if (back[0] == c) {
            B(); U(); Bi();
        }
        else if (right[2] == c) {
            Ri(); Ui(); R();
        }
        else {
            Ri(); U(); U(); R(); U(); Ri(); Ui(); R();
        }
    }

    c2 = left[4];
    if (isCornerUp(c, c1, c2)) {
        while ((up[0] != c && up[0] != c1 && up[0] != c2)
               || (back[2] != c && back[2] != c1 && back[2] != c2)
               || (left[0] != c && left[0] != c1 && left[0] != c2)) U();

        if (back[2] == c) {
            Bi(); Ui(); B();
        }
        else if (left[0] == c) {
            L(); U(); Li();
        }
        else {
            L(); U(); U(); Li(); Ui(); L(); U(); Li();
        }
    }
}

// solve middle edges
void Cube::middleEdges() {
    char c = up[4];

    // bring incorrect middle edges to the top
    if (front[3] != c && left[5] != c && (front[3] != front[4] || left[5] != left[4])) {
        while (up[7] != c && front[1] != c) U();
        Ui(); Li(); U(); L(); U(); F(); Ui(); Fi();
    }
    if (front[5] != c && right[3] != c && (front[5] != front[4] || right[3] != right[4])) {
        while (up[7] != c && front[1] != c) U();
        U(); R(); Ui(); Ri(); Ui(); Fi(); U(); F();
    }
    if (back[3] != c && right[5] != c && (back[3] != back[4] || right[5] != right[4])) {
        while (up[1] != c && back[1] != c) U();
        Ui(); Ri(); U(); R(); U(); B(); Ui(); Bi();
    }
    if (back[5] != c && left[3] != c && (back[5] != back[4] || left[3] != left[4])) {
        while (up[1] != c && back[1] != c) U();
        U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
    }

    // bring edges to the middle
    int k = 0;
    if (isEdgeUp(front[4], left[4]) || isEdgeUp(left[4], front[4])) k++;
    if (isEdgeUp(front[4], right[4]) || isEdgeUp(right[4], front[4])) k++;
    if (isEdgeUp(back[4], left[4]) || isEdgeUp(left[4], back[4])) k++;
    if (isEdgeUp(back[4], right[4]) || isEdgeUp(right[4], back[4])) k++;

    for (int i = 0; i < k; i++) {
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

// solve top cross
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

// solve top corners
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
        Ri(); U(); Li(); U(); U(); R(); Ui(); L(); Ri(); U(); Li(); U(); U(); R(); Ui(); L();
    }

    while (left[0] != left[2] || front[0] != front[2] || right[0] != right[2] || back[0] != back[2]) {
        while (left[0] != left[2]) U();
        R(); U(); Ri(); Ui(); Ri(); F(); R(); R(); Ui(); Ri(); Ui(); R(); U(); Ri(); Fi();
    }
}

void Cube::topEdges() {
    if (front[0] != front[1] && right[0] != right[1] && back[0] != back[1] && left[0] != left[1]) {
        R(); Ui(); R(); U(); R(); U(); R(); Ui(); Ri(); Ui(); R(); R();
    }

    while (front[0] != front[1] || right[0] != right[1] || back[0] != back[1] || left[0] != left[1]) {
        while (back[0] != back[1]) U();
        if (front[1] == left[0]) {
            R(); R(); U(); R(); U(); Ri(); Ui(); Ri(); Ui(); Ri(); U(); Ri();
        }
        else {
            R(); Ui(); R(); U(); R(); U(); R(); Ui(); Ri(); Ui(); R(); R();
        }
    }

    while (front[1] != front[4]) U();
}
