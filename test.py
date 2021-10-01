class parent:
    var = 100

class a(parent):
    var = 99


class b (parent):
    def fun():
        print("fun")
        pass


class c(a, b):
    def print_val(self):

        print("VAlue of a : ", a.var)
        print("VAlue of b : ", b.var)


obj = c()
obj.print_val()
