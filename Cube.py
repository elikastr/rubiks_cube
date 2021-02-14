import numpy as np


def colorize(arr):
    colors = {'0': 'r',
              '1': 'b',
              '2': 'w',
              '3': 'g',
              '4': 'o',
              '5': 'y'}

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

    def F(self):
        self.cube['f'] = np.rot90(self.cube['f'], 3)

        self.cube['r'] = np.swapaxes(self.cube['r'], 0, 1)
        self.cube['l'] = np.swapaxes(self.cube['l'], 0, 1)

        temp = np.array(self.cube['u'][2])
        self.cube['u'][2] = self.cube['l'][2]
        self.cube['l'][2] = self.cube['d'][0]
        self.cube['d'][0] = self.cube['r'][0]
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

