from  Gui import *
from Conditions import *
from Algorithm import Algorithm
import time

import matplotlib.pyplot as plt

# choose the condition  function 

def condition():

    if(water_radio.isChecked()):
        return Water()
    
    elif(sand_radio.isChecked()):
        return Sand()

    elif(dark_radio.isChecked()):
        return Dark()

    elif(mountain_radio.isChecked()):
        return Mountain()

    elif(light_radio.isChecked()):
        return Light()

    elif(obstacles_radio.isChecked()):
        return Obstacles()

    elif(rocks_radio.isChecked()):
        return Rocks()

    elif(rubble_radio.isChecked()):
        return Rubble()

    elif(wind_radio.isChecked()):
        return Wind()

    elif(waterfalls_radio.isChecked()):
        return Waterfalls()

    elif(rain_radio.isChecked()):
        return Rain()

    elif(collapses_radio.isChecked()):
        return Collapses()

    elif(glass_radio.isChecked()):
        return Glass()

    elif(temperature_radio.isChecked()):
        return Temperature()

    elif(fire_radio.isChecked()):
        return Fire()

    elif(forest_radio.isChecked()):
        return Forest()

    elif(trafficsigns_radio.isChecked()):
        return TrafficSigns()



def print_characteristics (l):

    height_result.setText("         "+l[0]+ " cm")
    width_result.setText("         "+l[1]+" cm")
    speed_result.setText("         "+l[2]+ " m/s")
    material_result.setText("      "+l[3])
    weight_result.setText("          "+l[4]+" kg")

    if (l[6]=="0"):
        legnum_result.setText("          "+l[5])
        wheelnum_result.setText("          -")

    elif (l[6]=="1"):
        wheelnum_result.setText("          "+l[5])
        legnum_result.setText("          -")


    print l




def calculate_cost(l):
    
    cost=0
    
    for i in range(0,len(Data.height)):
        if(l[0]==Data.height[i][0]):
            cost+=Data.height[i][2]


    for i in range(0,len(Data.width)):
        if(l[1]==Data.width[i][0]):
            cost+=Data.width[i][2]


    for i in range(0,len(Data.speed)):
        if(l[2]==Data.speed[i][0]):
            cost+=Data.speed[i][2]

    for i in range(0,len(Data.material)):
        if(l[3]==Data.material[i][0]):
            cost+=Data.material[i][2]

    for i in range(0,len(Data.weight)):
        if(l[4]==Data.weight[i][0]):
            cost+=Data.weight[i][2]


    if(l[6]=="0"):

        for i in range(0, len(Data.legnum)):
            if (l[5] == Data.legnum[i][0]):
                cost += Data.legnum[i][2]

    if (l[6] == "1"):

        for i in range(0, len(Data.wheelnum)):
            if (l[5] == Data.wheelnum[i][0]):
                cost += Data.wheelnum[i][2]



    return cost



def draw(lx,y):

    x=[]

    for i in range (1,lx+1):
        x.append(i)


    plt.title(" robot emulator ")
    plt.xlabel(" generations")
    plt.ylabel("max fittest (%)")
    plt.axis([1,9,0,110])

    # plt.ion()
    plt.plot(x, y)
    #plt.show()


def draw_show():
    plt.show()




