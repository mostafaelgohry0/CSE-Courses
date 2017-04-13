import textwrap


class Fitness:

    def __init__(self, chromosome, condition):
        self.chromosome_fitness = 0
        self.chromosome = chromosome
        self.condition = condition
        self.tokens = textwrap.wrap(self.chromosome, 2)

    def compare_height(self):

        allowed_height = self.condition.get_height()

        for i in range(0, len(allowed_height)):
            if self.tokens[0] == allowed_height[i]:
                self.chromosome_fitness += 1
                break

    def compare_width(self):

        allowed_width = self.condition.get_width()

        for i in range(0, len(allowed_width)):
            if self.tokens[1] == allowed_width[i]:
                self.chromosome_fitness += 1
                break

    def compare_speed(self):

        allowed_speed = self.condition.get_speed()

        for i in range(0, len(allowed_speed)):
            if self.tokens[2] == allowed_speed[i]:
                self.chromosome_fitness += 1
                break

    def compare_material(self):

        allowed_material = self.condition.get_material()

        for i in range(0, len(allowed_material)):
            if self.tokens[3] == allowed_material[i]:
                self.chromosome_fitness += 1
                break

    def compare_weight(self):

        allowed_weight = self.condition.get_weight()

        for i in range(0, len(allowed_weight)):
            if self.tokens[4] == allowed_weight[i]:
                self.chromosome_fitness += 1
                break

    def compare_limbs(self):

        if self.tokens[6] == "0":
            allowed_legs = self.condition.get_legnum()
            for i in range(0, len(allowed_legs)):
                if self.tokens[5] == allowed_legs[i]:
                    self.chromosome_fitness += 1
                    break

        elif self.tokens[6] == "1":
            allowed_wheels = self.condition.get_wheelnum()
            for i in range(0, len(allowed_wheels)):
                if self.tokens[5] == allowed_wheels[i]:
                    self.chromosome_fitness += 1
                    break

    def calculate_fitness(self):
        self.compare_height()
        self.compare_width()
        self.compare_speed()
        self.compare_material()
        self.compare_weight()
        self.compare_limbs()

    def get_fitness(self):
        return self.chromosome_fitness
