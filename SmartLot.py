# Program Name: Smart Parking Lot Attendant

# Sample python3 program that returns the next available spot in a Parking Lot 
# Suppose the Next available spot always start at position 1
# Assuming a list of ordered integers representing occupied spots
# next_available_spot() returns the next available spot
# it_is_a_lot() checks if position pos of User it is a lot to Park in
# Program rather tells the user how to parks efficiently

def next_available_spot(myList):
    if(myList == []):
        return 1
    else:
        myList.sort()
        for i in range(len(myList)):
            if myList[i] != i + 1:
                return i + 1
        return len(myList) + 1
            
def it_is_a_lot(next_spot, pos):
    if next_spot != pos:
        print(pos, "is a Spot that is already occupied")
        print("Park at lot " + str(next_spot) + " instead. Thanks!!")
    else:
        print("Yeahhhy you can park at", pos)
        
        
# Test Cases
it_is_a_lot(next_available_spot([]), 1)
it_is_a_lot(next_available_spot([2,1]), 3)
it_is_a_lot(next_available_spot([2,1,3]), 2)
it_is_a_lot(next_available_spot([2,3,1,4,5]), 6)
    
    

            
        
        
        
