class Interval:
    def __init__(self, left, right):
        self.index = None
        self.left = left
        self.right = right
        self.color = None
        self.adj = None
    
    def __str__(self):
        return "[%d,%d]" % (self.index, self.color)
    
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