 #  qt   
from PyQt4.QtCore import *    
from PyQt4.QtGui  import *
import sys


Gui_app= QApplication(sys.argv)    # create application
main_gui= QWidget()    # main window


main_gui.setWindowIcon(QIcon('img/robotic2.jpg'))    #  set icon

main_gui.setWindowTitle("Robot Emulator")     #  set title



'''
pic=QPixmap("img/robot1").scaled(350,250)
pic_lable=QLabel(main_gui)
pic_lable.move(350,100)
pic_lable.resize(pic.width(),pic.height())
pic_lable.setPixmap(pic)
'''



#the robot picture
def robot_pic(h,w):
    pic2 = QPixmap("img/robotf").scaled(h,w)
    pic2_lable = QLabel(main_gui)
    pic2_lable.move(350, 100)
    pic2_lable.resize(pic2.width(), pic2.height())
    pic2_lable.setPixmap(pic2)



robot_pic(300,300)


# the background set 
bc=QPalette()
#bc.setColor(main_gui.backgroundRole(),Qt.blue)  # set background color
#bc.setBrush(main_gui.backgroundRole(),QBrush(QPixmap("img/dna")))
main_gui.setPalette(bc)






 #  set  window size 
main_gui.resize(1200,700)   # set size
main_gui.move(500,200)    # set postion
#main_gui.setGeometry(0,0,1200,700)






#set   choose label 

chooise_label=QLabel(main_gui)  #  for lable 
chooise_label.setText("<h1> Choose The Enviroment </h1> ")
chooise_label.move(750,20)        #  set postion







#radio boxes

water_radio=QRadioButton(main_gui,text="Water")
water_radio.move(750,90)

sand_radio=QRadioButton(main_gui,text="Sand")
sand_radio.move(1000,90)



dark_radio=QRadioButton(main_gui,text="Dark")
dark_radio.move(750,140)

mountain_radio=QRadioButton(main_gui,text="Mountain")
mountain_radio.move(1000,140)



light_radio=QRadioButton(main_gui,text="Light")
light_radio.move(750,190)

obstacles_radio=QRadioButton(main_gui,text="Obstacles")
obstacles_radio.move(1000,190)





rocks_radio=QRadioButton(main_gui,text="Rocks")
rocks_radio.move(750,240)

rubble_radio=QRadioButton(main_gui,text="Rubble")
rubble_radio.move(1000,240)





wind_radio=QRadioButton(main_gui,text="Wind")
wind_radio.move(750,290)

waterfalls_radio=QRadioButton(main_gui,text="Waterfalls")
waterfalls_radio.move(1000,290)




rain_radio=QRadioButton(main_gui,text="Rain")
rain_radio.move(750,340)

collapses_radio=QRadioButton(main_gui,text="Collapses")
collapses_radio.move(1000,340)





glass_radio=QRadioButton(main_gui,text="Glass")
glass_radio.move(750,390)

temperature_radio=QRadioButton(main_gui,text="Temperature")
temperature_radio.move(1000,390)



fire_radio=QRadioButton(main_gui,text="Fire")
fire_radio.move(750,440)

forest_radio=QRadioButton(main_gui,text="Forest")
forest_radio.move(1000,440)









# set   result label 

reslut_label=QLabel(main_gui)  #  for lable 
reslut_label.setText("<h1><b> The robot  Characteristics  <b></h1> ")
reslut_label.move(10,20)        #  set postion


height_label=QLabel(main_gui)  #  for lable
height_label.setText("<h3>  Height <h3> ")
height_label.move(20,100)        #  set postion

height_result = QLineEdit(main_gui)
height_result.move(150,90)
height_result.resize(120,40)
#height_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 



width_label=QLabel(main_gui)  #  for lable
width_label.setText("<h3>Width<h3> ")
width_label.move(20,170)        #  set postion

width_result = QLineEdit(main_gui)
width_result.move(150,160)
width_result.resize(120,40)
#width_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 



speed_label=QLabel(main_gui)  #  for lable
speed_label.setText("<h3> Speed <h3> ")
speed_label.move(20,240)        #  set postion

speed_result = QLineEdit(main_gui)
speed_result.move(150,230)
speed_result.resize(120,40)
#speed_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 




weight_label=QLabel(main_gui)  #  for lable
weight_label.setText("<h3>  Weight <h3> ")
weight_label.move(20,310)        #  set postion

weight_result = QLineEdit(main_gui)
weight_result.move(150,300)
weight_result.resize(120,40)
#weight_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 





material_label=QLabel(main_gui)  #  for lable
material_label.setText("<h3>  Material <h3> ")
material_label.move(20,380)        #  set postion

material_result= QLineEdit(main_gui)
material_result.move(150,370)
material_result.resize(120,40)
#material_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 






wheelnum_label=QLabel(main_gui)  #  for lable
wheelnum_label.setText("<h3>  wheelnum  <h3> ")
wheelnum_label.move(20,450)        #  set postion

wheelnum_result= QLineEdit(main_gui)
wheelnum_result.move(150,440)
wheelnum_result.resize(120,40)
#wheelnum_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text 






legnum_label=QLabel(main_gui)  #  for lable
legnum_label.setText("<h3>  legnum <h3> ")
legnum_label.move(20,520)        #  set postion

legnum_result = QLineEdit(main_gui)
legnum_result.move(150,510)
legnum_result.resize(120,40)
#legnum_result.setPlaceholderText("result here")
#text.setText("hi")     # inital text




cost_lable=QLabel(main_gui , text=" <h3> The Cost<h3>")
cost_lable.move(20,590)

cost_result=QLineEdit(main_gui)
cost_result.move(150,580)
cost_result.resize(120,40)






time_label=QLabel(main_gui)  #  for lable
time_label.setText("<h4>  ETA <h4> ")
time_label.move(510,555)        #  set postion

time_result = QLineEdit(main_gui)
time_result.move(450,580)
time_result.resize(150,40)






gennum_label=QLabel(main_gui)  #  for lable
gennum_label.setText("<h4>    No. of Generations  <h4> ")
gennum_label.move(460,460)        #  set postion


gennum_result = QLineEdit(main_gui)
gennum_result.move(450,485)
gennum_result.resize(150,40)



#############################################################button 


                       #  create   button 
startbtn=QPushButton("Start",main_gui)
startbtn.setGeometry(700,550,100,50)
startbtn.setToolTip("click to run")

drawbtn=QPushButton("Draw",main_gui)
drawbtn.setGeometry(900,550,100,50)
drawbtn.setToolTip("click to draw")

                      #  create  exit  button 
exitBtn=QPushButton("Exit ",main_gui)
exitBtn.setGeometry(1100,550,100,50)
exitBtn.clicked.connect(exit)
exitBtn.setToolTip("click to exit")

###############show  window 

#main_gui.show()
#Gui_app.exec_()
