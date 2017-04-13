import random


class Mutation:

    def __init__(self, chromosome):
        self.chromosome = chromosome        # list will contain 4 element from crossover
        self.final_chromosome = chromosome  # create list to that contain the list from crossover
                                            # and after mutation  will contain 8 elements

    def mutation(self):

        for i in range(0, 4):
            temp_list = list(self.chromosome[i])  # convert string to list

            mutate_bit = random.randint(0, len(self.chromosome[i]) - 1)  # generate random num

            if temp_list[mutate_bit] == "1":
                temp_list[mutate_bit] = "0"

            elif temp_list[mutate_bit] == "0":
                temp_list[mutate_bit] = "1"

            self.final_chromosome.append("".join(temp_list))  # convert list to string and add to final_chromosome

    def get_chromosomes(self):
        return self.final_chromosome
