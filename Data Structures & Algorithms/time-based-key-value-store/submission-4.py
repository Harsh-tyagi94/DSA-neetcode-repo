class Node:
    def __init__(self, value: str, timestamp: int):
        self.val = value
        self.time_st = timestamp
        self.next = None


class TimeMap:
    def __init__(self):
        self.mp = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        curr = Node(value,timestamp)
        if key not in self.mp:
            self.mp[key] = curr
            return
        
        head = self.mp[key]
        curr.next = head
        self.mp[key] = curr

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp:
            return ""
        
        head = self.mp[key]
        while head is not None and head.time_st > timestamp:
            head = head.next
        
        return "" if head is None else head.val

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)