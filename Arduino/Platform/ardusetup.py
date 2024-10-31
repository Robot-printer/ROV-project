# This file is a python mock-up of the function that will be used as a testbench
potVal=0
outVal=0
oldBool=0
potBool=True # up is true, down is false, the switch starts up
while True:
#------ Input processing, not needed on ardu --------------------------------
    while True:
        potVal=int(input("please type a number for the potval between 500 and 1200 "))
        if 500<=potVal<=1200:
            break
#-------- Convert continuous val to bool ------------------------------------
    if potVal<=725:
        potBool=False
    else:
        potBool=True
#------- set output value ---------------------------------------------------
    if potBool==False and oldBool!=potBool:
        
        if outVal==1:
            outVal=0
        else:
            outVal=1
    oldBool=potBool
    print(outVal)
