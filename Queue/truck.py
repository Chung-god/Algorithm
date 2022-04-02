def solution(bridge_length, weight, truck_weights):
    answer = 0
    wait_truck = [[0,l] for l in truck_weights] #트럭 위치와 트럭 무게
    answerNum = len(wait_truck)
    bridge = [] #다리
    arrive_truck = [] #도착한 트럭
    while True:
        answer = answer + 1
        #다리에 있는 트럭 전진
        if bridge:
            for i in range(0,len(bridge)):
                truck = bridge[i]
                truck[0] = truck[0] + 1
            if bridge[0][0] > bridge_length:
                arrive_truck.append(bridge.pop(0))
        #삽질한 부분, len(bridge)를 해놓고 안에서 pop을 해버리면 for문 범위가 이상해진다. pop은 따로 뺄것
        
        if len(bridge) < bridge_length: #다리가 다 안 찼으면
            if wait_truck: #대기 중인 트력이 있을 경우
                truck = wait_truck[0]
                bridge_weight = 0 #다리를 지나고 있는 트럭의 무게
                for i in bridge:
                    bridge_weight += i[1]
                if bridge_weight + truck[1] <= weight: #다리에 트럭 무게를 견딜 수 있으면
                    wait_truck.pop(0)
                    truck[0] = truck[0] + 1
                    bridge.append(truck)
        if len(arrive_truck) == answerNum: 
            return answer
