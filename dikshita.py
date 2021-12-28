from itertools import combinations

class Test:
    def __init__(self, list):
        self.list = list

    def function(self, order):

        i = order[0]
        j = order[1]

        return (abs(self.list[i - 1] - self.list[j - 1]) + abs(i - j))

    def result(self):
        print(list(range(1, len(self.list) + 1)))
        
        combinations([])

        comb = combinations(list(range(1, len(self.list) + 1)), 2)

        temp = []

        for i in comb:
            print(i)
            temp.append(self.function(i))

        return max(temp)


a = [1, 3, -1]
obj = Test(a)
print("Max of all: ", obj.result())


# total_cases = int(input())
# for i in range(total_cases):
#     case_inputs = input()
#     case = Test(*map(int, case_inputs.split()))

#     print(f'Case #{i+1}: ', case.result())
