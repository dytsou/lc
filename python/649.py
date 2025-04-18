class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        r_queue, d_queue = [], []
        for i, s in enumerate(senate):
            if s == 'R':
                r_queue.append(i)
            else:
                d_queue.append(i)
        while r_queue and d_queue:
            if r_queue[0] < d_queue[0]:
                r_queue.append(r_queue[0] + n)
            else:
                d_queue.append(d_queue[0] + n)
            r_queue.pop(0)
            d_queue.pop(0)
        return 'Radiant' if r_queue else 'Dire'