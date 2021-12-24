# https://open.kattis.com/problems/settlers2


class GeneralSolution:
    class Position:
        def __init__(self,Point_x,Point_y):
            self.Point_x = Point_x
            self.Point_y = Point_y

        def __eq__(self,other):
            return self.Point_x == other.Point_x and self.Point_y == other.Point_y
        
        def __ne__(self,other):
            return not(self == other)

        def __hash__(self):
            return hash((self.Point_x,self.Point_y))

        def __add__(self,other):
            Point_x, Point_y = other
            return GeneralSolution.Position(self.Point_x + Point_x, self.Point_y + Point_y)

        def __str__(self):
            return f'({self.Point_x},{self.Point_y})'

    class ClasseCatan:
        walks = [(-1,1),(-1,-1),(0,-2),(1,-1),(1,1),(0,2)]
        neighbors = [(1,1),(0,2),(-1,1),(-1,-1),(0,-2),(1,-1)]        

        def __init__(self):
            self.current = GeneralSolution.Position(1,1)
            self.next_walk = 0
            self.value_of_point = {GeneralSolution.Position(0,0): 1, GeneralSolution.Position(1,1): 2}
            self.resources = [1,2]
            self.resources_count = [1,1,0,0,0]

        def get_nth_value(self, n):
            if n > len(self.resources):
                self.__extend_board(n)
            return self.resources[n-1]
        
        def __extend_board(self, n):
            while len(self.resources) < n:
                self.current = self.current + GeneralSolution.ClasseCatan.walks[self.next_walk]
                resource = self.__find_next_resource(self.current)

                self.value_of_point[self.current] = resource
                self.resources.append(resource)
                self.resources_count[resource-1] += 1

                next_walk_in_line = (self.next_walk + 1) % len(GeneralSolution.ClasseCatan.walks)
                if self.current + GeneralSolution.ClasseCatan.walks[next_walk_in_line] not in self.value_of_point:
                    self.next_walk = next_walk_in_line

        def __find_next_resource(self, pos):
            available_resources = {(self.resources_count[i-1],i) for i in range(1,6)}
            for neighbor in GeneralSolution.ClasseCatan.neighbors:
                n_pos = pos + neighbor
                if n_pos in self.value_of_point:
                    n_val = self.value_of_point[n_pos]
                    available_resources.discard((self.resources_count[n_val-1], n_val))
            return sorted(available_resources)[0][1]

    def main():
        ClasseCatan = GeneralSolution.ClasseCatan()
        for _ in range(int(input())):
            print(ClasseCatan.get_nth_value(int(input())))

def main():
    GeneralSolution.main()

main()