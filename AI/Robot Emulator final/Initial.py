import Data
import random


class Initial:

    def __init__(self):
        self.chromosome = ""
        self.cost = 0

    def set_height(self):
        h = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.height[h][1]
        self.cost += Data.height[h][2]

    def set_width(self):
        w = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.width[w][1]
        self.cost += Data.width[w][2]

    def set_speed(self):
        s = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.speed[s][1]
        self.cost += Data.speed[s][2]

    def set_weight(self):
        g = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.weight[g][1]
        self.cost += Data.weight[g][2]

    def set_material(self):
        m = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.material[m][1]
        self.cost += Data.material[m][2]

    def set_wheelsnum(self):
        s = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.wheelnum[s][1]
        self.cost += Data.wheelnum[s][2]

    def set_legsnum(self):
        l = random.randint(0, 3)
        self.chromosome = self.chromosome + Data.legnum[l][1]
        self.cost += Data.legnum[l][2]

    def set_limbs(self):
        r = random.randint(0, 1024)
        if r % 2 == 0:
            self.set_legsnum()
            self.chromosome += "0"
        else:
            self.set_wheelsnum()
            self.chromosome += "1"

    def create_chromosome(self):
        self.set_height()
        self.set_width()
        self.set_speed()
        self.set_material()
        self.set_weight()
        self.set_limbs()

    def get_chromosome(self):
        return self.chromosome

    def get_cost(self):
        return self.cost