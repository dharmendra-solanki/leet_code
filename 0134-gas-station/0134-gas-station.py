class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_surplus = 0
        current_tank = 0
        start_index = 0

        for i in range(len(gas)):
            net = gas[i] - cost[i]
            total_surplus += net
            current_tank += net

       
            if current_tank < 0:
                start_index = i + 1
                current_tank = 0

        return start_index if total_surplus >= 0 else -1
        