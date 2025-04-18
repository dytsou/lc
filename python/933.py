class RecentCounter:
    v = []
    curr = 0
    def __init__(self):
        self.v = []
        self.curr = 0
        
    def ping(self, t: int) -> int:
        self.v.append(t)
        while self.v[self.curr] < t - 3000:
            self.curr += 1
        return len(self.v) - self.curr