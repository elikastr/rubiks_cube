#include "Cube.h"
#include <vector>

Cube::Cube(std::string cube) {
    bool isSolved = false;

    if (!isSolved && cube.size() != 54) {
        solution = "*Each color must be added exactly 9 times*";
        cube = CUBE;
        isSolved = true;
    }

    int counter[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 54 && !isSolved; i++) {
        count(cube[i], counter);
    }
    for (int i = 0; i < 5 && !isSolved; i++) {
        if (counter[i] != 9) {
            solution = "*Each color must be added exactly 9 times*";
            cube = CUBE;
            isSolved = true;
        }
        counter[i] = 0;
    }

    for (int i = 4; i <= 49 && !isSolved; i += 9) {
        count(cube[i], counter);
    }
    for (int i = 0; i < 5 && !isSolved; i++) {
        if (counter[i] != 1) {
            solution = "*Each color must be used exactly 1 time as a center field*";
            cube = CUBE;
            isSolved = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        up.push_back(cube[i]);
        front.push_back(cube[i + 9]);
        right.push_back(cube[i + 18]);
        back.push_back(cube[i + 27]);
        left.push_back(cube[i + 36]);
        down.push_back(cube[i + 45]);
    }
}

void Cube::count(char v, int counter[]) {
    switch (v) {
        case 'w':
            counter[0]++;
            break;
        case 'g':
            counter[1]++;
            break;
        case 'r':
            counter[2]++;
            break;
        case 'b':
            counter[3]++;
            break;
        case 'o':
            counter[4]++;
            break;
        case 'y':
            counter[5]++;
            break;
        default:
            std::cout << "Incorrect symbol entered: " << v << std::endl;
            return;
    }
}

void Cube::replace(const std::string& s1, const std::string& s2) {
    size_t pos = solution.find(s1);

    while (pos != std::string::npos) {
        solution.replace(pos, s1.size(), s2);
        pos = solution.find(s1, pos + s2.size());
    }
}

void Cube::optimize() {
    std::string a[] = {"U", "F", "L", "R", "B", "D"};

    for (int i = 0; i < 3; i++) {
        for (auto & k : a) {
            replace(k + " " + k + " " + k + " ", k + "i ");
            replace(k + " " + k + "i ", "");
            replace(k + "i " + k + " ", "");
            replace(k + "i " + k + "i ", k + "2 ");
            replace(k + " " + k + " ", k + "2 ");
            replace(k + "2 " + k + " ", k + "i ");
            replace(k + " " + k + "2 ", k + "i ");
            replace(k + "2 " + k + "i ", k + "");
            replace(k + "i " + k + "2 ", k + "");
        }
    }
}

// solve from given state to solved cube
std::string Cube::solve() {
    if (!solution.empty()) return solution;

    std::string msg = "*Impossible scramble*";
    bottomCross();
    if (solution == "*") {
        solution = msg;
        return solution;
    }
    bottomCorners();
    if (solution == "*") {
        solution = msg;
        return solution;
    }
    middleEdges();
    if (solution == "*") {
        solution = msg;
        return solution;
    }
    topCross();
    if (solution == "*") {
        solution = msg;
        return solution;
    }
    topCorners();
    if (solution == "*") {
        solution = msg;
        return solution;
    }
    topEdges();
    if (solution == "*") {
        solution = msg;
        return solution;
    }

    if (solution.empty()) {
        solution = "*The cube is already solved*";
        return solution;
    }

    optimize();

    int k = 0;
    for (char & c : solution) {
        if (c == ' ') k++;
        if (k == 20) {
            c = '\n';
            k = 0;
        }
    }

    return solution;
}

// solve from solved cube to given state
std::string Cube::reverseSolve() {
    if (!reverseSolution.empty()) return reverseSolution;

    if (solution.empty()) solve();

    if (solution[0] == '*') {
        reverseSolution = solution;
        return reverseSolution;
    }

    std::vector<std::string> v;
    int k = 0;
    for (int i = 0; i < solution.size(); i++) {
        if (solution[i] == ' ' || solution[i] == '\n') {
            v.push_back(solution.substr(k, i - k));
            k = i + 1;
        }
    }

    for (int i = int(v.size()) - 1; i >= 0; i--) {
        std::string s = v[i];
        if (s.size() == 1) reverseSolution.append(s + "i ");
        else if (s[1] == '2') reverseSolution.append(s + " ");
        else {
            s = s.substr(0, 1) + " ";
            reverseSolution.append(s);
        }
    }

    k = 0;
    for (char & c : reverseSolution) {
        if (c == ' ') k++;
        if (k == 20) {
            c = '\n';
            k = 0;
        }
    }

    return reverseSolution;
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

// check if a given edge is at the top layer (permuted correctly)
bool Cube::isEdgeUp(const char c1, const char c2) {
    if (up[1] == c1 && back[1] == c2) return true;
    if (up[3] == c1 && left[1] == c2) return true;
    if (up[5] == c1 && right[1] == c2) return true;
    if (up[7] == c1 && front[1] == c2) return true;
    return false;
}

// check if a given edge is at the bottom layer (permuted correctly)
bool Cube::isEdgeDown(char c1, char c2) {
    if (down[1] == c1 && front[7] == c2) return true;
    if (down[3] == c1 && left[7] == c2) return true;
    if (down[5] == c1 && right[7] == c2) return true;
    if (down[7] == c1 && back[7] == c2) return true;
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

// solve the front bottom edge
void Cube::frontBottom() {
    char c1 = down[4];
    char c2 = front[4];

    if (isEdgeDown(c1, c2)) {
        while (down[1] != c1 || front[7] != c2) D();
    }
    else if (isEdgeDown(c2, c1)) {
        while (right[7] != c1 || down[5] != c2) D();
        R(); F();
    }

    else if (isEdgeUp(c1, c2)) {
        while (up[7] != c1 || front[1] != c2) U();
        F(); F();
    }
    else if (isEdgeUp(c2, c1)) {
        while (right[1] != c1 || up[5] != c2) U();
        Ri(); F();
    }

    else if (right[3] == c1 && front[5] == c2) F();
    else if (right[3] == c2 && front[5] == c1) {
        Ri(); Di();
    }

    else if (left[5] == c1 && front[3] == c2) Fi();
    else if (left[5] == c2 && front[3] == c1) {
        L(); D();
    }

    else if (right[5] == c1 && back[3] == c2) {
        Bi(); D(); D();
    }
    else if (right[5] == c2 && back[3] == c1) {
        R(); Di();
    }

    else if (left[3] == c1 && back[5] == c2) {
        B(); D(); D();
    }
    else if (left[3] == c2 && back[5] == c1) {
        Li(); D();
    }

    else solution = "*";
}

// solve the right bottom edge
void Cube::rightBottom() {
    char c1 = down[4];
    char c2 = right[4];

    if (down[5] == c1 && right[7] == c2) return;
    else if (down[5] == c2 && right[7] == c1) {
        R(); Di(); F(); D();
    }

    else if (down[3] == c1 && left[7] == c2) {
        L(); L(); U(); U(); R(); R();
    }
    else if (down[3] == c2 && left[7] == c1) {
        Li(); Di(); Fi(); D();
    }

    else if (down[7] == c1 && back[7] == c2) {
        F(); Di(); Fi();
    }
    else if (down[7] == c2 && back[7] == c1) {
        B(); R();
    }

    else if (isEdgeUp(c1, c2)) {
        while (up[5] != c1 || right[1] != c2) U();
        R(); R();
    }
    else if (isEdgeUp(c2, c1)) {
        while (back[1] != c1 || up[1] != c2) U();
        Bi(); R();
    }

    else if (front[5] == c1 && right[3] == c2) Ri();
    else if (front[5] == c2 && right[3] == c1) {
        Di(); F(); D();
    }

    else if (front[3] == c1 && left[5] == c2) {
        Li(); U(); U(); R(); R();
    }
    else if (front[3] == c2 && left[5] == c1) {
        Di(); Fi(); D();
    }

    else if (back[3] == c1 && right[5] == c2) R();
    else if (back[3] == c2 && right[5] == c1) {
        D(); Bi(); Di();
    }

    else if (back[5] == c1 && left[3] == c2) {
        L(); U(); U(); R(); R();
    }
    else if (back[5] == c2 && left[3] == c1) {
        D(); B(); Di();
    }

    else solution = "*";
}

// solve the left bottom edge
void Cube::leftBottom() {
    char c1 = down[4];
    char c2 = left[4];

    if (down[3] == c1 && left[7] == c2) return;
    else if (down[3] == c2 && left[7] == c1) {
        Li(); D(); Fi(); Di();
    }

    else if (down[7] == c1 && back[7] == c2) {
        B(); B(); Ui(); L(); L();
    }
    else if (down[7] == c2 && back[7] == c1) {
        Bi(); Li();
    }

    else if (isEdgeUp(c1, c2)) {
        while (up[3] != c1 || left[1] != c2) U();
        L(); L();
    }
    else if (isEdgeUp(c2, c1)) {
        while (back[1] != c1 || up[1] != c2) U();
        B(); Li();
    }

    else if (front[3] == c1 && left[5] == c2) L();
    else if (front[3] == c2 && left[5] == c1) {
        D(); Fi(); Di();
    }

    else if (front[5] == c1 && right[3] == c2) {
        D(); D(); Ri(); D(); D();
    }
    else if (front[5] == c2 && right[3] == c1) {
        D(); F(); Di();
    }

    else if (back[5] == c1 && left[3] == c2) Li();
    else if (back[5] == c2 && left[3] == c1) {
        Di(); B(); D();
    }

    else if (back[3] == c1 && right[5] == c2) {
        D(); D(); R(); D(); D();
    }
    else if (back[3] == c2 && right[5] == c1) {
        Di(); Bi(); D();
    }

    else solution = "*";
}

// solve the back bottom edge
void Cube::backBottom() {
    char c1 = down[4];
    char c2 = back[4];

    if (down[7] == c1 && back[7] == c2) return;
    else if (down[7] == c2 && back[7] == c1) {
        Bi(); D(); Li(); Di();
    }

    else if (isEdgeUp(c1, c2)) {
        while (up[1] != c1 || back[1] != c2) U();
        B(); B();
    }
    else if (isEdgeUp(c2, c1)) {
        while (right[1] != c1 || up[5] != c2) U();
        R(); Bi(); Ri();
    }

    else if (right[5] == c1 && back[3] == c2) Bi();
    else if (right[5] == c2 && back[3] == c1) {
        Di(); R(); D();
    }

    else if (left[3] == c1 && back[5] == c2) B();
    else if (left[3] == c2 && back[5] == c1) {
        D(); Li(); Di();
    }

    else if (right[3] == c1 && front[5] == c2) {
        D(); D(); F(); D(); D();
    }
    else if (right[3] == c2 && front[5] == c1) {
        Di(); Ri(); D();
    }

    else if (left[5] == c1 && front[3] == c2) {
        D(); D(); Fi(); D(); D();
    }
    else if (left[5] == c2 && front[3] == c1) {
        D(); L(); Di();
    }

    else solution = "*";
}

// solve bottom cross
void Cube::bottomCross() {
    frontBottom();
    if (solution == "*") return;
    rightBottom();
    if (solution == "*") return;
    leftBottom();
    if (solution == "*") return;
    backBottom();
}

// solve bottom corners
void Cube::bottomCorners() {
    char c = down[4];

    // bring incorrect corners to the top
    int i = 0;

    if (front[8] == c || right[6] == c || (down[2] == c && (front[8] != front[4] || right[6] != right[4]))) {
        i = 0;
        while (up[8] == c || front[2] == c || right[0] == c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        R(); U(); Ri(); Ui();
    }
    if (front[6] == c || left[8] == c || (down[0] == c && (front[6] != front[4] || left[8] != left[4]))) {
        i = 0;
        while (up[6] == c || front[0] == c || left[2] == c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        F(); U(); Fi(); Ui();
    }
    if (back[6] == c || right[8] == c || (down[8] == c && (back[6] != back[4] || right[8] != right[4]))) {
        i = 0;
        while (up[2] == c || right[2] == c || back[0] == c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        B(); U(); Bi(); Ui();
    }
    if (back[8] == c || left[6] == c || (down[6] == c && (back[8] != back[4] || left[6] != left[4]))) {
        i = 0;
        while (up[0] == c || left[0] == c || back[2] == c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        L(); U(); Li(); Ui();
    }

    // bring corners to the bottom
    char c1 = front[4];
    char c2 = right[4];
    if (isCornerUp(c, c1, c2)) {
        i = 0;
        while ((up[8] != c && up[8] != c1 && up[8] != c2)
               || (front[2] != c && front[2] != c1 && front[2] != c2)
               || (right[0] != c && right[0] != c1 && right[0] != c2)) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }

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
        i = 0;
        while ((up[6] != c && up[6] != c1 && up[6] != c2)
               || (front[0] != c && front[0] != c1 && front[0] != c2)
               || (left[2] != c && left[2] != c1 && left[2] != c2)) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }

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
        i = 0;
        while ((up[2] != c && up[2] != c1 && up[2] != c2)
               || (back[0] != c && back[0] != c1 && back[0] != c2)
               || (right[2] != c && right[2] != c1 && right[2] != c2)) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }

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
        i = 0;
        while ((up[0] != c && up[0] != c1 && up[0] != c2)
               || (back[2] != c && back[2] != c1 && back[2] != c2)
               || (left[0] != c && left[0] != c1 && left[0] != c2)) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }

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
    int i = 0;

    if (front[3] != c && left[5] != c && (front[3] != front[4] || left[5] != left[4])) {
        i = 0;
        while (up[7] != c && front[1] != c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        Ui(); Li(); U(); L(); U(); F(); Ui(); Fi();
    }
    if (front[5] != c && right[3] != c && (front[5] != front[4] || right[3] != right[4])) {
        i = 0;
        while (up[7] != c && front[1] != c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        U(); R(); Ui(); Ri(); Ui(); Fi(); U(); F();
    }
    if (back[3] != c && right[5] != c && (back[3] != back[4] || right[5] != right[4])) {
        i = 0;
        while (up[1] != c && back[1] != c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        Ui(); Ri(); U(); R(); U(); B(); Ui(); Bi();
    }
    if (back[5] != c && left[3] != c && (back[5] != back[4] || left[3] != left[4])) {
        i = 0;
        while (up[1] != c && back[1] != c) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        U(); L(); Ui(); Li(); Ui(); Bi(); U(); B();
    }

    // bring edges to the middle
    int k = 0;
    if (isEdgeUp(front[4], left[4]) || isEdgeUp(left[4], front[4])) k++;
    if (isEdgeUp(front[4], right[4]) || isEdgeUp(right[4], front[4])) k++;
    if (isEdgeUp(back[4], left[4]) || isEdgeUp(left[4], back[4])) k++;
    if (isEdgeUp(back[4], right[4]) || isEdgeUp(right[4], back[4])) k++;

    for (int j = 0; j < k; j++) {
        int m = 0;
        while (up[7] == c || front[1] == c) {
            m++;
            if (m == MAX) {
                solution = "*";
                return;
            }

            U();
        }

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

    int k = 0;
    while (up[1] != c || up[3] != c || up[5] != c || up[7] != c) {
        k++;
        if (k == MAX) {
            solution = "*";
            return;
        }

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

    int k = 0;
    int i = 0;
    while (corners != 4) {
        k++;
        if (k == MAX) {
            solution = "*";
            return;
        }

        if (corners == 0) {
            i = 0;
            while (left[2] != c) {
                i++;
                if (i == MAX) {
                    solution = "*";
                    return;
                }

                U();
            }
        }
        else if (corners == 1) {
            i = 0;
            while (up[6] != c) {
                i++;
                if (i == MAX) {
                    solution = "*";
                    return;
                }

                U();
            }
        }
        else if (corners == 2) {
            i = 0;
            while (front[0] != c) {
                i++;
                if (i == MAX) {
                    solution = "*";
                    return;
                }

                U();
            }
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

    k = 0;
    while (left[0] != left[2] || front[0] != front[2] || right[0] != right[2] || back[0] != back[2]) {
        k++;
        if (k == MAX) {
            solution = "*";
            return;
        }

        i = 0;
        while (left[0] != left[2]) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        R(); U(); Ri(); Ui(); Ri(); F(); R(); R(); Ui(); Ri(); Ui(); R(); U(); Ri(); Fi();
    }
}

void Cube::topEdges() {
    if (front[0] != front[1] && right[0] != right[1] && back[0] != back[1] && left[0] != left[1]) {
        R(); Ui(); R(); U(); R(); U(); R(); Ui(); Ri(); Ui(); R(); R();
    }

    int k = 0;
    int i = 0;
    while (front[0] != front[1] || right[0] != right[1] || back[0] != back[1] || left[0] != left[1]) {
        k++;
        if (k == MAX) {
            solution = "*";
            return;
        }

        i = 0;
        while (back[0] != back[1]) {
            i++;
            if (i == MAX) {
                solution = "*";
                return;
            }

            U();
        }
        if (front[1] == left[0]) {
            R(); R(); U(); R(); U(); Ri(); Ui(); Ri(); Ui(); Ri(); U(); Ri();
        }
        else {
            R(); Ui(); R(); U(); R(); U(); R(); Ui(); Ri(); Ui(); R(); R();
        }
    }

    i = 0;
    while (front[1] != front[4]) {
        i++;
        if (i == MAX) {
            solution = "*";
            return;
        }

        U();
    }
}
