import sys 

# 사냥꾼
# 사대의 위치(x) 들에서 총의 사정거리 만큼(사각형임 원 아님)
# 범위 내의 동물(a,b)을 잡을 수 있다고 한다
# 사대 동물간 거리 계산 식 : abs(x-a) + b

# 음... 아예 '동물' 입장에서 생각해보는건???
# 결국 사대 입장에서라면 '여러' 동물을 노릴 수 있기에 서로 겹칠 가능성 고려
# 반대로 동물 이라면 모든 포대의 사정거리에 존재하는지를 알면 됨

# 이진탐색???
# 음... 모든 포대를 '검사'하게 되면, 시간 낭비라 생각??
# 동물 위치(x)에서 가장 가까운 포대를 정하고
# 해당 포대에서 잡을수 있는지 확인하면 됨

# 동물 위치에서 잡혀??
def isCaughtAnimal(animalX : int,animalY : int,ShootPlaceX : int,range : int)->bool:
    return abs(ShootPlaceX - animalX) + animalY <= range

def DistanceToAniFromSh(animalX : int,animalY : int,ShootPlaceX : int)->int:
    return abs(ShootPlaceX - animalX) + animalY

def checkShootPlace(start,end,animalX,animalY,shootPlaceArr,range,count):
    if start > end:
        return
    
    mid = (start + end) // 2

    if isCaughtAnimal(animalX,animalY,shootPlaceArr[mid],range):
        count[0] += 1
        return
    
    if(0 < mid < len(shootPlaceArr) - 1):    
        disOne = DistanceToAniFromSh(animalX,animalY,shootPlaceArr[mid + 1])
        disTwo = DistanceToAniFromSh(animalX,animalY,shootPlaceArr[mid - 1])
        if disOne > disTwo:
            checkShootPlace(start,mid-1,animalX,animalY,shootPlaceArr,range,count)
        else:
            checkShootPlace(mid+1,end,animalX,animalY,shootPlaceArr,range,count)

def shootCount(gunXArea,animalPos,gunRange)->int:
    sum = [0]
    for i in range(len(animalPos)):
        checkShootPlace(0,len(gunXArea)-1,animalPos[i][0],animalPos[i][1],gunXArea,gunRange,sum)

    return sum[0]


if __name__ == "__main__":
    shootPlaceCount,animalCount,gunRange = sys.stdin.readline().split()
    shootPlaceCount = int(shootPlaceCount)
    animalCount = int(animalCount)
    gunRange = int(gunRange)
    gunXArea = list(map(int, sys.stdin.readline().split()))
    gunXArea.sort()
    # 2중 배열
    animalPos = [list(map(int,sys.stdin.readline().split())) for _ in range(animalCount)]

    print(shootCount(gunXArea,animalPos,gunRange))

