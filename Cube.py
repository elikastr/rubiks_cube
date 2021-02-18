import numpy as np
import random


def colorize(arr):
    colors = {'0': 'y',
              '1': 'g',
              '2': 'o',
              '3': 'b',
              '4': 'w',
              '5': 'r'}

    arr = str(arr)
    for number, color in colors.items():
        arr = arr.replace(number, color)
    return arr


class Cube:
    def __init__(self, faces='', solved=False):
        if solved:
            faces = np.array([np.full((3, 3), 0), np.full((3, 3), 1), np.full((3, 3), 2),
                              np.full((3, 3), 3), np.full((3, 3), 4), np.full((3, 3), 5)])
        else:
            faces = np.array(list(faces), dtype=int).reshape((6, 3, 3))

        self.cube = {'u': faces[0],
                     'l': faces[1],
                     'f': faces[2],
                     'r': faces[3],
                     'd': faces[4],
                     'b': faces[5]}

        self.solution = ''
        
    def print(self):
        print("Up: ")
        print(colorize(self.cube['u']))
        print("\nLeft: ")
        print(colorize(self.cube['l']))
        print("\nFront: ")
        print(colorize(self.cube['f']))
        print("\nRight: ")
        print(colorize(self.cube['r']))
        print("\nDown: ")
        print(colorize(self.cube['d']))
        print("\nBack: ")
        print(colorize(self.cube['b']) + '\n')

    def solve(self):
        if self.solution != '':
            print(self.solution)
            return

        self.bottom_cross()
        self.bottom_corners()
        self.middle_edges()
        self.top_cross()

        moves = ['U', 'L', 'F', 'R', 'D', 'B']
        for move in moves:
            self.solution = self.solution.replace(move + ' ' + move + ' ' + move + ' ', move + 'i ')
            self.solution = self.solution.replace(move + ' ' + move + 'i ', '')
            self.solution = self.solution.replace(move + 'i ' + move + ' ', '')
        print(self.solution)

    def scramble(self, string):
        string = string.split(" ")

        for rotation in string:
            if rotation == 'F':
                self.F()
            elif rotation == 'Fi':
                self.Fi()
            elif rotation == 'B':
                self.B()
            elif rotation == 'Bi':
                self.Bi()
            elif rotation == 'R':
                self.R()
            elif rotation == 'Ri':
                self.Ri()
            elif rotation == 'L':
                self.L()
            elif rotation == 'Li':
                self.Li()
            elif rotation == 'U':
                self.U()
            elif rotation == 'Ui':
                self.Ui()
            elif rotation == 'D':
                self.D()
            elif rotation == 'Di':
                self.Di()

    def shuffle(self, k):
        moves = ['F ', 'B ', 'R ', 'L ', 'U ', 'D ']

        scramble_list = random.choices(moves, k=k)

        scramble = ''
        for move in scramble_list:
            scramble += move

        print(scramble)
        self.scramble(scramble)

    def F(self):
        self.cube['f'] = np.rot90(self.cube['f'], 3)

        self.cube['r'] = np.swapaxes(self.cube['r'], 0, 1)
        self.cube['l'] = np.swapaxes(self.cube['l'], 0, 1)

        temp = np.array(self.cube['u'][2])
        self.cube['u'][2] = np.flip(self.cube['l'][2])
        self.cube['l'][2] = self.cube['d'][0]
        self.cube['d'][0] = np.flip(self.cube['r'][0])
        self.cube['r'][0] = temp

        self.cube['r'] = np.swapaxes(self.cube['r'], 0, 1)
        self.cube['l'] = np.swapaxes(self.cube['l'], 0, 1)

    def Fi(self):
        self.F()
        self.F()
        self.F()

    def B(self):
        self.cube['b'] = np.rot90(self.cube['b'], 3)

        self.cube['r'] = np.swapaxes(self.cube['r'], 0, 1)
        self.cube['l'] = np.swapaxes(self.cube['l'], 0, 1)

        temp = np.array(self.cube['u'][0])
        self.cube['u'][0] = self.cube['r'][2]
        self.cube['r'][2] = np.flip(self.cube['d'][2])
        self.cube['d'][2] = self.cube['l'][0]
        self.cube['l'][0] = np.flip(temp)

        self.cube['r'] = np.swapaxes(self.cube['r'], 0, 1)
        self.cube['l'] = np.swapaxes(self.cube['l'], 0, 1)

    def Bi(self):
        self.B()
        self.B()
        self.B()

    def R(self):
        self.cube['r'] = np.rot90(self.cube['r'], 3)

        self.cube['u'] = np.swapaxes(self.cube['u'], 0, 1)
        self.cube['d'] = np.swapaxes(self.cube['d'], 0, 1)
        self.cube['f'] = np.swapaxes(self.cube['f'], 0, 1)
        self.cube['b'] = np.swapaxes(self.cube['b'], 0, 1)

        temp = np.array(self.cube['u'][2])
        self.cube['u'][2] = self.cube['f'][2]
        self.cube['f'][2] = self.cube['d'][2]
        self.cube['d'][2] = self.cube['b'][2]
        self.cube['b'][2] = temp

        self.cube['u'] = np.swapaxes(self.cube['u'], 0, 1)
        self.cube['d'] = np.swapaxes(self.cube['d'], 0, 1)
        self.cube['f'] = np.swapaxes(self.cube['f'], 0, 1)
        self.cube['b'] = np.swapaxes(self.cube['b'], 0, 1)

    def Ri(self):
        self.R()
        self.R()
        self.R()

    def L(self):
        self.cube['l'] = np.rot90(self.cube['l'], 3)

        self.cube['u'] = np.swapaxes(self.cube['u'], 0, 1)
        self.cube['d'] = np.swapaxes(self.cube['d'], 0, 1)
        self.cube['f'] = np.swapaxes(self.cube['f'], 0, 1)
        self.cube['b'] = np.swapaxes(self.cube['b'], 0, 1)

        temp = np.array(self.cube['u'][0])
        self.cube['u'][0] = self.cube['b'][0]
        self.cube['b'][0] = self.cube['d'][0]
        self.cube['d'][0] = self.cube['f'][0]
        self.cube['f'][0] = temp

        self.cube['u'] = np.swapaxes(self.cube['u'], 0, 1)
        self.cube['d'] = np.swapaxes(self.cube['d'], 0, 1)
        self.cube['f'] = np.swapaxes(self.cube['f'], 0, 1)
        self.cube['b'] = np.swapaxes(self.cube['b'], 0, 1)

    def Li(self):
        self.L()
        self.L()
        self.L()

    def U(self):
        self.cube['u'] = np.rot90(self.cube['u'], 3)

        temp = np.array(self.cube['b'][2])
        self.cube['b'][2] = np.flip(self.cube['l'][0])
        self.cube['l'][0] = self.cube['f'][0]
        self.cube['f'][0] = self.cube['r'][0]
        self.cube['r'][0] = np.flip(temp)

    def Ui(self):
        self.U()
        self.U()
        self.U()

    def D(self):
        self.cube['d'] = np.rot90(self.cube['d'], 3)

        temp = np.array(self.cube['f'][2])
        self.cube['f'][2] = self.cube['l'][2]
        self.cube['l'][2] = np.flip(self.cube['b'][0])
        self.cube['b'][0] = np.flip(self.cube['r'][2])
        self.cube['r'][2] = temp

    def Di(self):
        self.D()
        self.D()
        self.D()

    def bottom_cross(self):
        color = self.cube['d'][1, 1]
        free_spaces = [0, 1, 2, 3]

        if self.cube['u'][0, 1] == color:
            free_spaces.remove(0)
        if self.cube['u'][1, 2] == color:
            free_spaces.remove(1)
        if self.cube['u'][2, 1] == color:
            free_spaces.remove(2)
        if self.cube['u'][1, 0] == color:
            free_spaces.remove(3)

        while free_spaces:
            move = ''
            if self.cube['f'][0, 1] == color:
                move = 'F Ui R U '
                free_spaces.remove(2)
            elif self.cube['r'][0, 1] == color:
                move = 'Ri U Fi Ui '
                free_spaces.remove(1)
            elif self.cube['l'][0, 1] == color:
                move = 'L Ui F U '
                free_spaces.remove(3)
            elif self.cube['b'][2, 1] == color:
                move = 'B Ui L U '
                free_spaces.remove(0)

            elif self.cube['d'][0, 1] == color:
                if 2 in free_spaces:
                    move = 'F F '
                    free_spaces.remove(2)
                elif 0 in free_spaces:
                    move = 'U U F F U U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U F F Ui '
                    free_spaces.remove(1)
                else:
                    move = 'Ui F F U '
                    free_spaces.remove(3)
            elif self.cube['d'][1, 2] == color:
                if 1 in free_spaces:
                    move = 'R R '
                    free_spaces.remove(1)
                elif 0 in free_spaces:
                    move = 'U R R Ui '
                    free_spaces.remove(0)
                elif 2 in free_spaces:
                    move = 'Ui R R U '
                    free_spaces.remove(2)
                else:
                    move = 'U U R R U U '
                    free_spaces.remove(3)
            elif self.cube['d'][2, 1] == color:
                if 0 in free_spaces:
                    move = 'B B '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'Ui B B U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U U B B U U '
                    free_spaces.remove(2)
                else:
                    move = 'U B B Ui '
                    free_spaces.remove(3)
            elif self.cube['d'][1, 0] == color:
                if 3 in free_spaces:
                    move = 'L L '
                    free_spaces.remove(3)
                elif 0 in free_spaces:
                    move = 'Ui L L U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U U L L U U '
                    free_spaces.remove(1)
                else:
                    move = 'U L L Ui '
                    free_spaces.remove(2)

            elif self.cube['f'][1, 2] == color:
                if 1 in free_spaces:
                    move = 'R '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'Ui R U '
                    free_spaces.remove(2)
                elif 3 in free_spaces:
                    move = 'U U R U U '
                    free_spaces.remove(3)
                else:
                    move = 'U R Ui '
                    free_spaces.remove(0)
            elif self.cube['f'][1, 0] == color:
                if 0 in free_spaces:
                    move = 'Ui Li '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U U Li U U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U Li Ui '
                    free_spaces.remove(2)
                else:
                    move = 'Li '
                    free_spaces.remove(3)

            elif self.cube['r'][1, 0] == color:
                if 0 in free_spaces:
                    move = 'U U Fi U U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U Fi Ui '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'Fi '
                    free_spaces.remove(2)
                else:
                    move = 'Ui Fi U '
                    free_spaces.remove(3)
            elif self.cube['r'][1, 2] == color:
                if 0 in free_spaces:
                    move = 'B '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'Ui B U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U U B U U '
                    free_spaces.remove(2)
                else:
                    move = 'U B Ui '
                    free_spaces.remove(3)

            elif self.cube['l'][1, 0] == color:
                if 0 in free_spaces:
                    move = 'Bi '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'Ui Bi U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U U Bi U U '
                    free_spaces.remove(2)
                else:
                    move = 'U Bi Ui '
                    free_spaces.remove(3)
            elif self.cube['l'][1, 2] == color:
                if 0 in free_spaces:
                    move = 'U U F U U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U F Ui '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'F '
                    free_spaces.remove(2)
                else:
                    move = 'Ui F U '
                    free_spaces.remove(3)

            elif self.cube['b'][1, 0] == color:
                if 0 in free_spaces:
                    move = 'Ui L U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U U L U U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U L Ui '
                    free_spaces.remove(2)
                else:
                    move = 'L '
                    free_spaces.remove(3)
            elif self.cube['b'][1, 2] == color:
                if 0 in free_spaces:
                    move = 'U Ri Ui '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'Ri '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'Ui Ri U '
                    free_spaces.remove(2)
                else:
                    move = 'U U Ri U U '
                    free_spaces.remove(3)

            elif self.cube['f'][2, 1] == color:
                if 0 in free_spaces:
                    move = 'U U F U Li U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U F U Li U U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'F U Li Ui '
                    free_spaces.remove(2)
                else:
                    move = 'Ui F U Li '
                    free_spaces.remove(3)
            elif self.cube['r'][2, 1] == color:
                if 0 in free_spaces:
                    move = 'U R U Fi U U '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'R U Fi Ui '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'Ui R U Fi '
                    free_spaces.remove(2)
                else:
                    move = 'U U R U Fi U '
                    free_spaces.remove(3)
            elif self.cube['l'][2, 1] == color:
                if 0 in free_spaces:
                    move = 'Ui L U Bi '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'U U L U Bi U '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U L U Bi U U '
                    free_spaces.remove(2)
                else:
                    move = 'L U Bi Ui '
                    free_spaces.remove(3)
            elif self.cube['b'][0, 1] == color:
                if 0 in free_spaces:
                    move = 'B U Ri Ui '
                    free_spaces.remove(0)
                elif 1 in free_spaces:
                    move = 'Ui B U Ri '
                    free_spaces.remove(1)
                elif 2 in free_spaces:
                    move = 'U U B U Ri U '
                    free_spaces.remove(2)
                else:
                    move = 'U B U Ri U U '
                    free_spaces.remove(3)

            if move:
                self.solution += move
                self.scramble(move)

        while self.cube['f'][0, 1] != self.cube['f'][1, 1] or self.cube['u'][2, 1] != color:
            self.solution += 'U '
            self.U()
        self.solution += 'F F '
        self.scramble('F F')

        while self.cube['r'][0, 1] != self.cube['r'][1, 1] or self.cube['u'][1, 2] != color:
            self.solution += 'U '
            self.U()
        self.solution += 'R R '
        self.scramble('R R')

        while self.cube['l'][0, 1] != self.cube['l'][1, 1] or self.cube['u'][1, 0] != color:
            self.solution += 'U '
            self.U()
        self.solution += 'L L '
        self.scramble('L L')

        while self.cube['b'][2, 1] != self.cube['b'][1, 1] or self.cube['u'][0, 1] != color:
            self.solution += 'U '
            self.U()
        self.solution += 'B B '
        self.scramble('B B')

    def bottom_corners(self):
        color = self.cube['d'][1, 1]
        free_corners = [0, 1, 2, 3]

        if self.cube['u'][0, 0] == color or self.cube['l'][0, 0] == color or self.cube['b'][2, 0] == color:
            free_corners.remove(0)
        if self.cube['u'][0, 2] == color or self.cube['r'][0, 2] == color or self.cube['b'][2, 2] == color:
            free_corners.remove(1)
        if self.cube['u'][2, 2] == color or self.cube['r'][0, 0] == color or self.cube['f'][0, 2] == color:
            free_corners.remove(2)
        if self.cube['u'][0, 0] == color or self.cube['l'][0, 0] == color or self.cube['b'][2, 0] == color:
            free_corners.remove(3)

        while free_corners:
            while self.cube['d'][0, 2] != color and self.cube['f'][2, 2] != color and self.cube['r'][2, 0] != color:
                self.solution += 'D '
                self.D()

            if 2 in free_corners:
                move = 'R U Ri Ui '
                free_corners.remove(2)
            elif 1 in free_corners:
                move = 'U R U Ri U U '
                free_corners.remove(1)
            elif 3 in free_corners:
                move = 'Ui R U Ri '
                free_corners.remove(3)
            else:
                move = 'U U R U Ri U '
                free_corners.remove(0)

            if move:
                self.solution += move
                self.scramble(move)

        move = 'R U Ri Ui '
        for _ in range(4):
            colors = [self.cube['u'][2, 2], self.cube['f'][0, 2], self.cube['r'][0, 0]]
            while color not in colors:
                self.solution += 'U '
                self.U()
                colors = [self.cube['u'][2, 2], self.cube['f'][0, 2], self.cube['r'][0, 0]]

            while self.cube['f'][2, 1] not in colors or self.cube['r'][2, 1] not in colors:
                self.solution += 'D '
                self.D()

            while self.cube['d'][0, 2] != color or \
                    self.cube['f'][2, 2] != self.cube['f'][2, 1] or self.cube['r'][2, 0] != self.cube['r'][2, 1]:
                self.solution += move
                self.scramble(move)

        while self.cube['f'][2, 1] != self.cube['f'][1, 1]:
            self.solution += 'D '
            self.D()

    def middle_edges(self):
        color = self.cube['u'][1, 1]
        free_edges = [0, 1, 2, 3]

        if self.cube['u'][0, 1] != color and self.cube['b'][2, 1] != color:
            free_edges.remove(0)
        if self.cube['u'][1, 2] != color and self.cube['r'][0, 1] != color:
            free_edges.remove(1)
        if self.cube['u'][2, 1] != color and self.cube['f'][0, 1] != color:
            free_edges.remove(2)
        if self.cube['u'][1, 0] != color and self.cube['l'][0, 1] != color:
            free_edges.remove(3)

        while free_edges:
            move = ''
            if self.cube['f'][1, 2] != color and self.cube['r'][1, 0] != color:
                if 0 in free_edges:
                    move = 'Fi U F U R Ui Ri U '
                    free_edges.remove(0)
                elif 1 in free_edges:
                    move = 'Ui Fi U F U R Ui Ri U U '
                    free_edges.remove(1)
                elif 2 in free_edges:
                    move = 'U U Fi U F U R Ui Ri Ui '
                    free_edges.remove(2)
                else:
                    move = 'U Fi U F U R Ui Ri '
                    free_edges.remove(3)
            elif self.cube['r'][1, 2] != color and self.cube['b'][1, 2] != color:
                if 0 in free_edges:
                    move = 'Ui Ri U R U B Ui Bi U U '
                    free_edges.remove(0)
                elif 1 in free_edges:
                    move = 'U U Ri U R U B Ui Bi Ui '
                    free_edges.remove(1)
                elif 2 in free_edges:
                    move = 'U Ri U R U B Ui Bi '
                    free_edges.remove(2)
                else:
                    move = 'Ri U R U B Ui Bi U '
                    free_edges.remove(3)
            elif self.cube['l'][1, 0] != color and self.cube['b'][1, 0] != color:
                if 0 in free_edges:
                    move = 'U U Bi U B U L Ui Li Ui '
                    free_edges.remove(0)
                elif 1 in free_edges:
                    move = 'U Bi U B U L Ui Li '
                    free_edges.remove(1)
                elif 2 in free_edges:
                    move = 'Bi U B U L Ui Li U '
                    free_edges.remove(2)
                else:
                    move = 'Ui Bi U B U L Ui Li U U '
                    free_edges.remove(3)
            elif self.cube['l'][1, 2] != color and self.cube['f'][1, 0] != color:
                if 0 in free_edges:
                    move = 'U Li U L U F Ui Fi '
                    free_edges.remove(0)
                elif 1 in free_edges:
                    move = 'Li U L U F Ui Fi U '
                    free_edges.remove(1)
                elif 2 in free_edges:
                    move = 'Ui Li U L U F Ui Fi U U '
                    free_edges.remove(2)
                else:
                    move = 'U U Li U L U F Ui Fi Ui '
                    free_edges.remove(3)

            if move:
                self.solution += move
                self.scramble(move)

        for _ in range(4):
            while self.cube['u'][2, 1] == color or self.cube['f'][0, 1] == color:
                self.solution += 'U '
                self.U()

            up = self.cube['u'][2, 1]
            front = self.cube['f'][0, 1]

            move = ''
            if front == self.cube['f'][1, 1]:
                if up == self.cube['r'][1, 1]:
                    move = 'U R Ui Ri Ui Fi U F '
                elif up == self.cube['l'][1, 1]:
                    move = 'Ui Li U L U F Ui Fi '

            elif front == self.cube['r'][1, 1]:
                if up == self.cube['b'][1, 1]:
                    move = 'B Ui Bi Ui Ri U R '
                elif up == self.cube['f'][1, 1]:
                    move = 'U U Fi U F U R Ui Ri '

            elif front == self.cube['l'][1, 1]:
                if up == self.cube['f'][1, 1]:
                    move = 'U U F Ui Fi Ui Li U L '
                elif up == self.cube['b'][1, 1]:
                    move = 'Bi U B U L Ui Li '

            elif front == self.cube['b'][1, 1]:
                if up == self.cube['l'][1, 1]:
                    move = 'Ui L Ui Li Ui Bi U B '
                elif up == self.cube['r'][1, 1]:
                    move = 'U Ri U R U B Ui Bi '

            if move:
                self.solution += move
                self.scramble(move)

    def top_cross(self):
        color = self.cube['u'][1, 1]
        edges = []

        while edges != [0, 1, 2, 3]:
            if 0 in edges and 1 in edges:
                move = 'Ui '
            elif 2 in edges and 3 in edges:
                move = 'U '
            elif 1 in edges and 2 in edges:
                move = 'U U '
            else:
                move = ''

            move += 'F U R Ui Ri Fi '

            self.solution += move
            self.scramble(move)

            edges = []
            if self.cube['u'][0, 1] == color:
                edges.append(0)
            if self.cube['u'][1, 2] == color:
                edges.append(1)
            if self.cube['u'][2, 1] == color:
                edges.append(2)
            if self.cube['u'][1, 0] == color:
                edges.append(3)
