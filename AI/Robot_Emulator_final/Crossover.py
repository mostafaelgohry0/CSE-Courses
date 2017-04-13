import random
import copy


class Crossover:

    def __init__(self, chromosomes, crossover_rate):             # two chromosomes to generate two children
        self.parent1 = chromosomes[0]
        self.parent2 = chromosomes[1]
        self.crossover_rate = crossover_rate
        self.crossed = []

    def crossover(self):

        # if random.random() <= self.crossover_rate:
        if self.crossover_rate <= 1:
            cross_point = random.randint(1, len(self.parent1) - 1)
            child1 = self.parent1[:cross_point] + self.parent2[cross_point:]    # [:x]-> from the beginning of array to x
            child2 = self.parent2[:cross_point] + self.parent1[cross_point:]    # [x:]-> from x to the end

        else:
            child1 = copy.deepcopy(self.parent1)                                # or shallow // copy.copy
            child2 = copy.deepcopy(self.parent2)                                # make copy of parent

        self.crossed = [self.parent1, self.parent2, child1, child2]

    def get_crossed(self):
        return self.crossed
