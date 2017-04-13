import Data
import textwrap
from Initial import Initial
from Fitness import Fitness
from Crossover import Crossover
from Mutation import Mutation



class Algorithm:

    def __init__(self, no_of_chromosomes):
        # The variable for the no_of_chromosomes number for the algorithm to run
        self.no_of_chromosomes = no_of_chromosomes 
        # This list will hold the initial generated chromosomes
        self.initials_list = []
        # This list will hold the cost for each initially created chromosome
        self.initials_cost = []
        self.generation_cost = []
        # This list will hold each chromosome and its fitness
        self.fitness_list = [[0]*2 for i in range(0, self.no_of_chromosomes)]
        # This list will hold the most fittest two chromosome
        self.fittest_list = []
        # This list will hold the chromosome sorted according to their fitness
        self.fitness_sorted = []
        # This list will hold the tokens for the fittest chromosome
        self.fittest_tokens_list = []
        # This list will hold the chromosomes after the crossover
        self.crossed_chromosomes = []
        # This list will hold the chromosomes after the mutation
        self.mutated_chromosomes = []
        # This variable is used in the process of calculating the chromosome cost
        self.cost = 0
        # This list will hold the cost of the new chromosomes after mutation
        self.mutated_chromosomes_cost = []


    # Initials generation
    def create_initials(self):
        for i in range(0, self.no_of_chromosomes):
            # Creating object from Initial class
            initial = Initial()
            # Generating an initial chromosome
            initial.create_chromosome()
            # Add the generated chromosome to the initial chromosomes list
            self.initials_list.append(initial.get_chromosome())
            # Add the generated chromosome cost to the initials chromosomes cost list
            self.initials_cost.append(initial.get_cost())

        self.generation_cost = self.initials_cost

    # This function is used to get the initial chromosomes list outside the class
    def get_initials(self):
        return self.initials_list



    # Fitness function
    def calculate_fitness(self, chromosomes_list, condition):
        for i in range(0, self.no_of_chromosomes):
            # Creating object from Fitness class
            fitness = Fitness(chromosomes_list[i], condition)
            # Calculating the fitness of each chromosome
            fitness.calculate_fitness()
            # Adding each chromosome and its fitness to the fitness list
            self.fitness_list[i][0] = chromosomes_list[i]
            self.fitness_list[i][1] = fitness.get_fitness()

        # Sorting the chromosomes according to their fitness
        self.fitness_sorted = sorted(self.fitness_list, key=lambda x: x[1], reverse=True)

        # Creating a list of the most two fittest chromosome
        self.fittest_list = [self.fitness_sorted[0][0], self.fitness_sorted[1][0]]



    # Get the tokens of the best chromosome
    def fittest_tokens_fun(self):
        if self.fitness_sorted[0][1] == 6:
            tokens = textwrap.wrap(self.fitness_sorted[0][0], 2)

            for i in range(0, len(Data.height)):
                if tokens[0] == Data.height[i][1]:
                    self.fittest_tokens_list.append(Data.height[i][0])

            for i in range(0, len(Data.width)):
                if tokens[1] == Data.width[i][1]:
                    self.fittest_tokens_list.append(Data.width[i][0])

            for i in range(0, len(Data.speed)):
                if tokens[2] == Data.speed[i][1]:
                    self.fittest_tokens_list.append(Data.speed[i][0])

            for i in range(0, len(Data.material)):
                if tokens[3] == Data.material[i][1]:
                    self.fittest_tokens_list.append(Data.material[i][0])

            for i in range(0, len(Data.weight)):
                if tokens[4] == Data.weight[i][1]:
                    self.fittest_tokens_list.append(Data.weight[i][0])

            if tokens[6] == "0":
                for i in range(0, len(Data.legnum)):
                    if tokens[5] == Data.legnum[i][1]:
                        self.fittest_tokens_list.append(Data.legnum[i][0])

                        # to check  that there is legnum
                        self.fittest_tokens_list.append("0")
            elif tokens[6] == "1":
                for i in range(0, len(Data.wheelnum)):
                    if tokens[5] == Data.wheelnum[i][1]:
                        self.fittest_tokens_list.append(Data.wheelnum[i][0])

                        # to check  that there is wheelnum
                        self.fittest_tokens_list.append("1")


    def get_fittest_tokens(self):
        return self.fittest_tokens_list

    # Crossover
    def do_crossover(self):
        crossover = Crossover(self.fittest_list, 1)
        crossover.crossover()
        self.crossed_chromosomes = crossover.get_crossed()

    # Mutation
    def do_mutation(self):
        mutation = Mutation(self.crossed_chromosomes)
        mutation.mutation()
        self.mutated_chromosomes = mutation.get_chromosomes()

        # Calculating the cost of each mutated chromosome
        self.mutated_chromosomes_cost = []
        for c in range(0, len(self.mutated_chromosomes)):
            tokens = textwrap.wrap(self.mutated_chromosomes[c], 2)

            self.cost = 0
            for i in range(0, len(Data.height)):
                if tokens[0] == Data.height[i][1]:
                    self.cost += Data.height[i][2]

            for i in range(0, len(Data.width)):
                if tokens[1] == Data.width[i][1]:
                    self.cost += Data.width[i][2]

            for i in range(0, len(Data.speed)):
                if tokens[2] == Data.speed[i][1]:
                    self.cost += Data.speed[i][2]

            for i in range(0, len(Data.material)):
                if tokens[3] == Data.material[i][1]:
                    self.cost += Data.material[i][2]

            for i in range(0, len(Data.weight)):
                if tokens[4] == Data.weight[i][1]:
                    self.cost += Data.weight[i][2]

            if tokens[6] == "0":
                for i in range(0, len(Data.legnum)):
                    if tokens[5] == Data.legnum[i][1]:
                        self.cost += Data.legnum[i][2]
            elif tokens[6] == "1":
                for i in range(0, len(Data.wheelnum)):
                    if tokens[5] == Data.wheelnum[i][1]:
                        self.cost += Data.wheelnum[i][2]

            self.mutated_chromosomes_cost.append(self.cost)

        self.generation_cost = self.mutated_chromosomes_cost

    def get_mutated(self):
        return self.mutated_chromosomes

    def get_generation_cost(self):
        return self.generation_cost



    def the_most_fittest_chromosome(self):
        return self.fitness_sorted[0][1]
