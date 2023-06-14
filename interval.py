class Interval:
    def __init__(self, left, right, label):
        self.index = None
        self.left = left
        self.right = right
        self.color = None
        self.adj = None
        self.label = label
    
    def __str__(self):
        return "[%s,%d,%d]" % (self.label,self.index, self.color)
    
        # return "index: %d\nleft endpoint: %d\nright endpoint: %d\ncolor: %d\nadjacent: %d\n" % (self.index, self.left, self.right, self.color, self.adj)
    
    def get_index(self):
        return self.index
    
    def get_right(self):
        return self.right
    
    def get_left(self):
        return self.left
    
    def get_color(self):
        return self.color
    
    def get_adj(self):
        return self.adj
    
    def set_index(self, new_index):
        self.index = new_index
    
    def set_color(self, new_color):
        self.color = new_color

    def set_adj(self, new_adj):
        self.adj = new_adj

class Interval2:
    def __init__(self, left1, right1, left2, right2, label):
        self.left1 = left1
        self.right1 = right1
        self.left2 = left2
        self.right2 = right2
        self.color = 0
        self.label = label
    
    def __str__(self):
        # return "[%s,%d,%d]" % (self.label,self.index, self.color)
    
        return "\nlabel: %s\nleft endpoint 1: %4.2f\nright endpoint 1: %4.2f\nleft endpoint 2: %4.2f\nright endpoint 2: %4.2f\ncolor: %d" % (self.label, self.left1, self.right1, self.left2, self.right2, self.color)
    
    def get_right1(self):
        return self.right1
    
    def get_left1(self):
        return self.left1
    
    def get_right2(self):
        return self.right2
    
    def get_left2(self):
        return self.left2
    
    def get_color(self):
        return self.color
    
    def set_color(self, new_color):
        self.color = new_color

    def new_overlap(self, new_int):
        self.color.append(new_int)
