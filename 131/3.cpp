class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        color = {}
        dis_color = set()
        res = []
        for x,y in queries:
            if x in color:
                old = color[x]
                if old != y:
                    color[x] = y
                    if old not in color.values():
                        dis_color.discard(old)
                    dis_color.add(y)
            else:
                color[x] = y
                dis_color.add(y)
            res.append(len(dis_color))
        return res